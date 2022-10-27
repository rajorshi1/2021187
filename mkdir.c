#include<stdio.h>
#include<string.h>
#include <sys/stat.h>
#include<dirent.h>
#include <unistd.h>

char cwd[1000];

int stringCompare(char one[], char two[]) {
    return strcmp(one, two);
}
void callChdir(char* add){
    int x=chdir(add);
    if(x==-1){
        printf("Error in changing directory to %s\n",add);
    }
    else{
        strcpy(cwd,add);
    }
    getcwd(cwd,sizeof(cwd));
}
void concatenator(char *var, char *temp) {
    strcat(temp,"/");
    strcat(temp,var);
}
char* advanceV(char* var) {
    if(stringCompare(var,"mkdir")==0){
        var=strtok(NULL," ");
        if(stringCompare(var,"-v")==0){
            var=strtok(NULL," ");
        }
    }
    return var;

}
char* make_directory(char* var){
    struct  stat s={0};
    char temp[1000];
    getcwd(temp,sizeof(temp));
    concatenator(var, temp);
    printf("%s\n",temp );
    int x=mkdir(temp, 0777);
    if(x==-1){
        printf("%s Directory can't be created, already exists\n",var);
    }
    else{
        printf("%s Directory created\n",var);
    }
    var=strtok(NULL," ");
    return var;
}
char* mcD(char *var) {
    char temp[1000];
    getcwd(temp,sizeof(temp));
    concatenator(var, temp);
    int x=mkdir(temp, 0777);
    if(x==-1){
        printf("Directory already exits\n");
    }
    else{
        var=strtok(NULL," ");
    }
    return var;
}

int main(int argc, char const* arg[]){
    char* token=(char*)arg[0];
    getcwd(cwd,sizeof(cwd));
    char args[105];
    strcpy(args,arg[1]);
    if (token!=NULL) {
        if(!stringCompare(token,"-v")) {
            char* var=strtok(args," ");
            var = advanceV(var);
            getcwd(cwd,sizeof(cwd));
            while (var!=NULL){
                var = make_directory(var);
            }
        }
        else if (!stringCompare(token, "--help")) {
            printf(" -m, --mode=MODE\n"
                   "              set file mode (as in chmod), not a=rwx - umask\n"
                   "\n"
                   "       -p, --parents\n"
                   "              no error if existing, make parent directories as needed\n"
                   "\n"
                   "       -v, --verbose\n"
                   "              print a message for each created directory\n"
                   "\n"
                   "       -Z     set SELinux security context of each created directory to\n"
                   "              the default type\n"
                   "\n"
                   "       --context[=CTX]\n"
                   "              like -Z, or if CTX is specified then set the SELinux or\n"
                   "              SMACK security context to CTX\n"
                   "\n"
                   "       --help display this help and exit\n"
                   "\n"
                   "       --version\n"
                   "              output version information and exit");
        }
        else{
            char* var=strtok(args," ");
            if(!stringCompare(var,"mkdir")){
                var=strtok(NULL," ");
            }
            getcwd(cwd,sizeof(cwd));
            while(var!=NULL){
                var = mcD(var);
            }
        }
    }
    else {
        printf("Argument missing, Try again");
    }
    return 0;
}
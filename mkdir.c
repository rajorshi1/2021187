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

int main(int argc, char const* arg[]){
    char* token=(char*)arg[0];
    getcwd(cwd,sizeof(cwd));
    char args[105];
    strcpy(args,arg[1]);
    if (token!=NULL) {
        if(stringCompare(token,"-v")==0) {
            char* vari=strtok(args," ");
            if(stringCompare(vari,"mkdir")==0){
                vari=strtok(NULL," ");
                if(stringCompare(vari,"-v")==0){
                    vari=strtok(NULL," ");
                }
            }
            getcwd(cwd,sizeof(cwd));
            while(vari!=NULL){
                struct  stat s={0};
                char temp[1000];
                getcwd(temp,sizeof(temp));
                strcat(temp,"/");
                strcat(temp,vari);
                printf("%s\n",temp );
                int x=mkdir(temp, 0777);
                if(x==-1){
                    printf("%s Directory can't be created, already exists\n",vari);
                    vari=strtok(NULL," ");
                }
                else{
                    printf("%s Directory created\n",vari);
                    vari=strtok(NULL," ");
                }
            }
        }
        else{
            char* vari=strtok(args," ");
            if(stringCompare(vari,"mkdir")==0){
                vari=strtok(NULL," ");
            }
            getcwd(cwd,sizeof(cwd));
            while(vari!=NULL){
                char temp[1000];
                getcwd(temp,sizeof(temp));
                strcat(temp,"/");
                strcat(temp,vari);
                int x=mkdir(temp, 0777);
                if(x==-1){
                    printf("Directory already exits\n");
                }
                else{
                    vari=strtok(NULL," ");
                }
            }
        }
    }
    else {
        printf("Argument missing, Try again");
    }
    return 0;
}
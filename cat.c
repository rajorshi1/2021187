#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

char cwd[1000];

int stringCompare(char one[], char two[]) {
    return strcmp(one, two);
}
int checkStatus(struct stat st) {
    return stat(cwd,&st);
}
char* advanceE(char *var) {
    if(stringCompare(var,"cat")==0){
        var=strtok(NULL," ");
        if(stringCompare(var,"-E")==0){
            var=strtok(NULL," ");
        }
    }
    return var;
}
char* advanceN(char *var) {
    if(!stringCompare(var,"cat")) {
        var = strtok(NULL, " ");
        if (!stringCompare(var, "-n")) {
            var = strtok(NULL, " ");
        }
    }
    return var;
}
void printFile(FILE *file) {
    char output[150];
    while(fgets(output,sizeof(output),file)!=NULL){
        strcat(output,"$");
        fputs(output,stdout);
    }
}
void printLines(FILE *file, int line) {
    char output[150];
    while((fgets(output,sizeof(output),file))!=NULL){
        printf("%d ",line);
        line+=1;
        fputs(output,stdout);
    }
}

int main(int argc, char const* arg[]){
    char* token=(char*)(arg[0]);
    char str[105];
    strcpy(str,arg[1]);
    if(!stringCompare(token,"-E")){
        struct stat st={0};
        char* var=strtok(str," ");
        var = advanceE(var);
        getcwd(cwd,sizeof(cwd));
        strcat(cwd,"/");
        strcat(cwd,var);
        if(checkStatus(st)==-1) {
            printf("File does not exist\n");
        }
        else {
            FILE *file=fopen(cwd,"r");
            if(file!=NULL){
                printFile(file);
            }
            else {
                printf("Error in opening file\n");
            }
        }
    }
    else if(!stringCompare(token,"-n")){
        char* var=strtok(str," ");
        var = advanceN(var);
        struct stat st={0};
        int line=1;
        getcwd(cwd,sizeof(cwd));
        strcat(cwd,"/");
        strcat(cwd,var);
        if(checkStatus(st)==-1){
            printf("File does not exist\n");
        }
        else {
            FILE *file=fopen(cwd,"r");
            printf("%s\n",cwd);
            if(file!=NULL){
                printLines(file, line);
            }
            else {
                printf("Error in opening file\n");
            }
        }
    }
    else{
        printf("Command not supported\n");
    }
}
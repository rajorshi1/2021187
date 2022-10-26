#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
char cwd[1000];

int stringCompare(char one[], char two[]) {
    return strcmp(one, two);
}

int main(int argc, char const* arg[]){
    char* token=(char*)(arg[0]);
    char str[105];
    strcpy(str,arg[1]);
    if(!stringCompare(token,"-E")){
        struct stat st={0};
        char* var=strtok(str," ");
        if(stringCompare(var,"cat")==0){
            var=strtok(NULL," ");
            if(stringCompare(var,"-E")==0){
                var=strtok(NULL," ");
            }
        }
        getcwd(cwd,sizeof(cwd));
        strcat(cwd,"/");
        strcat(cwd,var);
        if(stat(cwd,&st)==-1) {
            printf("File does not exist\n");
        }
        FILE *file=fopen(cwd,"r");
        if(file!=NULL){
            char output[150];
            while(fgets(output,sizeof(output),file)!=NULL){
                strcat(output,"$");
                fputs(output,stdout);
            }
        }
        if(file==NULL){
            printf("Error in opening file\n");
        }
    }
    else if(!stringCompare(token,"-n")){
        char* var=strtok(str," ");
        if(!stringCompare(var,"cat")){
            var=strtok(NULL," ");
            if(stringCompare(var,"-n")==0){
                var=strtok(NULL," ");
            }
        }
        struct stat st={0};
        int line=1;
        getcwd(cwd,sizeof(cwd));
        strcat(cwd,"/");
        strcat(cwd,var);
        if(stat(cwd,&st)==-1){
            printf("File does not exist\n");
        }
        FILE *file=fopen(cwd,"r");
        printf("%s\n",cwd);
        if(file!=NULL){
            char output[150];
            while((fgets(output,sizeof(output),file))!=NULL){
                printf("%d ",line);
                line+=1;
                fputs(output,stdout);
            }
        }
        else {
            printf("Error in opening file\n");
        }
    }
    else{
        printf("Command not supported\n");
    }
}
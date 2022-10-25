#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
char cwd[1000];
char prevWorkingDirectory[1000];


int stringCompare(char one[], char two[]) {
    return strcmp(one, two);
}
void callChdir(char* add){
    int x=chdir(add);
    if(x==-1){
        printf("Can't change directory to %s\n",add);
    }
    else{
        strcpy(prevWorkingDirectory,cwd);
        strcpy(cwd,add);
    }
}
void cd(char* argument){
    if(argument==NULL || stringCompare(argument,"-")==0){
        callChdir(prevWorkingDirectory);
    }
    else if(stringCompare("..",argument)==0){
        callChdir("../");
    }
    else if(stringCompare("~",argument)==0){
        callChdir(getenv("HOME"));
    }
    else{
        if(stringCompare("-L",argument)==0 || stringCompare("-P",argument)==0){
            argument=strtok(NULL," ");
            if(argument==NULL){
                callChdir(getenv("HOME"));
            }
            else{
                callChdir(argument);
            }
        }
        else {
            callChdir(argument);
        }
    }
}
void pwd(char* argument){
    if(argument!=NULL){
        if(stringCompare(argument,"-L")==0){
            printf("%s\n",cwd);
        }
        else if(stringCompare(argument,"--help")==0){
            FILE* help=fopen("/home/bhavya/Desktop/os/assign1/My-Shell/pwdhelp.txt","r");
            char out[1000];
            while(fgets(out,sizeof(out),help)!=NULL){
                fputs(out,stdout);
            }
            fclose(help);
        }
        else{
            printf("Command not found \n");
        }
    }
    else{
        printf("%s\n",cwd);
    }
}
void echo(char* token){
    if(token==NULL){
        printf("\n");
    }
    else if(stringCompare(token,"--help")==0){
        printf("Press echo and a and argument after it\n");
    }
    else{
        while(token!=NULL){
            printf("%s ",token);
            token=strtok(NULL," ");
        }
        printf("\n");
    }

}
void exxit(char* token){
    if(token==NULL){
        exit(0);
    }
    else{
        printf("Invalid command \n");
    }
}


int main() {
    printf("Welcome to Igarashi's shell\n");

    while(1){
        char input[100];
        char splits[105]="";
        scanf("%[^\n]%*c",input);
        strcat(splits,input);
        strcat(splits," ");
        char* token;
        token=strtok(input," ");
        if (!stringCompare(token, "cd")) {
            token=strtok(NULL," ");
            cd(token);
        }
        else if (!stringCompare(token, "echo")) {
            token=strtok(NULL," ");
            echo(token);
        }
        else if (!stringCompare(token, "pwd")) {
            token=strtok(NULL," ");
            pwd(token);
        }
        else if(!stringCompare(token,"exit")){
            token=strtok(NULL," ");
            exxit(token);
        }
        else if (!stringCompare(token, "ls")) {
            pid_t pid;
            pid=fork();
            if(pid==0) {
                token=strtok(NULL," ");
                execl("ls.c",token,NULL);
                exit(0);
            }
            else if(pid>0) {
                waitpid(0,NULL,0);
            }
            else {
                printf("Error in forking\n");
            }
        }
        else if (!stringCompare(token, "cat")) {
            pid_t pid;
            pid=fork();
            if(pid==0) {
                token=strtok(NULL," ");
                execl("ls.c",token,splits,NULL);
                exit(0);
            }
            else if(pid>0) {
                waitpid(0,NULL,0);
            }
            else {
                printf("Error in forking\n");
            }
        }
        else if (!stringCompare(token, "date")) {
            pid_t pid;
            pid=fork();
            if(pid==0) {
                token=strtok(NULL," ");
                execl("date.c",token,NULL);
                exit(0);
            }
            else if(pid>0) {
                waitpid(0,NULL,0);
            }
            else {
                printf("Error in forking\n");
            }
        }
        else if (!stringCompare(token, "mkdir")) {
            pid_t pid;
            pid=fork();
            if(pid==0) {
                token=strtok(NULL," ");
                execl("mkdir.c",token,splits,NULL);
                exit(0);
            }
            else if(pid>0) {
                waitpid(0,NULL,0);
            }
            else {
                printf("Error in forking\n");
            }
        }
        else if (!stringCompare(token, "rm")) {
            pid_t pid;
            pid=fork();
            if(pid==0) {
                token=strtok(NULL," ");
                execl("rm.c",token,splits,NULL);
                exit(0);
            }
            else if(pid>0) {
                waitpid(0,NULL,0);
            }
            else {
                printf("Error in forking\n");
            }
        }
        else{
            printf("Command not found\n");
            }
    }
}

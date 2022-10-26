#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<stdlib.h>

int stringCompare(char one[], char two[]) {
    return strcmp(one, two);
}

void main(int argc, char const* arg[]){
    char* token=(char*)arg[0];
    if(stringCompare(token,"-a")){
        struct dirent **dir;
        int n=scandir(".",&dir,0,alphasort);
        for (int i=0; i<n; i++){
            char* name;
            name=dir[i]->d_name;
            printf("%s ",name);
            free(dir[i]);
        }
        free(dir);
        printf("\n");

    }
    else if(token==NULL){
        struct dirent **dir;
        int n=scandir(".",&dir,0,alphasort);
        int i=0;
        for (int i=0; i<n; i++) {
            char* name;
            name=dir[i]->d_name;
            if(name[0]!='.'){
                printf("%s ",name);
                free(dir[i]);
            }
        }
        free(dir);
        printf("\n");
    }
    else if(stringCompare(token,"-R")){		
        struct dirent *dir;
        DIR *d=opendir(".");
        if(d!=NULL){
            while(dir!=NULL){
                printf("%s ",dir->d_name);
                dir=readdir(d);
            }
        }
        else{
            printf("Error as type of directory is null\n");
        }
        printf("\n");
        free(dir);
        free(d);
    }
    else{
        printf("Command not supported\n");
    }
}
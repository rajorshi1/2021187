#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<stdlib.h>

int stringCompare(char one[], char two[]) {
    return strcmp(one, two);
}
void printDir(struct dirent **dir) {
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
void printDirdot(struct dirent ** dir) {
    int n = scandir(".",&dir,0,alphasort);
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
void readDir() {
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

void main(int argc, char const* arg[]){
    char* token=(char*)arg[0];
    if(stringCompare(token,"-a")){
        struct dirent **dir;
        printDir(dir);
    }
    else if(token==NULL){
        struct dirent **dir;
        printDirdot(dir);
    }
    else if(stringCompare(token,"-R")){		
        readDir();
    }
    else{
        printf("Command not supported\n");
    }
}
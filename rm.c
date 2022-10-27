#include <stdio.h>
#include <string.h>
#include <unistd.h>

int stringCompare(char one[], char two[]) {
    return strcmp(one, two);
}
char* advanceF(char* file_var) {
    if(stringCompare(file_var,"rm")==0){
        file_var=strtok(NULL," ");
        if(stringCompare(file_var,"-f")==0){
            file_var=strtok(NULL," ");
        }
    }
    return file_var;
}
char* advanceI(char* file_var) {
    if(stringCompare(file_var,"rm")==0){
        file_var=strtok(NULL," ");
        if(stringCompare(file_var,"-i")==0){
            file_var=strtok(NULL," ");
        }
    }
    return file_var;
}

int main(int argc, char const* arg[]){
    char* token=(char*)arg[0];
    char args[105];
    strcpy(args,arg[1]);
    if(token==NULL){
        printf("Operand not found \n");
    }
    else if(stringCompare(token,"-i")==0){
        char* file_var=strtok(args," ");
        file_var = advanceI(file_var);
        while(file_var!=NULL){
            printf("removing file %s \n",file_var);
            unlink(file_var);
            file_var=strtok(NULL," ");
        }
    }
    else if(stringCompare(token,"-f")==0){
        char* file_var=strtok(args," ");
        file_var = advanceF(file_var);
        while(file_var!=NULL){
            unlink(file_var);
            file_var=strtok(NULL," ");
        }
    }
    else{
        char* file_var=strtok(args," ");
        if(!stringCompare(file_var,"rm")) {
            file_var = strtok(NULL," ");
        }
        else {
            while(file_var!=NULL){
                int x=unlink(file_var);
                if(x!=0){
                    printf("File %s does not exist. \n",file_var);
                }
                file_var=strtok(NULL," ");
            }
        }
    }
}
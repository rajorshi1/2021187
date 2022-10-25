#include <stdio.h>
#include <string.h>

int stringCompare(char one[], char two[]) {
    return strcmp(one, two);
}

int main(int argc, char const* arg[]){
    char* token=arg[0];
    char args[105];
    strcpy(args,arg[1]);
    if(token==NULL){
        printf("Operand not found \n");
    }
    else if(stringCompare(token,"-f")==0){
        char* file_var=strtok(args," ");
        if(stringCompare(file_var,"rm")==0){
            file_var=strtok(NULL," ");
            if(stringCompare(file_var,"-f")==0){
                file_var=strtok(NULL," ");
            }
        }
        while(file_var!=NULL){
            unlink(file_var);
            file_var=strtok(NULL," ");
        }
    }
    else if(stringCompare(token,"-i")==0){
        char* file_var=strtok(args," ");
        if(stringCompare(file_var,"rm")==0){
            file_var=strtok(NULL," ");
            if(stringCompare(file_var,"-i")==0){
                file_var=strtok(NULL," ");
            }
        }
        while(file_var!=NULL){
            printf("remove file %s ? Enter 'y' for yes \n",file_var);
            char input;
            scanf("%[^\n]%*c",input);
            if(input=='y'){
                unlink(file_var);
            }
            else{
                return 0;
            }
            file_var=strtok(NULL," ");
        }

    }
    else{
        char* file_var=strtok(args," ");
        if(!stringCompare(file_var,"rm")) {
            file_var = strtok(NULL," ");
        }
        while(file_var!=NULL){
            int x=unlink(file_var);
            if(x!=0){
                printf("File %s does not exist. \n",file_var);
            }
            file_var=strtok(NULL," ");
        }
    }
}
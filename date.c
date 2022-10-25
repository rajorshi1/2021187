#include <stdio.h>
#include <string.h>
#include <time.h>

int stringCompare(char one[], char two[]) {
    return strcmp(one, two);
}

int main(int argc, char const* arg[]){
    char* token=arg[0];
    if(stringCompare(token,"-u")==0){
        time_t t=time(&t);
        struct tm *utc=gmtime(&t);
        if(utc==NULL){
            printf("GMtime function failed \n");
        }
        printf("UTC TIME : %s\n",asctime(utc));
    }
    else if(token==NULL){
        time_t time_var;
        time(&time_var);
        if(time_var==-1){
            printf("Couldn't execute request\n");
        }
        else {
            printf("%s\n", ctime(&time_var));
        }
    }
    else{
        printf("Command not supported\n");
    }
}
#include <stdio.h>
#include <string.h>
#include <time.h>

int stringCompare(char one[], char two[]) {
    return strcmp(one, two);
}

int main(int argc, char const* arg[]){
    char* token=(char*)arg[0];
    if(!stringCompare(token,"-u")){
        time_t t=time(&t);
        struct tm *utc=gmtime(&t);
        if(utc==NULL){
            printf("GMtime function failed \n");
        }
        printf("UTC TIME : %s\n",asctime(utc));
    }
    else if (!stringCompare(token, "--help")) {
        printf("-d, --date=STRING\n"
               "              display time described by STRING, not 'now'\n"
               "\n"
               "       --debug\n"
               "              annotate the parsed date, and warn about questionable\n"
               "              usage to stderr\n"
               "\n"
               "       -f, --file=DATEFILE\n"
               "              like --date; once for each line of DATEFILE\n"
               "\n"
               "       -I[FMT], --iso-8601[=FMT]\n"
               "              output date/time in ISO 8601 format.  FMT='date' for date\n"
               "              only (the default), 'hours', 'minutes', 'seconds', or 'ns'\n"
               "              for date and time to the indicated precision.  Example:\n"
               "              2006-08-14T02:34:56-06:00\n"
               "\n"
               "       -R, --rfc-email\n"
               "              output date and time in RFC 5322 format.  Example: Mon, 14\n"
               "              Aug 2006 02:34:56 -0600\n"
               "\n"
               "       --rfc-3339=FMT\n"
               "              output date/time in RFC 3339 format.  FMT='date',\n"
               "              'seconds', or 'ns' for date and time to the indicated\n"
               "              precision.  Example: 2006-08-14 02:34:56-06:00\n"
               "\n"
               "       -r, --reference=FILE\n"
               "              display the last modification time of FILE\n"
               "\n"
               "       -s, --set=STRING\n"
               "              set time described by STRING\n"
               "\n"
               "       -u, --utc, --universal\n"
               "              print or set Coordinated Universal Time (UTC)\n"
               "\n"
               "       --help display this help and exit\n"
               "\n"
               "       --version\n"
               "              output version information and exit");
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
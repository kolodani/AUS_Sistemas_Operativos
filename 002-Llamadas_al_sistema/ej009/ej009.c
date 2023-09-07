#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 64

int main(int argc, char *argv[])
{
    DIR *dd;
    struct dirent* dirp;
    struct stat stats;
    char namebuf[BUFSIZE];
    int name_len;

    if(argc < 2){
        getcwd(namebuf, BUFSIZE-1);
    }
    else{
        strcpy(namebuf, argv[1]);
    }

    name_len = strlen(namebuf);

    if((dd = opendir(namebuf)) == 0){
        perror("Error1");
        _exit(1);
    }
    while(dirp = readdir(dd)){
        namebuf[name_len] = '\0';
        strcat(namebuf,"/");
        strcat(namebuf, dirp->d_name);

        if(stat(namebuf, &stats)){
            perror("Error2");
            exit(2);
        }

        if(S_ISDIR(stats.st_mode)){
            printf("%s\n", namebuf);
        }
    }
    return 0;
}

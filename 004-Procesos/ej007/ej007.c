#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    char comando[1000];
    int *status;

    for (;;)
    {
        printf("$ ");
        fgets(comando, 1000, stdin);

        if (fork())
        {
            wait(status);
        }
        else
        {
            execl(comando, comando, NULL);
        }
    }
    return 0;
}
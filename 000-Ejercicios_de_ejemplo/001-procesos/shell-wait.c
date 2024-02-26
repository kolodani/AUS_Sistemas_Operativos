#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    char comando[1000];
    int *status;

    for (;;)
    {
        printf("$ ");
        gets(comando);

        if (fork())
            wait(status);
        else
            execl(comando, comando, NULL);
    }

    return 0;
}

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    char comando[1000];

    for (;;)
    {
        printf("$ ");
        fgets(comando, 1000, stdin);

        if (fork())
            ;
        else
        {
            execl(comando, comando, NULL);
        }
    }
    return 0;
}
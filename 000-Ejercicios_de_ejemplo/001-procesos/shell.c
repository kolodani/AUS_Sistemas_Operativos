#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char comando[1000];

    for (;;)
    {
        printf("$");
        gets(comando);

        if (fork())
            ;
        else
            execl(comando, comando, NULL);
    }

    return 0;
}

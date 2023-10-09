#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int i;
    int fd1, fd2;
    const char string1[10] = "*********";
    const char string2[10] = "---------";
    pid_t rf;

    fd1 = creat("ficheroA", 0666);
    fd2 = creat("ficheroB", 0666);
    rf = fork();
    switch (rf)
    {
    case -1:
        printf("\nNo he podido crear el proceso hijo");
        break;
    case 0:
        for (i = 0; i < 10; i++)
        {
            sleep(2); // linea agregada por cuestion b)
            write(fd1, string2, sizeof(string2));
            write(fd2, string2, sizeof(string2));
            usleep(1); /* Abandonamos volutariamente el procesador */
        };
        break;
    default:
        for (i = 0; i < 10; i++)
        {
            sleep(1); // linea agregada por cuestion b)
            write(fd1, string1, sizeof(string1));
            write(fd2, string1, sizeof(string1));
            usleep(1); /* Abandonamos volutariamente el procesador */
        };
        break;
    };
    printf("\nFinal de ejecucion de %d \n", getpid());
    exit(0);
}
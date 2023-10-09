#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
    pid_t rf;
    int varfork = 10; // cambio hecho por la consigna h)
    int i = 0;        // cambio hecho por la consigna h)
    rf = fork();
    switch (rf)
    {
    case -1:
        printf("No he podido crear el proceso hijo \n");
        break;
    case 0:
        sleep(1); // cambio hecho por la consigna g)
        printf("Soy el hijo, mi PID es %d y mi PPID es %d \n", getpid(), getppid());
        for (i = 0; i < 10; i++) // cambio hecho por la consigna h)
        {
            varfork++;
        }
        sleep(20);
        break;
    default:
        printf("Soy el padre, mi PID es %d y el PID de mi hijo es %d \n", getpid(), rf);
        for (i = 0; i < 10; i++) // cambio hecho por la consigna h)
        {
            varfork += 10;
        }
        sleep(30);
        break;
    }
    printf("Soy el proceso %d y mi variable varfork es %d \n", getpid(), varfork); // cambio hecho por la consigna h)
    printf("Final de ejecucion de %d \n", getpid());
    exit(0);
}

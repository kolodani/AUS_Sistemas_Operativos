#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
    int i = 0; // cambios pregunta b)
    int j;
    pid_t rf;

    rf = fork();
    switch (rf)
    {
    case -1:
        printf("\nNo he podido crear el proceso hijo");
        break;
    case 0:
        // i = 0;     // cambios pregunta b)
        printf("\nSoy el hijo, mi PID es %d y mi variable i (inicialmente a %d) crece de 1 en 1", getpid(), i);
        for (j = 0; j < 5; j++)
        {
            i++;
            // i ++;    // cambios pregunta b)
            printf("\nSoy el hijo, mi variable i es %d", i);
        };
        break;
    default:
        // i = 1;      // cambios pregunta b)
        printf("\nSoy el padre, mi PID es %d y mi variable i (inicialmente a %d) crece de 2 en 2", getpid(), i);
        for (j = 0; j < 5; j++)
        {
            i += 2; // cambios pregunta b)
            // i++;    // cambios pregunta b)
            printf("\nSoy el padre, mi variable i es %d", i);
        };
    };
    printf("\nFinal de ejecucion de %d \n", getpid());
    exit(0);
}

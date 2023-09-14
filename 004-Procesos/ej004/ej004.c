#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>

int main()
{
    pid_t pid_hijo = fork();
    // fork() crea un proceso hijo, devuelve el pid del hijo al padre y 0 al hijo
    // osea en que cuando se ejecuta la linea se crea un proceso hijo
    // en el proceso hijo pid_hijo = 0 y en el padre pid_hijo = pid del hijo
    int var = 5;

    switch (pid_hijo)
    {
        //en el caso 0 nunca va a entrar el proceso padre porque su pid_hijo siempre es distinto de 0,es el pid del hijo
        //en cambio en el hijo siempre el pid_hijo es 0 porque no tiene hijos
        case 0:  // Proceso hijo
        {
            var = 10;
            printf("Proceso hijo\n");
            printf("Hijo: PID=%d, PPID=%d - Variable=%d\n", getpid(), getppid(), var);
            break;
        }
        case -1:
        {
            printf("errno = %d\n", errno);
            perror("fork");
            break;
        }
        default:  // Proceso padre
        {
            printf("Proceso padre\n");
            printf("Padre: PID=%d, PPID=%d - Variable=%d\n", getpid(), getppid(), var);
            break;
        }
    }
    return 0;
}
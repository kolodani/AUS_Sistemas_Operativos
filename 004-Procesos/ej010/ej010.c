#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid_hijo;
    int* status_hijo;

    pid_hijo = fork();

    if (pid_hijo)
    {
        /* Padre */
        printf("Mi hijo es el proceso %d, espero...", pid_hijo);
        wait(status_hijo);
        /* Determinar el motivo de la terminacion */
        if (WIFEXITED(*status_hijo))
        {
            printf("\nTerminacion normal del proceso hijo con exit code %d.\n", WEXITSTATUS(*status_hijo));
        }
        if (WIFSIGNALED(*status_hijo))
        {
            int signal_id = WTERMSIG(*status_hijo);
            char *signal_name = strsignal(signal_id);
            printf("\nTerminacion debido a la señal %d (%s).\n", signal_id, signal_name);
        }
    }
    else
    {
        /* Hijo */
        int i = 0;
        sleep(5);
        while (i++ < 120)
        {
            fprintf(stdout, "%d - ", i++);
            sleep(1);
        }
        printf("Hijo termina normalmente\n");
        _exit(status_hijo);
    }
    return 0;
}
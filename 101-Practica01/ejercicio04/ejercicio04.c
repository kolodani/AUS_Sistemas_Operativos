/*
 *  Crear un programa que genere dos procesos hijos.
 *  El padre debe esperar por la terminación de ambos procesos hijos antes debe imprimir por pantalla “Proceso padre
 *  esperando...”, y posteriormente imprimirá “Hijo PID_1er_hijo finalizó” e “Hijo PID_2do_hijo finalizó”.
 *  El primer proceso hijo debe realizar un exec imprimiendo en pantalla el calendario del mes y año (formato mm aaaa).
 *  Parámetros establecidos por el padre y recibidos por línea de comandos (el usuario lo introduce).
 *  El segundo hijo deberá recibir una señal SIGUSR1 y mediante un handler emitirá por pantalla el mensaje “Recibida la
 *  señal SIGUSR1” y luego finalizará con _exit().
 *  Finalmente el proceso padre mostrará por pantalla su propio PID y finalizará.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    // variables
    pid_t pid1, pid2;
    int status1, status2;

    // creacion de procesos hijos
    pid1 = fork();

    // proceso hijo 1
    if (pid1 == 0)
    {
        // ejecucion de comando
        execl("/usr/bin/cal", "cal", "10", "2020", NULL);
    }
    // proceso padre
    else
    {
        // creacion de proceso hijo 2
        pid2 = fork();

        // proceso hijo 2
        if (pid2 == 0)
        {
            // espera de señal
            pause();
            // mensaje de señal recibida
            printf("Recibida la señal SIGUSR1\n");
            // finalizacion del proceso
            _exit(0);
        }
        // proceso padre
        else
        {
            // espera de procesos hijos
            waitpid(pid1, &status1, 0);
            printf("Hijo %d finalizó\n", pid1);
            waitpid(pid2, &status2, 0);
            printf("Hijo %d finalizó\n", pid2);
            // mensaje de finalizacion del proceso padre
            printf("Proceso padre finalizó\n");
        }
    }

    return 0;
}
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
#include <signal.h>

#define CHILD_PID 0
#define MES 1
#define ANIO 2

void emosion(int);

int main(int argc, char *argv[])
{
    if (argc != 3)
        return 1;

    pid_t pid_holder;
    char *mes = argv[MES];
    char *anio = argv[ANIO];
    char cal[] = "/usr/bin/cal";
    char *nargv[] = {cal, mes, anio, NULL};

    pid_holder = fork();

    if (pid_holder == CHILD_PID)
    {
        execve(cal, nargv, NULL);
    }
    else
    {
        printf("Esperando ... por mi hijo %d :c\n", pid_holder);
        wait(&pid_holder);
    }
    pid_holder = fork();
    if (pid_holder == CHILD_PID)
    {
        signal(SIGUSR1, emosion);
        pause();
        _exit(0);
    }
    else
    {
        printf("Mandale un SIGUSR1(10) a este %d \n", pid_holder);
        wait(&pid_holder);
    }

    return 0;
}

void emosion(int signal)
{
    printf("Recibida la senial SIGUSR1, la señal es: %d \n", signal);
}

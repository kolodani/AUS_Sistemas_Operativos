#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigproc(int sig)
{
    printf("Ud presiono Ctrl-C\n");
    printf("Recibida la señal numero %d\n", sig);
}

void quitproc(int sig)
{
    printf("Ud presiono Ctrl-\\ \n");
    printf("Recibida la señal numero %d\n", sig);
    exit(0);
}

int main()
{
    signal(SIGINT, sigproc);
    signal(SIGQUIT, quitproc);
    printf("Ctrl-C deshabilitado use Ctrl-\\ para terminar\n");

    for (;;);

    return 0;
}
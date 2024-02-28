/*
 *  Ejercicio 8 : Pipes y popen
 *  (a) Construir un programa en C que emplee popen(ver presentación dada en clases) donde el
 *  padre permita al usuario ingresar un texto de varias líneas por pantalla(nueva linea<Enter>,
 *  para terminar) y el proceso hijo muestre la cantidad de líneas,
 *  palabras y caracteres que contiene(usar comando wc)
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#define READ 0
#define WRITE 1

int main()
{
    int fds[2];
    pid_t pid;

    pipe(fds);
    pid = fork();

    if (pid == (pid_t)0)
    {
        /* Proceso HIJO. Lee desde el pipe */
        close(fds[WRITE]); /* Cierra su extremo de escritura */
        /* leo lo ingrasado por pantalla y muestro la cantidad de lineas, palabras y caracteres que contienen */
        dup2(fds[READ], STDIN_FILENO);
        /* hago un cartel para marcar */
        execlp("wc", "wc", NULL);
    }
    else
    {
        /* Proceso PADRE. Escribe en el pipe */
        FILE *stream;
        close(fds[READ]); /* Cierra su extremo de lectura */
        /* lectura por consola hasta un enter */
        stream = popen("wc", "w");
        char c;
        while ((c = getchar()) != '\n')
        {
            fputc(c, stream);
        }
    }

    return 0;
}
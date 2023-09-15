/*
 *  Ejercicio 08:
 *  El comando pkill en UNIX permite el envío de señales a los procesos discriminándolos por nombre
 *  (man pkill). Crear un programa denominado my_pkill que imite el comportamiento de dicho comando,
 *  pero restringido al envío de señales.
 *  Es decir: my_pkill [-signal] pattern
 *  Si no se especifica señal alguna, enviar SIGTERM.
 *  pattern especifica una expresión regular para comparar con los nombres de los procesos.
 *  my_pkill deberá presentar un mensaje de error en el caso de ser ejecutado por un usuario que,
 *  por ejemplo, trate de terminar un proceso sobre el que no tiene injerencia (uno lanzado por otro
 *  usuario).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <regex.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX 100

int main(int argc, char const *argv[])
{
    // Variables
    char *pattern;
    char *signal;
    int sig;
    regex_t regex;
    DIR *dir;
    struct dirent *ent;
    pid_t pid;

    // Comprobamos que se han introducido los argumentos necesarios
    if (argc < 2)
    {
        printf("Error: Se deben introducir al menos dos argumentos.\n");
        printf("Uso: %s [-signal] pattern\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Comprobamos si se ha introducido una señal
    if (argv[1][0] == '-')
    {
        signal = (char *)malloc(sizeof(char) * strlen(argv[1]));
        strcpy(signal, argv[1]);
        pattern = (char *)malloc(sizeof(char) * strlen(argv[2]));
        strcpy(pattern, argv[2]);
    }
    else
    {
        signal = (char *)malloc(sizeof(char) * 3);
        strcpy(signal, "-9");
        pattern = (char *)malloc(sizeof(char) * strlen(argv[1]));
        strcpy(pattern, argv[1]);
    }

    // Comprobamos si la señal es válida
    if (signal[1] == '0')
    {
        sig = 0;
    }
    else
    {
        sig = atoi(signal + 1);
    }

    // Comprobamos si el patrón es válido
    if (regcomp(&regex, pattern, REG_EXTENDED) != 0)
    {
        printf("Error: El patrón introducido no es válido.\n");
        exit(EXIT_FAILURE);
    }

    // Abrimos el directorio /proc
    dir = opendir("/proc");
    if (dir == NULL)
    {
        printf("Error: No se ha podido abrir el directorio /proc.\n");
        exit(EXIT_FAILURE);
    }

    // Recorremos el directorio /proc
    while ((ent = readdir(dir)) != NULL)
    {
        // Comprobamos si el nombre del directorio coincide con el patrón
        if (regexec(&regex, ent->d_name, 0, NULL, 0) == 0)
        {
            // Comprobamos si el nombre del directorio es un número
            if (atoi(ent->d_name) != 0)
            {
                // Obtenemos el pid del proceso
                pid = atoi(ent->d_name);
                // Comprobamos si el proceso es del usuario actual
                if (getuid() == getpgid(pid))
                {
                    // Enviamos la señal al proceso
                    if (kill(pid, sig) == -1)
                    {
                        printf("Error: No se ha podido enviar la señal al proceso %d.\n", pid);
                    }
                }
                else
                {
                    printf("Error: No se puede enviar la señal al proceso %d.\n", pid);
                }
            }
        }
    }
    return 0;
}


// para ejecutar esto poner en la terminal: ./ejercicio08 -9 firefox
// esto mata el proceso de firefox
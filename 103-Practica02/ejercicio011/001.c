/*
 *  Ejercicio 11 : Pipes
 *  – Crear un proceso que solicite al usuario una operación aritmética sencilla, que involucre solo los operadores
 *  binarios +, -, * y /, y que de la forma : entero operando entero.
 *  – Este proceso entonces creará un proceso hijo, el cual recibirá dicha operación mediante un pipe, la resolverá y
 *  luego enviará al proceso padre el resultado por otro pipe.
 *  – El padre, a continuación, mostrará el resultado de la operación por pantalla.
 *  – Finalmente consultará al usuario si pretende realizar otra operación. En caso afirmativo deberán repetirse los
 *  pasos anteriores.
 *  Utilidades :
 *  – Convertir cadenas a enteros : int atoi(const char *cadena) de<stdlib.h>
 *  – Convertir enteros a cadena : int sprintf(const char *, char *fmt, ...) de<stdio.h>
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define READ 0
#define WRITE 1

// funcion cartel
void cartel()
{
    printf("Ingrese una operacion aritmetica sencilla: ");
    printf("Ejemplo: 2 + 2\n");
    printf("Osea, un entero, un operador y otro entero\n");
    printf("> ");
}


int main(int argc, char const *argv[])
{
    char respuesta = 's';
    int fds[2], fds2[2];
    pid_t pid;
    char operacion[100];
    char operador;
    int a, b, resultado;

    do
    {
        // creo dos pipes
        pipe(fds);
        pipe(fds2);
        pid = fork();

        if (pid == (pid_t)0)
        {
            // Proceso HIJO
            // espera que el padre termine de escribir en el pipe
            wait(NULL);

            // leo la operacion del pipe
            close(fds[WRITE]);
            read(fds[READ], operacion, sizeof(operacion));
            close(fds[READ]);

            // resuelvo la operacion
            // convierto la cadena a enteros

            sscanf(operacion, "%d %c %d", &a, &operador, &b);

            // resuelvo la operacion
            switch (operador)
            {
            case '+':
                resultado = a + b;
                break;
            case '-':
                resultado = a - b;
                break;
            case '*':
                resultado = a * b;
                break;
            case '/':
                resultado = a / b;
                break;
            default:
                resultado = 0;
                break;
            }

            // escribo el resultado en el pipe
            close(fds2[READ]);
            write(fds2[WRITE], &resultado, sizeof(resultado));
            close(fds2[WRITE]);

            // termina el proceso hijo
            exit(0);
        }
        else
        {
            // Proceso PADRE
            cartel();

            // leo la linea ingresada por el usuario
            fgets(operacion, sizeof(operacion), stdin);

            // escribo la operacion en el pipe
            close(fds[READ]);
            write(fds[WRITE], operacion, strlen(operacion) + 1);
            close(fds[WRITE]);

            // espero a que el hijo termine de resolver la operacion
            wait(NULL);

            // leo el resultado del pipe
            close(fds2[WRITE]);
            read(fds2[READ], &resultado, sizeof(resultado));
            close(fds2[READ]);

            // muestro el resultado
            printf("El resultado es: %d\n", resultado);

            // consulta al usuario si pretende realizar otra operacion
            printf("Desea realizar otra operacion? (s/n): ");
            scanf(" %c", &respuesta);
            if (respuesta == 's')
            {
                getchar(); // limpio el buffer
            } else {
                printf("Adios!\n");
            }
        }
    } while (respuesta == 's');
    return 0;
}

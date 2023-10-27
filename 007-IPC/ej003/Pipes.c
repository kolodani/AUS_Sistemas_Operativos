#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#define READ 0
#define WRITE 1

int main(){
    int fds[2];
    pid_t pid;

    pipe(fds);
    pid = fork();

    if(pid == (pid_t) 0){
        /* Proceso HIJO. Lee desde el pipe */
        char buffer[1024];
        FILE* stream;
        close(fds[WRITE]); /* Cierra su copia del extremo de escritura */

        stream = fdopen(fds[READ], "r");
        fgets(buffer, sizeof(buffer), stream);
        fputs(buffer, stdout);
        close(fds[READ]);
    } else {
        /* Proceso PADRE. Escribe en el pipe */
        FILE* stream;
        close(fds[READ]); /* Cierra su extremo de lectura */

        stream = fdopen(fds[WRITE], "w");
        fprintf(stream, "Mensaje del padre para el hijo...\n");
        fflush(stream);
        close(fds[WRITE]);
    }

    return 0;
}
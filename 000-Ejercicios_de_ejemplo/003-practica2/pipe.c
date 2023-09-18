#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define READ  0
#define WRITE 1

int main () {
    int fds[2];
    pid_t pid;

    /* Crea un pipe, los extremos (file descriptors) se almacenan 
	 * en fds */
    pipe(fds);

    /* Crea un proceso hijo. */
    pid = fork();
    
    if (pid == (pid_t) 0) {
        /* Proceso HIJO. Lee desde el pipe. */
        char buffer[1024];
        FILE* stream;
	    /* Cierra su copia del extremo de escritura. */
        close(fds[WRITE]);
		
        /* Convierte el descriptor de lectura en un objeto FILE, y lee
		 * desde el mismo. */
        stream = fdopen(fds[READ], "r");
		
        fgets(buffer, sizeof(buffer), stream);
		fputs(buffer, stdout);
		
        close(fds[READ]);
    } else {
        /* Proceso PADRE. Escribe en el pipe*/
        FILE* stream;
        /* Cierra su extremo de lectura. */
        close(fds[READ]);
		
        /* Convierte el descriptor de escritura en un objeto FILE, y 
		 * escribe en el mismo. */
        stream = fdopen(fds[WRITE], "w");
		
		fprintf(stream, "Mensaje del padre para el hijo...");
		fflush(stream);

        close(fds[WRITE]);
    }

    return 0;
}

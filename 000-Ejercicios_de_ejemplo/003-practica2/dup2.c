//Ejemplo de uso de la llamada al sistema dup2.
//Recurra a las man pages para mas detalles sobre dup2
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define READ  0
#define WRITE 1

int main () {
    int fds[2];
    pid_t pid;
    pipe (fds);

    pid = fork ();

    if (pid == (pid_t) 0) {
        /* Proceso HIJO. Leera desde el pipe. */
	    close (fds[WRITE]);
 	    /* Conecta el extermo de lectura del pipe con la entrada 
		 * estandar (STDIN). */
	    dup2 (fds[READ], STDIN_FILENO);
  	    /* Reemplaza el proceso hijo con el programa "sort". */
 	    execlp ("sort", "sort", 0);
    } else {
	    /* Proceso PADRE. Escribira en el pipe. */
 	    FILE* stream;
	    /* Cierra el extremo de lectura. */
	    close (fds[READ]);

		/* file descriptor --> objeto FILE */
		stream = fdopen (fds[WRITE], "w");
		fprintf (stream, "1 - para todos y todos para uno.\n");
		fprintf (stream, "3 - tristes tigres.\n");
		fprintf (stream, "2 - horas y media.\n");
		fprintf (stream, "5 - mentarios.\n");
		fprintf (stream, "4 - cientos cuarenta y cuatro.\n");
		fflush (stream);
		close (fds[WRITE]);
	
		/* Espera que finalice el proceso hijo. */
		waitpid (pid, NULL, 0);
    }
    
    return 0;
}

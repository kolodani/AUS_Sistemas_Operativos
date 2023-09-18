/* Escritor generico del FIFO */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

int main (int argc, char **argv) {
	int fd, nbytes, nmsg=0;	
	char data[PIPE_BUF];
	pid_t pid = getpid();

	if (argc != 2) {
		perror("Error de uso: ./fifo-writer path\n");	
		exit(1);
	}

	/* Apertura del FIFO */
	if ((fd = open(argv[1], O_WRONLY)) < 0) {
		perror("Error en open");
		exit(2);
	}

	printf("Yo soy el proceso %d\n", pid);

	while (1) { 
		/* Confeccion del mensaje a enviar */	
	    nbytes = sprintf(data, "Mensaje Nº %d del escritor [%d] hacia el FIFO.", nmsg++, pid);

		/* Escritura (envio) del mensaje */
		if (write(fd, data, nbytes+1) < 0) {
			perror("Error en write");
			exit(2);
		}
		sleep(pid%3); 
	}	
		
	close(fd);
	return 0;
}

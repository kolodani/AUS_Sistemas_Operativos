#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

int main (int argc, char **argv) {
	int fd;	
	char buffer[PIPE_BUF];

	if (argc != 2) {
		perror("Error de uso: ./fifo-reader path");	
		exit(1);
	}
	
	if ((fd=open(argv[1], O_RDONLY)) < 0) {
		perror("Error de open");	
		exit(2);
	}

	/* Leer desde el FIFO y mostar datos por pantalla */
	while (read(fd, buffer, PIPE_BUF-1) > 0) 
		printf("-> %s\n", buffer);

	close(fd);
	return 0;
}

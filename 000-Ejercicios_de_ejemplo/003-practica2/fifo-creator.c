#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char **argv) {

	if (argc != 2) {
		printf("Error de uso: ./fifo-creator path\n");	
		exit(1);
	}

	//Crea un fifo con el path suministrado
	if (mkfifo(argv[1], 0666) == -1) {
		printf("Error de mkfifo\n");
		exit(2);
	}

	printf("Se ha creado el FIFO %s, compruebelo con `ls -l`.\n", argv[1]);

	return 0;
}

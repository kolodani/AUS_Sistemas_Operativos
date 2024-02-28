#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

int main(int argc, char const *argv[])
{
    int fd;
    char data[PIPE_BUF];
    mode_t modo = 0666;

    if (argc !=2){
        perror("Error de uso: ./fifo-reader path");
        exit(1);
    }

    if(mkfifo(argv[1], modo) < 0){
        perror("Error en mkfifo");
        exit(2);
    }

    if ((fd = open(argv[1], O_RDONLY)) < 0){
        perror("Error en open");
        exit(3);
    }

    /* Leer desde el FIFO y mostrar datos */
    while (read(fd, data, PIPE_BUF-1) > 0)
        printf("->%s\n", data);

    close(fd);
    return 0;
}

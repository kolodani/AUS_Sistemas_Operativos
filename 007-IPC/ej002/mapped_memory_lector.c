#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#define FILE_LENGTH 0x100

int main(int argc, char const *argv[])
{
    int fd;
    void *file_memory;
    int integer;

    /* Abre el archivo. */
    fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR);

    /* Crea la memoria mapeada. */
    file_memory = mmap(0, FILE_LENGTH, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    /* Lee el entero, lo imprime y lo duplica */
    sscanf((char *)file_memory, "%d", &integer);
    printf("El valor del entero es: %d\n", integer*2);

    /* Libera la memoria */
    munmap(file_memory, FILE_LENGTH);

    return 0;
}

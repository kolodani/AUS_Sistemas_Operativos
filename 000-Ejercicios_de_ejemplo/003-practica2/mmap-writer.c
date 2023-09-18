#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#define FILE_LENGTH 0x100
#define INTEGER 123

int main (int argc, char* const argv[]) {
    int fd;
    void* file_memory;

    /* Prepare a file large enough to hold an unsigned integer. */
    fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    lseek (fd, FILE_LENGTH+1, SEEK_SET);
    write (fd, "", 1);
    lseek (fd, 0, SEEK_SET);
    
    /* Crea el mapeo de memoria. */
    file_memory = mmap(0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);
    close (fd);
   
    /* Escribe un entero al area de memoria mapeada. */
    sprintf((char*)file_memory, "%d\n", INTEGER);
    
    /* Libera la memoria. */
    munmap (file_memory, FILE_LENGTH);
    
    return 0;
}

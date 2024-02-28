/*
 *  Ejercicio 10 : Mapped Memory
 *  Un proceso, denominado productor, crea un archivo con 100 enteros aleatorios incluidos en el rango [1, 1000].
 *  Posteriormente mapeará el contenido del archivo a memoria. Otro proceso denominado sorter, haciendo uso de qsort,
 *  ordenará estos enteros directamente en memoria. Finalmente productor debe mostrar por pantalla el contenido del
 *  archivo ordenado.
 *  Nota : Las tareas de creación y eliminación y mapeo del archivo son responsabilidad de productor.
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

/* tamaño del archivo para 100 enteros*/
#define FILE_LENGTH 100 * sizeof(int)

// funcion para elegir un numero aleatorio entre 1 y 1000
int aleatorio()
{
    return rand() % 1000 + 1;
}

// funcion para comparar dos enteros
int comparar(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(int argc, char const *argv[])
{
    int fd;
    void *file_memory;

    // creo dos procesos, uno para el productor y otro para el sorter
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("Error en el fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // proceso sorter
        // espero a que el proceso productor termine
        wait(NULL);
        // abro el archivo
        fd = open("file.bin", O_RDWR, S_IRUSR | S_IWUSR);
        // mapeo el archivo a memoria
        file_memory = mmap(0, FILE_LENGTH, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        close(fd);

        // ordeno los enteros
        int *enteros = (int *)file_memory;
        qsort(enteros, 100, sizeof(int), comparar);
    }
    else
    {
        // proceso productor
        // creo el archivo
        fd = open("file.bin", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
        // redimensiono el archivo para que tenga el tamaño de 100 enteros
        lseek(fd, FILE_LENGTH + 1, SEEK_SET);
        write(fd, "", 1);
        lseek(fd, 0, SEEK_SET);

        // mapeo el archivo a memoria
        file_memory = mmap(0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);
        close(fd);

        // genero 100 enteros aleatorios y los guardo en el archivo
        int *enteros = (int *)file_memory;
        srand(time(NULL));
        for (int i = 0; i < 100; i++)
        {
            enteros[i] = aleatorio();
        }

        // espero a que el proceso sorter termine
        wait(NULL);

        // muestro el contenido del archivo ordenado
        for (int i = 0; i < 100; i++)
        {
            printf("%d ", enteros[i]);
        }
    }

    return 0;
}

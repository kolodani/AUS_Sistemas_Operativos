#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main()
{
    int ret;
    char *args[] = {"ls", "-l", NULL};
    // *args[] es un array de punteros a char, donde guardo los argumentos
    // ls es el comando a ejecutar, que me muestra el contenido del directorio actual
    // -l es un argumento del comando ls, que me muestra el contenido del directorio actual en formato largo
    // NULL es el puntero que indica el final del array de punteros a char

    ret = execv("/bin/ls", args);
    // execv() ejecuta el comando ls con los argumentos -l en el directorio actual
    // execv() devuelve -1 si falla, y 0 si tiene exito

    if (ret == -1)
    {
        printf("errno = %d\n", errno);
        // errno es una variable global que guarda el codigo de error
        perror("execv");
        // perror() imprime el mensaje de error correspondiente al codigo de error guardado en errno
        return -1;
        // Si falla, termino el programa
    }

    printf("Codigo inalcanzable");
    return 0;
}

// si el ret == -1, el programa termina con error y no se ejecuta el printf("Codigo inalcanzable");, el programa
// termina con el return -1
// si el ret == 0, significa que se ejecuto correctamente y como llama a un proceso, el programa termina y se ejecuta
// la funcion ls -l en el directorio actual
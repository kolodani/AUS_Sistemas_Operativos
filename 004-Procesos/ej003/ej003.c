#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main()
{
    int ret;
    char *args[] = {"sleep", "1000", NULL};
    // *args[] es un array de punteros a char, donde guardo los argumentos
    // sleep es el comando a ejecutar, lo que hace es dormir el proceso durante 1000 segundos
    char *env[] = {"LOGNAME=gdm", "PWD=/opt", NULL};
    // *env[] es un array de punteros a char, donde guardo las variables de entorno
    // LOGNAME es el nombre del usuario que ejecuta el proceso
    // PWD es el directorio actual del proceso

    ret = execve("/bin/sleep", args, env);
    // execve() ejecuta el comando sleep con los argumentos 1000 en el directorio actual
    // execve() devuelve -1 si falla, y 0 si tiene exito

    if (ret == -1)
    {
        printf("errno = %d\n", errno);
        // errno es una variable global que guarda el codigo de error
        perror("execve");
        // perror() imprime el mensaje de error correspondiente al codigo de error guardado en errno
        return -1;
        // Si falla, termino el programa
    }

    printf("Codigo inalcanzable");
    return 0;
}

// si ret == -1, significa que hubo un error y el programa termina con error, no se ejecuta el printf("Codigo
// inalcanzable");. ademas se imprime el mensaje de error correspondiente al codigo de error guardado en errno
// si ter == 0, significa que se ejecuto correctamente y como llama a un proceso, el programa termina y se ejecuta
// la funcion sleep 1000 en el directorio actual
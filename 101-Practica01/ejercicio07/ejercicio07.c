/*
 *  Ejercicio 07:
 *  Crear un comando denominado my_chmod que imite el comportamiento del comando UNIX chmod.
 *  El mismo sirve para cambiar los permisos de acceso a archivos y directorios.
 *  Usar la llamada al sistema chmod y cualquier otra que sea de utilidad.
*/

#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int mode;       // Modo de acceso
    char *path;     // Ruta del archivo o directorio
    int a;          // Resultado de la llamada al sistema

    // si no se pasan los argumentos correctos
    if (argc != 3)
    {
        printf("Uso: %s <modo> <archivo>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // obtener el modo de acceso
    mode = strtol(argv[1], NULL, 8);

    // obtener la ruta del archivo
    path = argv[2];

    // cambiar los permisos de acceso
    a = chmod(path, mode);
    if (a == -1)
    {
        perror("chmod");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
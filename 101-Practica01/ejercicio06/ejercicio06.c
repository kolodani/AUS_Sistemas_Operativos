/*
 *  Ejercicio 06:
 *  Crear un programa llamado my_ls.
 *  For uso será:
 *  my_ls <opción> <directorio>
 *  donde <directorio> es el nombre de un directorio y según la opción que se le pase hará lo siguiente.
 *  <opción>:
 *  -e : liste todos los archivos contenidos en <directorio>
 *  -d : liste sólo los directorios contenidos en <directorio>
 *  -i : liste el número de i-nodo y el nombre de los archivos contenidos en <directorio>.
 *  Notas: Usar las llamadas al sistema: stat y cualquier otra que consideren necesaria.
 *  Además usar las funciones opendir, readdir, closedir.
*/

#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dir;                // Puntero al directorio
    struct dirent *ent;      // Puntero a la entrada del directorio
    struct stat fileStat;    // Estructura para almacenar los datos del archivo
    char *path = argv[2];    // Ruta del directorio

    if (argc != 3)
    {
        printf("Uso: %s <opción> <directorio>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((dir = opendir(path)) == NULL)
    {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    switch (argv[1][1])
    {
        case 'e':
            while ((ent = readdir(dir)) != NULL)
            {
                printf("%s\n", ent->d_name);
            }
            break;
        case 'd':
            while ((ent = readdir(dir)) != NULL)
            {
                if (ent->d_type == DT_DIR)
                {
                    printf("%s\n", ent->d_name);
                }
            }
            break;
        case 'i':
            while ((ent = readdir(dir)) != NULL)
            {
                if (stat(ent->d_name, &fileStat) < 0)
                {
                    perror("stat");
                    exit(EXIT_FAILURE);
                }
                printf("%ld %s\n", fileStat.st_ino, ent->d_name);
            }
            break;
        default:
            printf("Opción no válida\n");
            break;
    }
    return 0;
}

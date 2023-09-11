/*
 *  Ejercicio 5 :
 *  Crear un programa denominado my_cat que imite al comando UNIX cat. El mismo concatena el contenido de uno o más
 *  archivos en un único flujo de caractere (por defecto) dirigido a stdout.
 *  Su uso será:
 *  my_cat <archivo1> <archivo2> ... [-o <archivo_salida>]
 *  • Al pasar la opción -o en lugar de escribir a la salida estándar (pantalla) escribirá a un archivo
 *  llamado <archivo_salida>.
 *  Nota: Usar las llamadas al sistema: open, write, read, close y cualquier otra que sea necesaria.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// uso argc y *argv[] para poder pasarle los argumentos al programa
int main(int argc, char *argv[])
{
    // la funcion open devuelve un descriptor de archivo, que es un entero
    // le paso por argumento el nombre del archivo, y los flags de apertura
    // O_WRONLY: abre el archivo para escritura
    // O_CREAT: si el archivo no existe, lo crea
    // O_TRUNC: si el archivo existe, lo trunca a cero
    // 0666: permisos de lectura y escritura para el usuario, grupo y otros
    int fd = open(argv[argc-1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    // si el descriptor de archivo es -1, hubo un error
    if (fd == -1) {
        perror("open");
        return 1;
    }
    // recorro los argumentos pasados al programa
    for (int i = 1; i < argc-1; i++) {
        // abro el archivo en modo lectura
        // O_RDONLY: abre el archivo para lectura
        int fd2 = open(argv[i], O_RDONLY);
        // si el descriptor de archivo es -1, hubo un error
        if (fd2 == -1) {
            perror("open");
            return 1;
        }
        // leo el archivo y lo escribo en el archivo de salida
        // creo un buffer de 1024 bytes
        char buffer[1024];
        int n;
        // leo el archivo hasta que llego al final
        while ((n = read(fd2, buffer, sizeof buffer)) > 0) {
            // escribo en el archivo de salida
            // write devuelve la cantidad de bytes escritos
            if (write(fd, buffer, n) != n) {
                perror("write");
                return 1;
            }
        }
        // si n es -1, hubo un error
        if (n == -1) {
            perror("read");
            return 1;
        }
        // cierro el archivo
        if (close(fd2) == -1) {
            perror("close");
            return 1;
        }
    }
    // cierro el archivo
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }
    return 0;
}

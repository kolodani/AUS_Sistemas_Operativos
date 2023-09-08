#include <stdio.h>
#include <unistd.h>

int main(){
    int p = fork();                          // Crear un proceso hijo
    if(p !=0){                               // Si soy el padre
        for(;;);                             // Esperar a que el hijo termine
    }
    if(p == 0){                              // Si soy el hijo
        execl("/bin/ls", "ls", "-l", NULL);  // Ejecutar ls -l en el directorio actual
    }
    printf("Mi pid es %d", getpid());        // Imprimir el pid del proceso actual
    return 0;
}
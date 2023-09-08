#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int p = fork();                     // p es igual al pid del proceso hijo
    if(p==0)                            // si p es igual a 0, entonces es el proceso hijo
    {
        for(;;);                       // ciclo infinito
    }
    wait(NULL);                        // espera a que el proceso hijo termine
    printf( "Mi pid es %d", getpid()); // imprime el pid del proceso actual
    return 0;
}
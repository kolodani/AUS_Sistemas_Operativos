#include <stdio.h>
#include <unistd.h>

int main()
{
    int i, j, k;                   // cteo tres variables enteras
    for(i = 0; i < 3; i++)         // ciclo for que se ejecuta 3 veces
    {
        j = getpid();              // j es igual al pid del proceso actual
        k = fork();                // k es igual al pid del proceso hijo
        printf("%d - %d\n", j, k); // imprime el pid del proceso actual y el pid del proceso hijo
    }
    return 0;
}
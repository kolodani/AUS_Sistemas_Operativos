#include <stdio.h>
#include <stdlib.h>

void hola(void)
{
    printf("\nHola, esto puede ser una funcion de limpieza...\n");
}

void chau(void)
{
    printf("\nChau, esto puede ser una funcion que detiene un servicio por ejemplo...\n");
}

int main()
{

    atexit(hola);
    atexit(chau);

    exit(0);
}

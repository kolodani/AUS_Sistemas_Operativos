#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
int asistentes = 0;

void *puerta1(void *x)
{
    int i, k;
    for (k = 0; k < 5000; k++)
    {
        i = asistentes;
        i = i + 1;
        asistentes = i;
    }
    return NULL;
}

void *puerta2(void *x)
{
    int j, k;
    for (k = 0; k < 5000; k++)
    {
        j = asistentes;
        j = j + 1;
        asistentes = j;
    }
    return NULL;
}

int main()
{
    pthread_t p1, p2;
    pthread_create(&p1, 0, puerta1, NULL);
    pthread_create(&p2, 0, puerta2, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Cantidad de asistentes (debe ser 10000) %d\n", asistentes);
    return 0;
}

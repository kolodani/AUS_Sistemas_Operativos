#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int asistentes = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* puerta1(void *x) {
    int i, k;
    for(k=0; k<1000; k++) {
        pthread_mutex_lock(&mutex);
        i = asistentes;
        i = i + 1;
        asistentes = i;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* puerta2(void *x) {
    int j, k;
    for(k=0; k<1000; k++) {
        pthread_mutex_lock(&mutex);
        j = asistentes;
        j = j + 1;
        asistentes = j;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t p1, p2;
    pthread_create(&p1, 0, puerta1, NULL);
    pthread_create(&p2, 0, puerta2, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Cantidad de asistentes (debe ser 2000) %d\n", asistentes);
    return 0;
}

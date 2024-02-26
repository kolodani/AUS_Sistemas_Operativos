#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *mensaje1(void *x)
{
    printf("HOLA \n\n\n\n");
}

// void* mensaje2(void *x) {
//     printf("MUNDO\n");
// }

int main()
{
    pthread_t p1, p2;
    pthread_create(&p1, 0, mensaje1, NULL);
    //   pthread_create(&p2, 0, mensaje2, NULL);
    // pthread_join(p1, NULL);
    // pthread_join(p2, NULL);

    return 0;
}

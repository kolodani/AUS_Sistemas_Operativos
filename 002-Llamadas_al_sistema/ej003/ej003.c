/* mi_date.c - Muestra la fech y la hora acrual por pantalla */

#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

void print_time(){
    struct timeval tv;
    struct tm* ptm;
    char time_string[40];

    /* Obtenemos la fecha y hora del dia y la transformamos en una estructura tm */
    gettimeofday(&tv, NULL);
    ptm = localtime(&tv.tv_sec);

    /* Utilizando la estructura tm creamos un string con la informacion que deseamos */
    strftime(time_string, sizeof(time_string), "%d/%m/%Y %H:%M:%S", ptm);

    printf( "%s\n", time_string );
}

int main(){
    print_time();
    return 0;
}
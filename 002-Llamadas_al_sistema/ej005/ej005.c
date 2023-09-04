/* stats.c - Muestra estadisticas del sistema respecto al uso de memoria y los procesos en ejecucion. */

#include <stdio.h>
#include <linux/kernel.h>
//#include <linux/sys.h>
#include <sys/sysinfo.h>

int main(){
    const long minute = 60;
    const long hour = minute * 60;
    const long day = hour * 24;
    const double megabyte = 1024 * 1024;
    struct sysinfo si;

    /* Obtenemos estadisticas del sistema */
    sysinfo(&si);

    /* Mostramos algunos valores interesantes contenidos en la escructura sysinfo. */
    printf("Tiempo que lleva el sist. en funcionamiento: %ld dias , %ld:%02ld:%02ld\n", si.uptime / day, (si.uptime % day) / hour, (si.uptime % hour) / minute, si.uptime % minute);

    printf("Memoria RAM total: %5.1f MB\n", si.totalram / megabyte);
    printf("Memoria RAM libre: %5.1f MB\n", si.freeram / megabyte);
    printf("Cantidad de procesos corriendo: %d\n", si.procs);

    return 0;
}
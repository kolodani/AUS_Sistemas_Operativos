#include <stdio.h>
#include <unistd.h>  // declara funciones del estander POSIX

int main(){
    printf("PID: %d\n", getpid());
    // getpid() devuelve el PID del proceso actual
    printf("PPID: %d\n", getppid());
    // getppid() devuelve el PID del proceso padre

    return 0;
}
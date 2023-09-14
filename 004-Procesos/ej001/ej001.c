#include <stdio.h>
#include <unistd.h>  // declara funciones del estander POSIX

int main(){
    printf("PID: %d\n", getpid());
    printf("PPID: %d\n", getppid());

    return 0;
}
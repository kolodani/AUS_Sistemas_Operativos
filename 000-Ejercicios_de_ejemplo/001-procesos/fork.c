#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main() {
   pid_t pid_hijo = fork();
   int var = 5;
   switch(pid_hijo) {
     case 0: {   //proceso hijo
        var = 10;
        printf("Proceso hijo\n");
        printf("Hijo: PID=%d, PPID=%d ­ Variable=%d\n", getpid(), getppid(), var);
        break; 
     }
     case 1: {
        printf("errno = %d\n", errno);  perror("fork");
        break;
     }
     default: {  //proceso padre 
        printf("Proceso padre\n");
        printf("Padre: PID=%d, PPID=%d ­ Variable=%d\n", getpid(), getppid(), var);
        break; 
     }
  }
  return 0;
}

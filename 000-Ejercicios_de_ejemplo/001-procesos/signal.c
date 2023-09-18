#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
 
void sigproc(int sig) {
   printf("Ud presiono ctrl-c \n");
   printf("recibida la señal numero %d\n", sig);
}
 
void quitproc(int sig) {
   printf("Ud presiono ctrl-\\ \n");
   printf("recibida la señal numero %d\n", sig);
   exit(0);
}
 
int main() {
  signal(SIGINT, sigproc);
  signal(SIGQUIT, quitproc);
  printf("ctrl-c deshabilitado use ctrl-\\ para terminar \n");

  for(;;);

  return 0;
}

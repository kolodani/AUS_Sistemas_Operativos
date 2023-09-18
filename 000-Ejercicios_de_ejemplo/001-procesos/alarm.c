#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void handler( int sig ) {
   printf("Recibida la alarma %d\n.", sig);
   exit(0);
}

int main() {
  signal(SIGALRM, handler);
  alarm(5);
  printf("zzzzzz\n");
  for (;;) ; 
  return 0;
}

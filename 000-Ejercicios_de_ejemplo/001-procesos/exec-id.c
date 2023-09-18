#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main() {
   int ret;
   char *args[]={"sleep", "1000", NULL};
   char *env[]={"LOGNAME=gdm", "PWD=/opt", NULL}; 

   ret = execve("/bin/sleep", args, env);

   if (ret == -1) {
      printf("errno = %d\n", errno);
      perror("execve");
   }

   printf("Codigo inalcanzable");
   return 0;
}

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pids[5];
    int i;

    for(i = 4; i >= 0; --i)
    {
        pids[i] = fork();
        if(pids[i] == 0) /* Hijo */
        {
            sleep(i);
            _exit(0);
        }
    }
    for (i = 4; i >= 0; --i)
    {
        waitpid(pids[i], NULL, 0);
    }
    return 0;
}

// antes de correr el programa introducir en la terminal el siguiente comando:
/*
while :; do
    sleep 1; clear; ps -elf | grep Z;
done
*/
/*************************************************************************************/
/* shm_server.c                                                                      */
/*     -- simply creates the string and shared memory portion.                       */
/*  C Programming on Unix for two processes communicating via shared memory          */
/*  Download more programs at http://sourcecode4u.com/                               */
/*************************************************************************************/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SHMSZ     27

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    /* We'll name our shared memory segment "5678" */
    key = 5678;

    /* Create the segment. */
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /* Now we attach the segment to our data space */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    /* Now put some things into the memory for the other process to read */
    s = shm;

    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;
    *s = (int)NULL;

    /* Finally, we wait until the other process changes the first character of our memory
     * to '*', indicating that it has read what we put there. */
    printf("Waiting for client ");
    fflush(stdout);
    while (*shm != '*') {
        printf(". ");
        fflush(stdout);
        sleep(1);
    }
 
    /* Delete shared memory segment */
    shmctl(shmid, IPC_RMID, NULL);

    exit(0);
}

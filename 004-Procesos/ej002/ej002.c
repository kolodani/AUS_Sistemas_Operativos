#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main()
{
    int ret;
    char *args[] = {"ls", "-l", NULL};

    ret = execv("/bin/ls", args);

    if (ret == -1)
    {
        printf("errno = %d\n", errno);
        perror("execv");
        return -1;
    }

    printf("Codigo inalcanzable");
    return 0;
}
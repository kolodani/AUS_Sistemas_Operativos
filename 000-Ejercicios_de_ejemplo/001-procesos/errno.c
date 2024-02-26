#include <stdio.h>
#include <errno.h>
#include <sys/file.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int fd;

    fd = open("/NoExiste", O_RDONLY);

    if (fd == -1)
    {
        printf("errno = %d\n", errno);
        perror("main");
    }

    if ((fd = open("/", O_WRONLY)) == -1)
    {
        printf("errno = %d\n", errno);
        perror("main");
    }

    sqrt(-1);
    printf("errno = %d\n", errno);
    perror("main");

    return 0;
}

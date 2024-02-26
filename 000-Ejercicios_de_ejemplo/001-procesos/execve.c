#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main()
{
    int ret;
    char *args[] = {"ls", "-l", NULL};
    char *env[] = {"PWD=/opt", NULL};

    printf("HOLA\n");

    ret = execve("./a.out", args, env);

    if (ret == -1)
    {
        printf("errno = %d\n", errno);
        perror("execve");
    }

    printf("Codigo inalcanzable");
    return 0;
}

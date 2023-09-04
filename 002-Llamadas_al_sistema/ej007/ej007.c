#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int fd, c, i = 0;
    int result;
    int offset;
    char buf[32];

    /* chequeamos que se pasen los argumentos necesarios */
    if (argc < 3)
    {
        printf("Uso: %s <file> <Nro. de caracteres a mostrar>\n", argv[0]);
        exit(1);
    }

    /* chequeamos que el tercer argumento (2-esimo en argv) sea un digito */
    while ((c = argv[2][i]))
    {
        if (!isdigit(c))
        {
            printf("error! Debe ingresar un numero de digitos");
            printf("como segundo argumento\n");
            exit(1);
        }
        i++;
    }
    /* verificado que es un numero, convierto el argumento (char*)->(int) */
    offset = atoi(argv[2]);

    if ((fd = open(argv[1], O_RDONLY)) == -1)
        perror("error!");
    if ((result = pread(fd, buf, 31, offset)) == -1)
    {
        perror("error!");
        exit(1);
    }

    buf[result] = '\0';
    printf("char %d: %s\n", offset, buf);
    close(fd);

    return 0;
}

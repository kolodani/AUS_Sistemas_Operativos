#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

/* continua en proxima pagina... */
int isDigit(char *s){
    int i = 0;
    char c;
    while(c = s[i]){
        if(!isdigit(c)){
            printf("error!: el parametro %s no es un numero!\n", s);
            exit(1);
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    int fd;
    char buf[32];
    int result, offset, cuantos;

    /* chequeamos que se pasen los argumentos necesarios */
    if(argc < 4){
        printf("Uso: %s <archivo> <nro. de caracteres de partida> \ <cuantos caracters mostrar>\n", argv[0]);
        exit(1);
    }

    /* cheqeuamos que el 3er y 4to argumento sea un numero */
    isDigit(argv[2]);
    isDigit(argv[3]);

    offset = atoi(argv[2]);
    cuantos = atoi(argv[3]);

    if(cuantos > 31){
        printf("error, sobrepasa el limite del buffer\n");
        exit(1);
    }
    if((fd = open(argv[1], O_RDONLY)) == -1){
        perror("Error!");
    }
    if((result = pread(fd, buf, cuantos, offset)) == -1){
        perror("Error!");
        exit(1);
    }

    buf[result] = '\0';
    /* reemplazo de printf("caracter %d: %s\n", offset, buf);*/
    {
        char aux[8];
        char mensage[48];
        strcat(mensage, "caracter ");
        sprintf(aux, "%d", offset);
        strcat(mensage, aux);
        strcat(mensage, ": ");
        strcat(mensage, buf);
        aux[0] = '\012';
        aux[1] = 0; /* para adherir el (\n) */
        strcat(mensage, aux);
        write(1, mensage, strlen(mensage));
    }
    fsync(fd);
    return 0;
}

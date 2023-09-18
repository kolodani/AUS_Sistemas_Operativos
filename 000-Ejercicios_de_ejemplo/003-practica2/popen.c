//Realiza lo mismo que el programa dup2.c, pero aqui se utiliza
//popen
#include <stdio.h>
#include <unistd.h>

int main () {
    FILE* stream = popen("sort", "w");
    fprintf(stream, "1 - para todos y todos para uno.\n");
    fprintf(stream, "3 - tristes tigres.\n");
    fprintf(stream, "2 - horas y media.\n");
    fprintf(stream, "5 - mentarios.\n");
    fprintf(stream, "4 - cientos cuarenta y cuatro.\n");

    return pclose(stream);
}


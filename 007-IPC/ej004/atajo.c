#include <stdio.h>
#include <unistd.h>

int main () {
    FILE* stream = popen("sort", "w");
    fprintf(stream, "Hola\n");
    fprintf(stream, "Hijo\n");
    fprintf(stream, "Hasta Pronto\n");

    pclose(stream);
    return 0;
}
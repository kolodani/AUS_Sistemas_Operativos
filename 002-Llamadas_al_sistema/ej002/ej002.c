/* read.c - Llamada al sistema read en C */
#include <unistd.h>

int main()
{
    char buf[32];
    int result;

    result = read(0, buf, sizeof(buf));
    return result;
}

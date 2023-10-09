#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
    pid_t rf;
    int varfork = 10; // cambio hecho por la consigna h)
    int i = 0; // cambio hecho por la consigna h)
    rf = fork();
    switch (rf)
    {
    case -1:
        printf("No he podido crear el proceso hijo \n");
        break;
    case 0:
        sleep(1); // cambio hecho por la consigna g)
        printf ("Soy el hijo, mi PID es %d y mi PPID es %d \n", getpid(), getppid());
        for (i = 0; i < 10; i++) // cambio hecho por la consigna h)
        {
            varfork++;
        }
        sleep(20);
        break;
    default:
        printf("Soy el padre, mi PID es %d y el PID de mi hijo es %d \n", getpid(), rf);
        for (i = 0; i < 10; i++) // cambio hecho por la consigna h)
        {
            varfork += 10;
        }
        sleep(30);
        break;
    }
    printf("Soy el proceso %d y mi variable varfork es %d \n", getpid(), varfork); // cambio hecho por la consigna h)
    printf("Final de ejecucion de %d \n", getpid());
    exit (0);
}

// 1)
// a) Anote el valor mostrado por el shell inmediatamente despues de lanzar al
//    proceso en segundo plano e indique que representa dicho valor.
// respuesta:
// A- Los valores mostrados por el shell son el PID del proceso hijo y el PID
//    del proceso padre respectivamente.
//    El valor que representa el PID es el identificador del proceso.

// b) ¿Cuales son los PID de los procesos padre e hijo?
// B- En este caso el PID del padre era 16778 y el del hijo 16779.

// c) ¿Que tamaño de memoria ocupan los procesos padre e hijo?
// C- El tamaño de los procesos tanto del padre como del hijo son de 617 bytes.

// d) ¿Que realiza la funcion sleep? ¿Que proceso concluye antes su ejecucion?
// D- La funcion sleep hace que el proceso que la ejecuta se suspenda durante
//    el numero de segundos que se le pasa como parametro.
//    En este caso el proceso hijo concluye antes su ejecucion ya que tiene un
//    sleep de 20 segundos mientras que el padre tiene un sleep de 30 segundos.

// e) ¿que ocurre cuando la llamada al sistema fork devuelve un valor negativo?
// E- Cuando fork devuelve un numero negativo significa que no se ha podido
//    crear el proceso hijo. Si el resultado es 0 significa que se ha creado
//    correctamente el proceso hijo y si es positivo significa que se ha
//    creado correctamente el proceso padre.
//    Esto corresponde a que el proceso padre almacena el valor del PID del hijo
//    y el hijo almacena el valor de 0 ya que no tiene un proceso hijo.

// f) ¿Cual es la primera instruccion que ejecuta el proceso hijo?
// F- La primera instruccion que ejecuta el proceso hijo es el printf que
//    muestra por pantalla el mensaje "Soy el hijo, mi PID es 16779 y mi PPID
//    es 16778".

// g) Modifique el codigo del programa para asegurar que el proceso padre
//    imprime su mensaje presentacion ("Soy el Proceso") antes que el hijo
//    imprima el suyo.
// G- En mi caso el mensaje del padre se muestra antes que el del hijo.
//    Pero para asegurar de que eso se de la manere que pide la consigna, le he
//    añadido un sleep de 1 segundo al hijo para que el padre tenga tiempo de
//    ejecutarse antes que el hijo.

// h) Modifique el codigo fuente del programa declarando una variable entera
//    llamada varfork e inicializela a 10. Dicha variable debera incrementarse
//    10 veces en el padre y de 10 en 10. Mientras que el hijo la incrementara
//    10 veces de 1 en 1. Anote el valor final de la variable varfork para el
//    padre y para el hijo.
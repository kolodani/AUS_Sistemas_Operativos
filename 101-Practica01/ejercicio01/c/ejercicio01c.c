/*
 *  Ejercicio 01:
 *  C) Dotar a la función del apartado a) con la siguiente característica: “La función podrá recibir, mediante puntero
 *  a función, qué tipo de orden se llevará a cabo, por ejemplo: ascendente, descendente, valor absoluto ascendente,
 *  valor absoluto descendente, etc.
*/
//! Librerias
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//! Funciones
//? creo cada funcion de comparacion para qsort
int compararAscendente(const void *, const void *);
int compararDescendente(const void *, const void *);
int compararAbsolutoAscendente(const void *, const void *);
int compararAbsolutoDescendente(const void *, const void *);
void mostrarArray(int *, int);

int main()
{
    // Variables
    int *array;
    int opcion;
    unsigned n, i;
    // puntero a funcion
    int (*comparar)(const void *, const void *);
    // solicitar datos
    printf("Ingrese el tamaño del arreglo a ordenar:\n");
    printf("> ");
    scanf("%u", &n);
    // reservo memoria
    array = (int *)malloc(n * sizeof(int));
    // semilla random
    srand((int)getpid());
    // lleno el array con random
    for (i = 0; i < n; i++)
    {
        array[i] = (random() % 100) - 50;
    }
    // muestro el array desordenado
    printf("Array desordenado: ");
    mostrarArray(array, n);
    printf("\n");
    // elijo el tipo de orden
    do
    {
        printf("Elija el tipo de orden:\n");
        printf("1) Ascendente\n");
        printf("2) Descendente\n");
        printf("3) Valor absoluto ascendente\n");
        printf("4) Valor absoluto descendente\n");
        printf("> ");
        scanf("%d", &opcion);
        if ((opcion < 1) || (opcion > 4))
        {
            printf("La opcion: %d es incorrecta\n", opcion);
            printf("Ingrese una opcion valida\n");
        }
    } while ((opcion < 1) || (opcion > 4));
    switch (opcion)
    {
    case 1:
        comparar = compararAscendente;
        break;
    case 2:
        comparar = compararDescendente;
        break;
    case 3:
        comparar = compararAbsolutoAscendente;
        break;
    case 4:
        comparar = compararAbsolutoDescendente;
        break;
    default:
        printf("Opcion incorrecta\n");
        break;
    }
    // ordeno el array
    qsort(array, n, sizeof(int), comparar);
    // muestro el array ordenado
    printf("Array ordenado: ");
    mostrarArray(array, n);
    return 0;
}

int compararAscendente(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int compararDescendente(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int compararAbsolutoAscendente(const void *a, const void *b)
{
    return (abs(*(int *)a) - abs(*(int *)b));
}

int compararAbsolutoDescendente(const void *a, const void *b)
{
    return (abs(*(int *)b) - abs(*(int *)a));
}

void mostrarArray(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

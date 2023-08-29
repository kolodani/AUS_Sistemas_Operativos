/*
 *  Ejercicio 01:
 *  A) Escribir una función que ordene un array de n números enteros (n es un unsigned ingresado por el usuario)
 *  mediante el algoritmo quicksort.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void quicksort(int *, int, int);
void mostrarArray(int *, int);

int main()
{
    // variables
    unsigned n, i;
    int *array;
    // ingreso de datos
    printf("Ingrese la cantidad de elementos del array: ");
    scanf("%u", &n);
    // creacion del array
    array = (int *)malloc(n * sizeof(int));
    // llenado del array con random
    srand((int)getpid());
    for (i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
    }
    // mostrar array desordenado
    printf("Array desordenado: ");
    mostrarArray(array, n);
    printf("\n");
    // ordenar array
    quicksort(array, 0, n - 1);
    // mostrar array ordenado
    printf("Array ordenado: ");
    mostrarArray(array, n);
    return 0;
}

void quicksort(int* array, int izq, int der){
    int i = izq;
    int j = der;
    int pivote = array[(izq + der) / 2];
    int aux;
    while (i <= j)
    {
        while (array[i] < pivote)
        {
            i++;
        }
        while (array[j] > pivote)
        {
            j--;
        }
        if (i <= j)
        {
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }
    if (izq < j)
    {
        quicksort(array, izq, j);
    }
    if (i < der)
    {
        quicksort(array, i, der);
    }
}

void mostrarArray(int* array, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}


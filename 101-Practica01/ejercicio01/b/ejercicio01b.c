/*
 *  Ejercicio 01:
 *  B) Crear un programa que utilice la función qsort definida en <stdlib.h>
*/

/*
 *  qsort(arreglo, longitud del arreglo, tamaño de cada elemento del arreglo, función que compara)
 *  qsort es una funcion de la libreia estandar de C que ordena un arreglo de cualquier tipo de datos
 *  la misma recibe 4 parametros:
 * - arreglo: el arreglo a ordenar
 * - longitud del arreglo: la cantidad de elementos del arreglo
 * - tamaño de cada elemento del arreglo: el tamaño en bytes de cada elemento del arreglo
 * - función que compara: una función que compara dos elementos del arreglo y devuelve un entero
 *  esta funcion que comparar debe recibir dos punteros a elementos del arreglo y devolver un entero, este entero le
 *  indica al programa si el primer elemento es menor, igual o mayor al segundo elemento
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int comparar(const void *, const void *);
void mostrarArray(int *, int);

int main()
{
    // Variables
    int* array;
    unsigned n, i;
    // solicitar datos
    printf("Ingrese el tamaño del arreglo a ordenar:\n");
    scanf("%u", &n);
    // reservo memoria
    array = (int *)malloc(n * sizeof(int));
    // semilla random
    srand((int)getpid());
    // lleno el array con random
    for (i = 0; i < n; i++)
    {
        array[i] = random() % 100;
    }
    // muestro el array desordenado
    printf("Array desordenado: ");
    mostrarArray(array, n);
    printf("\n");
    // ordeno el array
    qsort(array, n, sizeof(int), comparar);
    // muestro el array ordenado
    printf("Array ordenado: ");
    mostrarArray(array, n);
    return 0;
}

int comparar(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
    // o lo que es lo mismo
    /*
    int x = *(int *)a;
    int y = *(int *)b;
    return (x - y);
    */
}

void mostrarArray(int* array, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}
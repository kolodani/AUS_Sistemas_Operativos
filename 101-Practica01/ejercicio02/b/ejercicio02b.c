/*
 *  Ejercicio 02:
 *  B) Crear un programa que utilice la función bsearch definida en <stdlib.h>
*/

//! Librerias
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//! Funciones
int comparar(const void *, const void *);
void mostrarArray(int *, int, int*);

int main()
{
    // Variables
    unsigned n, i, j, buscado;
    int *array, *resultado;
    // solicitar datos
    printf("Ingrese el tamaño del arreglo:\n");
    printf("> ");
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
    // ordeno el array
    qsort(array, n, sizeof(int), comparar);
    // cambio los repetidos en el arreglo
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (array[i] == array[j])
            {
                array[j]++;
            }
        }
    }
    // solicito el numero a buscar en el arreglo;
    printf("Ingrese el numero del 0 al 100 que quiere encontrar: \n");
    printf("> ");
    scanf("%u", &buscado);
    // realizo la busqueda con bsearch
    resultado = bsearch(&buscado, array, n, sizeof(int), comparar);
    if (resultado == NULL)
    {
        printf("El numero %d no se encuentra en el arreglo\n", buscado);
    }
    else
    {
        printf("El numero %d esta en el arraglo\n", buscado);
    }
    mostrarArray(array, n, resultado);
    return 0;
}

int comparar(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void mostrarArray(int *array, int n, int* m)
{
    for (int i = 0; i < n; i++)
    {
        if ((m != NULL)&&(array[i] == *m))
        {
            printf("[%d] ", array[i]);
        }
        else
        {
            printf("%d ", array[i]);
        }
    }
}


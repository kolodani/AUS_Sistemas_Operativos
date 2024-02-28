/*
 *  Ejercicio 9 : Shared Memory
 *  Un proceso denominado director alloca y escribe en un segmento de shared memory un número
 *  entre 0 y 2 el cual hace las veces de “identificador”(ID), y un número(NRO) con valor inicial 1(en
 *  este orden).
 *  Además existen 3 procesos jugadores, identificados por los ID en[0, 2](no es el PID es un número
 *  que se le asigna explícitamente en una variable global), que realizan continuamente lo siguiente:
 *  – Leen de la memoria compartida ambos valores, el ID y el NRO.
 *  – Si ID es el que le corresponde tomará el valor de NRO y lo reemplazará por el entero que le sigue
 *  que no contenga entre sus cifras a 3 ni sea múltiplo de 3.
 *  – Escribirá por pantalla un mensaje similar a este :
 *  “Se ejecutó el proceso[ID], se realizó el reemplazo NRO_viejo->NRO_nuevo”
 *  – Cambiará el valor de ID por el del siguiente proceso(secuencia... 0 1 2 0 1 2 ...)
 *  – Cuando NRO alcance el valor de 50, el proceso correspondiente, deberá asignar a ID el entero
 *  - 1.(ID del proceso director)Finalmente el proceso director deberá liberar la memoria compartida
 *  utilizada por los procesos e imprimir por pantalla “Ciclo finalizado” Notas :
 *  – en cada intervención de los procesos jugadores estos “attachan” y “dettachan” la memoria compartida al accederla
 *  – Cada uno de los procesos jugadores deberá ser lanzado en una terminal diferente y se le pasara el id del
 *  segmento de memoria compartida como argumento
*/

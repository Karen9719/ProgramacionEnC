#include <stdio.h>
#include <stdlib.h> //libreria par las funciones de memoria dinamica

int main(){
    int *puntero;// puntero a entero

    //1-asignacion de memoria
    // puntero = (int *)malloc(sizeof(int));
    // malloc: solicita el número de bytes (sizeof(int))
    // (int *): realiza un cast para convertir el puntero "vacío" retornado por malloc a un puntero a entero
    puntero=(int *)malloc(sizeof(int));

    //2-uso de la memoria
    *puntero = 26;//almacena el valor 26 en la direccion de memoria apuntada

    printf("El valor alojado en la memoria asignada( dinamica es: %d\n)", *puntero);

    //3-liberacion de la memoria
    free(puntero);//Devuelve el bloque de memoria a la pila
    return 0;
}
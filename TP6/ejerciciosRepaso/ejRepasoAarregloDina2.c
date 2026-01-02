#include <stdio.h>
#include <stdlib.h>

int main (){
    int *puntero;
    int capacidad = 5;
    int longitud=0;
    int numero;

    puntero= (int *)malloc(capacidad*sizeof(int)); //reservo este bloque de memoria

    printf("Ingrese numeros enteros (0 para finalizar): \n");
    scanf("%d", &numero);

    while (numero!=0)
    {
        if(longitud>=capacidad){

            capacidad *= 2; //aumento la capacidad al doble
            int*nuevo_puntero= (int*)realloc(puntero, capacidad*sizeof(int));//reasigo y pido la nueva memoria (mas grande porque el usuario esta pidiendo mas de la ingresada)
            puntero=nuevo_puntero;//reasigno al puntero inicial el nuevo puntero con nueva capacidad de memoria
        }

        puntero[longitud]=numero;
        longitud++;
        printf("Ingrese el siguiente numero entero:");
        scanf("%d", &numero);
    }
    //muestro el arreglo
    printf("Los numeros ingresados son: \n");
    for(int i=0; i<longitud; i++){
        printf("%d ", puntero[i]);
    }
    free(puntero);
    return 0;
}
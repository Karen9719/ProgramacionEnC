#include <stdio.h>
#include <stdlib.h>

int main (){

    int *puntero, tama, i;
    //1-el ususario define el tamaño en tiempo de ejecucion 
    printf("Cuantos elementos tendra el arreglo?: ");
    scanf("%d", &tama);

    //2-asignacion de memoria para 'tama' enteros
    //se solicita 'tama' veces el tamaño de un entero
    puntero = (int *)malloc(tama* sizeof(int));
    int *puntAux = puntero; //guardamos la direccion inicial para no perderla

    //3-carga de datos usando notacion de indice (como arreglo normal)
    for (i=0; i<tama; i++){
        printf("Ingrese un elemento: ");
        scanf("%d", &puntero[i]); //lo voy guardando en su direccion, es valido usar puntero [i]
    }

    //4-Impresion de datos (recorriendo el puntero auxiliar)
    printf("Contenido del arreglo dinamico es: \n");
    for(i=0; i<tama; i++){
        printf("%d\n", *puntAux);//muestro el contenido de cada elemento guardado en ese puntero
        puntAux++;//avanza el puntero auxiliar
    }   

    //5-Liberación
    //Se usa el puntero original, que no fue incrementado
    free(puntero);
    return 0;
}
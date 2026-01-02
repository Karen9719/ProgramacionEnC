#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#define MAX 8;

void primo(int arreglo[], int tama);
int mayorPrimo(int arreglo[], int tama);
int cantMaxPares(int arreglo[], int tama);
void ordenarDescendente(int arreglo [], int tama);


int main (){
    srand(time(NULL));
    //variables
    int tama, entrada, numero;
    int j=0;
    //entradas
    printf("Ingrese la cantidad de elementos del arreglo(maximo 8): ");
    scanf("%d", &tama);
    while(tama<1 || tama>8 ){
        printf("Ingrese un numero valido por favor: ");
        scanf("%d", &tama);
    }
    int arreglo[tama];
    printf("Si desea cargar usted los valores presione 0 de lo contrario presione 1: ");
    scanf("%d", &entrada);

    if(entrada==0){

        printf("Ingrese los valores del arreglo: ");
        for(int i=0; i<tama; i++){
            printf("\n arreglo[%d]: ", i);
            scanf("%d", &arreglo[i]);
        }

        printf("El arreglo ingresado es: ");
        while(j<tama){
            printf("\n arreglo[%d]=%d", j, arreglo[j]), j++;
        }

    }else{

        //genero el arreglo
        for(int i=0; i<tama; i++){
            numero = rand() % 101;
            arreglo[i] = numero; 
        }

        //muestro el arreglo
        printf("El arreglo generado con numeros aleatorios es: ");
        while(j<tama){
            printf("\n arreglo[%d]=%d", j, arreglo[j]), j++;
        }
    }
    // a. Mostrar arreglo original
    printf("\nArreglo original:\n");
    for (int i = 0; i < tama; i++) {
        printf("%d ", arreglo[i]);
    }

    // b. Mostrar el mayor número primo
    int primoMayor = mayorPrimo(arreglo, tama);
    if (primoMayor != -1)
        printf("\n\nEl mayor numero primo es: %d\n", primoMayor);
    else
        printf("\n\nNo existen numeros primos en el arreglo.\n");

    // c. Mostrar cantidad máxima de pares consecutivos
    int maxPares = cantMaxPares(arreglo, tama);
    printf("La mayor cantidad de pares consecutivos es: %d\n", maxPares);

    // d. Ordenar descendente y mostrar
    ordenarDescendente(arreglo, tama);
    printf("Arreglo ordenado de forma descendente:\n");
    for (int i = 0; i < tama; i++) {
        printf("%d ", arreglo[i]);
    }

    printf("\n");
    return 0;
}

void primo(int arreglo[], int tama){
    for(int i=0; i<tama; i++){
            int num;
            num = arreglo[i];
            int cantDivisor = 0;

            for(int j=2; j<num; j++){
                if(num%j==0 ){
                    cantDivisor++;
                }
            }
            if(cantDivisor==0 && num>1){
                printf("El numero es primo");
            }else{
                printf("El numero no es primo");
            }
    }
}
int mayorPrimo(int arreglo[], int tama){
    int mayor=0;
    for(int i=0; i<tama; i++){
        int num=arreglo[i];
        int cantDivisor=0;
        
        for(int j=2; j<num; j++){
            if(num%j==0){
                cantDivisor++;
            }
        }
        if(cantDivisor==0 && num>1){
            if(num>mayor){
                mayor=num;
            }
        }
        
    }
    return mayor;
}
int cantMaxPares(int arreglo[], int tama){
    int maxPares = 0;
    int contadorActual = 0 ;

    for(int i=0; i<tama; i++){
        int num = arreglo[i];
        if(num%2==0){
            contadorActual++;//aumento la racha actual
            
            if(contadorActual>maxPares){
                maxPares=contadorActual;
            }
        }else{
            contadorActual=0;//se corta la racha de numeros pares
        }
    }
    return maxPares;
}
void ordenarDescendente(int arreglo [], int tama){
    int aux;

    for (int i = 0; i < tama - 1; i++) {
        for (int j = i + 1; j < tama; j++) {
            if (arreglo[i] < arreglo[j]) { // si el actual es menor → intercambiar
                aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
    }
}
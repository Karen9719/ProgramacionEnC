#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//funcion para cargar los puntajes de los tiros
void cargarTiros(int *puntos, int tiros);
//funcion que calcula cuanto gano el jugador
float calcularGanancia(int *puntos, int tiros, float *perdida);
int main (){
    int tiros, *puntos;
    float ganacia, perdida;

    puts("------TIRO AL BLANCO------");
    printf("Ingrese la cantidad de tiros: ");
    scanf("%d", &tiros);

    puntos=malloc(tiros*sizeof(int));
    perdida=tiros*350;//cada tiro cuesta 350 por eso cuenta como perdida(lo paga al inicio)

    cargarTiros(puntos, tiros);//le paso la memoria del arreglo para ir guardando los tiros random generados y la cantidad de tiros para recorrer el arreglo

    return 0;
}
void cargarTiros(int *puntos, int tiros){
    //genero lo numeros random del 1 al 10
    srand(time(NULL));
    for(int i =0; i<tiros; i++){
        *puntos=rand()%10+1;
        puntos++;
    }
}

float calcularGanancia(int *puntos, int tiros, float *perdida){
    
}

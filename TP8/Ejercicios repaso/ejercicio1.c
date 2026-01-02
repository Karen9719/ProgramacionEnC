//uso de puntero con estructuras
#include <stdio.h>

struct Punto
{
    int x, y;
};

int main(){
    //declaro la estructura y su respectivo puntero
    struct Punto coordenadas, *Ppunto;

    Ppunto=&coordenadas; // asignoo direccion al puntero

    Ppunto->x=3;//asigno valores a la estructura mediante el puntero
    Ppunto->y=5;

    printf("Las coordenadas del punto son: %d, %d", Ppunto->x, Ppunto->y);
    
    return 0;
}
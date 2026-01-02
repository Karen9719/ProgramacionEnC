//arreglos de estructuras y punteros 
//Cuando tenemos un puntero a un arreglo de estructura, para acceder a cada campo de la estructura lo hacemos mediante el operador flecha
#include <stdio.h>

struct Alumno
{
    char ape[10];
    char nom[10];
    int edad;
    int nota1;
    int nota2;
    int nota3;
};

float promedio(int n1, int n2, int n3);
int main (){
    struct Alumno estudiante[2], *Pestudiante;// declaro el arreglo de tipo alumno y su puntero del mismo tipo(alumno)
    Pestudiante=estudiante;//inicializo el puntero en la primero posicion que apunta el puntero

    float prom;

    for(int i=0; i<2; i++){//para recorrer cada posicion del arreglo
        printf("Datos del alumno Nro %d:\n", i+1);

        puts("Ingrese el apellido del alumno: ");
        fflush(stdin);
        gets(Pestudiante->ape);

        puts("Ingrese el nombre del alummno: ");
        fflush(stdin);
        gets(Pestudiante->nom);

        puts("Ingrese la edad del alumno: ");
        scanf("%d", &Pestudiante->edad);

        puts("Ingrese 1era nota: ");
        scanf("%d", &Pestudiante->nota1);

        puts("Ingrese 2era nota: ");
        scanf("%d", &Pestudiante->nota2);

        puts("Ingrese 3era nota: ");
        scanf("%d", &Pestudiante->nota3);

        prom = promedio(Pestudiante->nota1, Pestudiante->nota2, Pestudiante->nota3);

        printf("El promedio del estudiante es: %.2f\n", prom);

        Pestudiante++;//avanzo al siguente estudiante

    }
    return 0;
}

float promedio(int n1, int n2, int n3){
    float prom = (n1 + n2 + n3)/3;
    return prom;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;

}Fecha;

typedef struct 
{
    int codigo;
    Fecha fechaEntrada;
    Fecha fechaSalida;
    char tipoHab[10];
    float montoTotal;

}Reserva;

typedef struct{
    char usuario[20];
    char contrasena[20];
}Cuenta; 

typedef struct 
{
    char apellido[10];
    char nombre[10];
    int DNI;
    Fecha fechaNacimiento;
    int tel;
    Cuenta cuenta;
    int reservaVigente;
    reservaVigente;
}Huesped;

char tipoHab [3][10]={
    "Simple",
    "Doble",
    "Suite"
};


int main(){
    //inicializacion de un arreglo de estructuras
    Huesped huespedes[3] = {
        {"Perez", "Laura", 12345678, {12, 3, 1985}, "1122334455", {"lauraP", "clave123"}, {0}, 0},
        {"Ramirez", "Carlos", 87654321, {7, 7, 1990}, "1198765432", {"carlosR", "pass456"}, {0}, 0},
        {"Martinez", "Sofia", 45678912, {20, 12, 1975}, "1100112233", {"sofiaM", "s3gura"}, {0}, 0}};

        for (int i = 0; i < 3; i++) {
            printf("Persona %d:\n", i + 1);
            printf("Nombre: %s\n", huespedes[i].nombre);
            printf("Apellido: %s\n", huespedes[i].apellido);
            printf("\n");
            }

    return 0;
}
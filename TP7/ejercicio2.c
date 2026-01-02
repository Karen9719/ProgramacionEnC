#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CUPO 15
#define ACTUAL_ANIO 2025

typedef struct 
{
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct
{
    char apellido[20];
    char nombre[20];
    int dni;
}Persona;

typedef struct 
{
    char nombre[20];
    Persona profesor;
    Fecha fechaInicio;
    Fecha fechaFinal;
    float costoInscripcion;
    int listaDni[15];
}Taller;

Taller cargarTaller();
void mostrarTaller(Taller t);
Taller actualizarCosto1(Taller t, float porcentaje);
float actualizarCosto2(float costo, float porcentaje);
int fechaValida(Fecha t);
int diasEnMes(int mes, int anio);

int main(){
    srand(time(NULL)); //Para el uso de rand()

    Taller taller;

    taller=cargarTaller();
    mostrarTaller(taller);

    float porcentaje;
    printf("\nIngrese el porcentaje de aumento de costo: ");
    scanf("%f", &porcentaje);

    printf("\n----Taller con costo actualizado / OPCION 1 ----\n");
    taller = actualizarCosto1(taller, porcentaje);
    mostrarTaller(taller);

    printf("\n----Taller con costo actualizado / OPCION 2 ----\n");
    taller.costoInscripcion = actualizarCosto2(taller.costoInscripcion, porcentaje);
    mostrarTaller(taller);
    return 0;
}

Taller cargarTaller(){//esta funcion devuelve un taller completo
    Taller t;
    printf("---INGRESO DE DATOS---");
    puts("Nombre del taller: ");
    fflush(stdin);
    gets(t.nombre);
    puts("Nombre del profesor a cargo del taller: ");
    fflush(stdin);
    gets(t.profesor.nombre);
    puts("Apellido del profesor: ");
    fflush(stdin);
    gets(t.profesor.apellido);
    puts("DNI del profesor:");
    scanf("%d", &t.profesor.dni);
    
    //fecha de inicio
    do{ //bucle do-while para garantizar que el usuario ingrese una fecha valida
        printf("Fecha de inicio (dd mm aaaa): ");
        scanf("%d %d %d", &t.fechaInicio.dia, &t.fechaInicio.mes, &t.fechaInicio.anio);
        if(!fechaValida(t.fechaInicio)){ //la validacion se delega a la funcio fechaValida(), que devuelve 1 o 0.
            printf("Fecha invalida, reintente. \n");
        }
    }while(!fechaValida(t.fechaInicio));//si el usuario se equivoca se repite la carga hasta que la fecha sea valida

    //fecha de fin
    do{
        printf("Fecha de fin (dd mm aaaa): ");
        scanf("%d %d %d", &t.fechaFinal.dia, &t.fechaFinal.mes, &t.fechaFinal.anio);
        if(!fechaValida(t.fechaFinal)){
            printf("Fecha invalida, reintente. \n");
        }
    }while(!fechaValida(t.fechaFinal));

    puts("Ingrese el costo de inscripcion del taller: ");
    scanf("%f", &t.costoInscripcion);
    

    //cargar DNIs aleatorios
    for(int i=0; i<CUPO; i++){
        t.listaDni[i]= 40000000 + rand() % 20000000;
    }
    return t;

}
int fechaValida(Fecha f){
    if(f.anio < ACTUAL_ANIO || f.anio>2026)
        return 0;
    if(f.mes>12 || f.mes<1)
        return 0;

    int maxDia = diasEnMes(f.mes, f.anio);
    return f.dia>=1 && f.dia <= maxDia; //Finalmente verifica que el dia este dentro del rango valido analizando el valor de verdad de una conjuncion
    
}

int diasEnMes(int mes, int anio){ //aunque el enunciado no lo pide analizamos el año bisiesto
    switch (mes)
    {
    case 4:
    case 6:
    case 9:
    case 11: return 30;
    case 2: return (anio % 400 == 0 || (anio%4 == 0 && anio % 100 != 0))? 29 : 28;
    default: return 31;
    }
}

void mostrarTaller(Taller t){
    printf("\n----Informacion del taller----\n");
    printf("Nombre del taller: %s\n: ", t.nombre);
    printf("Profesor: %s, %s - DNI: %d\n", t.profesor.apellido, t.profesor.nombre, t.profesor.dni);
    printf("Fecha de inicio: %02d/%02d/%d\n", t.fechaInicio.dia, t.fechaInicio.mes, t.fechaInicio.anio);
    printf("Fecha de finalizacion: %02d/%02d/%d\n", t.fechaFinal.dia, t.fechaFinal.mes, t.fechaFinal.anio);
    printf("Costo de inscripcion: $%.2f\n", t.costoInscripcion);
    printf("DNI de los alumnos: \n");
    for(int i = 0; i<CUPO; i++){
        printf("-%d-", t.listaDni[i]);
    }
    
}
//actualizar costo opcion1, en el main el valor retornado reemplaza al original: t=actualizarCosto1(t, porcentaje)
Taller actualizarCosto1(Taller t, float porcentaje){
    t.costoInscripcion=t.costoInscripcion + t.costoInscripcion*(porcentaje/100);
    return t;
}
//actulizar el costo opcion2. en el main se actualiza directamente el campo: t.costoInscripcion = actualizarCosto2(t.costoIncripcion, porcentaje);
float actualizarCosto2(float costo, float porcentaje){
    float costoActualizado = costo + costo * (porcentaje / 100);
    return costoActualizado;
}

//CONSULTAR SI TRABAJO ASUMIENDO QUE SIEMPRE SERAN 15 ALUMNOS POR TALLER O SI EL USUARIO DEBE INGRESAR UNA CANTIDAD COMO MAX 15(en el enunciado aparece asi)
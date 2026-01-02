#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

//ESTRUCTURAS
typedef struct{
    int dia;
    int mes; 
    int anio;
}Fecha;

typedef struct{
    Fecha fecha;
    char descripcion[MAX];
    float costoRep;
    char taller[MAX];
}Mantenimiento;

typedef struct{
    char patente[MAX];
    char marca[MAX];
    int anioFabricacion;
    int kilometros;
    int cantMantenimientos;
    Mantenimiento *mantenimientos;
}Camion;

//funciones a implementar
void cargarCamiones(Camion *c, int cantC);
void mostrarCamiones(Camion *c, int cantC);
void liberarMemoria(Camion *c, int cantC);
void actualizarKilometraje(Camion *c, int cantC, char patente[], int kilometros);
void agregarMantenimiento(Camion *c, char patenteN[]);
void gastoTotalMantenimientos(Camion *c, int cantC, char patente[]);
void mostrarPatentesConMasDe3Mantenimientos (Camion *c, int cantC);
void listaCamionesConCostoReparacionSuperior(Camion *c, int cantC, float montoI);
void mostrarPatenteYKm(Camion *c, int cantC);
int main(){
    int cantCamiones = 3;
    Camion *camiones=(Camion*)malloc(cantCamiones*sizeof(Camion));

    cargarCamiones(camiones, cantCamiones);
    mostrarCamiones(camiones, cantCamiones);
    /*char patente[MAX];
    int kilometros;
    printf("Ingrese la patente del camion a actualizar su kilometraje: ");
    gets(patente);
    fflush(stdin);
    printf("Ingrese los kilometros actualizados: ");
    scanf("%d", &kilometros);
    actualizarKilometraje(camiones, cantCamiones, patente, kilometros);*/
    //agregar mantenimiento al camion (realloc)
    /*char patenteN[MAX];
    printf("Ingrese la patente del camion a agregar un mantenimiento nuevo:");
    fflush(stdin);
    gets(patenteN);
    agregarMantenimiento(camiones, patenteN);*/
    //mostrar gasto total de los matenimientos
    /*char patenteI[MAX];
    printf("Ingrese la patente del camion a mostrar sus gastos totales: ");
    gets(patenteI);
    gastoTotalMantenimientos(camiones, cantCamiones, patenteI);*/
    /*mostrarPatentesConMasDe3Mantenimientos(camiones, cantCamiones);
    float montoI;
    printf("Ingrese el monto a buscar por manteniento: ");
    scanf("%f", &montoI);
    listaCamionesConCostoReparacionSuperior(camiones, cantCamiones, montoI);*/
    mostrarPatenteYKm(camiones, cantCamiones);
    liberarMemoria(camiones, cantCamiones);
    return 0;
}

void cargarCamiones(Camion *c, int cantC){

    //CAMION 1
    c[0]=(Camion){"AE123JH", "Scania", 2021, 12000, 2, malloc(2*sizeof(Mantenimiento))};

    c[0].mantenimientos[0]=(Mantenimiento){{4, 1, 2022}, "Cambio de aceite", 15030, "taller los 4hnos"};
    c[0].mantenimientos[1]=(Mantenimiento){{6, 5, 2023}, "Cambio de cubiertas", 160000, "taller los gardelitos"};

     //CAMION 2
    c[1]=(Camion){"LO556LO", "Volvo", 2017, 45200, 3, malloc(3*sizeof(Mantenimiento))};

    c[1].mantenimientos[0]=(Mantenimiento){{1, 1, 2024}, "Cambio de aceite", 70233, "taller los 4hnos"};
    c[1].mantenimientos[1]=(Mantenimiento){{25, 11, 2024}, "Cambio de cubiertas", 145800, "taller los gardelitos"};
    c[1].mantenimientos[2]=(Mantenimiento){{6, 2, 2025}, "Cambio de frenos", 164511, "taller los gardelitos"};

    //CAMION 3
    c[2]=(Camion){"PP456LK", "wolvagen", 2017, 203000, 4, malloc(4*sizeof(Mantenimiento))};

    c[2].mantenimientos[0]=(Mantenimiento){{2, 5, 2019}, "Cambio de aceite", 820000, "taller los 4hnos"};
    c[2].mantenimientos[1]=(Mantenimiento){{25, 10, 2020}, "Cambio de cubiertas", 40000, "taller los gardelitos"};
    c[2].mantenimientos[2]=(Mantenimiento){{7, 1, 2021}, "Cambio de frenos", 62000, "taller los nogales"};
    c[2].mantenimientos[3]=(Mantenimiento){{1, 2, 2025}, "Limpieza gral", 300000, "taller los Maria"};
}

void mostrarCamiones(Camion *c, int cantC){
    puts("------CAMIONES---------");
    for (int i = 0; i < cantC; i++)
    {
        printf("------CAMION %d---------\n", i+1);
        printf("Patente: %s\n", c[i].patente);
        printf("Marca: %s\n", c[i].marca);
        printf("Anio fabricacion: %d\n", c[i].anioFabricacion);
        printf("Kilometros recorridos: %d\n", c[i].kilometros);
        printf("Cantidad de mantenimientos: %d\n", c[i].cantMantenimientos);

        for(int j=0; j<c[i].cantMantenimientos; j++){
            printf("------MANTENIMIENTOS %d---------\n", j+1);
            printf("Fecha mantenimiento: %d/%d/%d \n", c[i].mantenimientos[j].fecha.dia, c[i].mantenimientos[j].fecha.mes,c[i].mantenimientos[j].fecha.anio);
            printf("Descripcion: %s\n", c[i].mantenimientos[j].descripcion);
            printf("Costo: %.2f\n", c[i].mantenimientos[j].costoRep);
            printf("Taller: %s\n", c[i].mantenimientos[j].taller);
        }
    }
    
}
void liberarMemoria(Camion *c, int cantC){
    for(int i=0; i<cantC; i++){
        free(c[i].mantenimientos);
    }
    free(c);
}
void actualizarKilometraje(Camion *c, int cantC, char patente[], int kilometraje){
    int encontrado=0;
    for(int i=0; i<cantC; i++){
        if(strcmp(c[i].patente, patente)==0){
            
            c[i].kilometros=kilometraje;
            printf("Kilometraje actualizado %d", c[i].kilometros);
            encontrado=1;
        }
    }
    if(encontrado==0){
        printf("No se encontro un camion con esa patente.");
    }
}

void agregarMantenimiento(Camion *c, char patenteN[]){
    for(int i=0; i<c[i].cantMantenimientos; i++){
        if(strcmp(c[i].patente, patenteN)==0){
            //redimensionar el arreglo mantenimietos(lo incremento para poder aumenta la cantidad de memoria)
            c[i].cantMantenimientos++;
            //Asigno la nueva cantidad de memoria
            c[i].mantenimientos=(Mantenimiento*)realloc(c[i].mantenimientos, c[i].cantMantenimientos*sizeof(Mantenimiento));
            // 2. Determinar la posición del nuevo elemento
            // La nueva posición es (cantidad actual - 1)
            int j=c[i].cantMantenimientos -1;
            printf("\n--- INGRESO NUEVO MANTENIMIENTO ---\n");
            printf("Ingrese fecha (dia mes anio, separados por espacio): ");
            scanf("%d %d %d", 
                &c[i].mantenimientos[j].fecha.dia, 
                &c[i].mantenimientos[j].fecha.mes, 
                &c[i].mantenimientos[j].fecha.anio);
            fflush(stdin);
            printf("Ingrese descripcion del mantenimiento realizado: ");
            gets(c[i].mantenimientos[j].descripcion);
            fflush(stdin);
            printf("Ingrese el costo: ");
            scanf("%f", &c[i].mantenimientos[j].costoRep);
            fflush(stdin);
            printf("Ingrese el taller: ");
            gets(c[i].mantenimientos[j].taller);
            fflush(stdin);
            
            puts("------nuevos datos del Mantenimiento---------");
            printf("fecha: %d/%d/%d\n", c[i].mantenimientos[j].fecha.dia, c[i].mantenimientos[j].fecha.mes,  c[i].mantenimientos[j].fecha.anio);
            printf("Descripcion: %s\n", c[i].mantenimientos[j].descripcion);
            printf("Costo: %.2f\n",  c[i].mantenimientos[j].costoRep);
            printf("Taller: %s\n", c[i].mantenimientos[j].taller);
        }
    }
    
    
}

void gastoTotalMantenimientos(Camion *c, int cantC, char patenteI[]){
    int encontrado =0;
    float suma=0;
    for(int i =0; i<cantC; i++){
        if(strcmp(c[i].patente, patenteI)==0){
            encontrado=1;
        }
        if(encontrado==1){
        for(int j=0; j<c[i].cantMantenimientos; j++){
            suma += c[i].mantenimientos[j].costoRep;
        }
        printf("Gasto total de los mantenimientos: %.2f\n", suma);
    }
    }
    if(encontrado == 0){
        printf("No se encontro un camion con esa patente. ");
    }
    
}

void mostrarPatentesConMasDe3Mantenimientos (Camion *c, int cantC){
    int contador=0;
    printf("Camiones con mas de 3 mantenimientos: \n");
    for(int i=0; i<cantC; i++){
        for(int j=0; j<c[i].cantMantenimientos; j++){
            contador++;
        }
        if(contador>3){
            printf("Patente: %s\n", c[i].patente);
        }
    }
}

void listaCamionesConCostoReparacionSuperior(Camion *c, int cantC, float montoI){
    int encontrado=0;
    for(int i=0; i<cantC; i++){
        for(int j=0; j<c[i].cantMantenimientos; j++){
            if(c[i].mantenimientos[j].fecha.mes == 1){
                if(c[i].mantenimientos[j].costoRep > montoI){
                    printf("Patente: %s\n", c[i].patente);
                    encontrado = 1;
                }
            }
        }
    }
    if(encontrado==0){
        printf("No se encontraron camiones.");
    }
}

void mostrarPatenteYKm(Camion *c, int cantC){
    int encontrado =0;
    for(int i=0; i<cantC; i++){
        int contador=0;
        if(c[i].anioFabricacion<2018){
            for(int j=0; j<c[i].cantMantenimientos; j++){
                contador++;
            }
            if(contador>=1){
                printf("Patente: %s\n", c[i].patente);
                printf("Kilometraje: %d\n", c[i].kilometros);
                encontrado = 1;
            }
        }
    }
    if(encontrado==0){
        printf("No se encontraron camiones.");
    }
}
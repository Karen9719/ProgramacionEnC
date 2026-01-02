#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 20

//estructuras
struct{
    int dni;
    int antiguedad;
    char rol[MAX];
    char lenguaje[MAX];
}typedef Desarrollador;

struct{
    int codigo;
    char estado[MAX];
    float costo;
    int cantDesarrolladores;
    Desarrollador *desarolladores;
}typedef Proyecto;

void cargarProyectos(Proyecto *p, int cantP);
void mostrarProyectos(Proyecto *p,  int cantP);
void liberarMemoria(Proyecto *p, int cantP);
void mostrarDesarroladoresPorEstado(Proyecto *p, int cantP, char estadoIngresado[]);
void mostrarMenorAntiguedad (Proyecto *p, int cantP);
void mostrarProyectosFinalizadosJavaBackend(Proyecto *p, int cantP);
void mostrarProyectoConMasDesarroladoresPorLenguaje(Proyecto *p, int cantP, char lenguaje[]);
float mostrarCostoPromedio(Proyecto *p, int cantP);

int main(){
    int cantProyectos=2;
    //printf("Ingrese la cantidad de proyectos a cargar: \n");
    //scanf("%d", &cantProyectos);

    Proyecto *proyectos = (Proyecto*)malloc(cantProyectos*sizeof(Proyecto));

    //cargo los proyectos
    cargarProyectos(proyectos, cantProyectos);
    //muestro los proyectos cargados
    mostrarProyectos(proyectos, cantProyectos);
    //mostrar desarrolladores segun estado de proyectos
    char estadoIngresado[MAX];
    printf("Ingrese el estado para ver los desarrolladores:");
    gets(estadoIngresado);
    
    mostrarDesarroladoresPorEstado(proyectos, cantProyectos, estadoIngresado);
    mostrarMenorAntiguedad(proyectos, cantProyectos);
    mostrarProyectosFinalizadosJavaBackend(proyectos, cantProyectos);

    char lenguaje[MAX];
    printf("Ingrese un lenguaje de programacion:");
    gets(lenguaje);
    
    mostrarProyectoConMasDesarroladoresPorLenguaje(proyectos, cantProyectos, lenguaje);
    float promedio = mostrarCostoPromedio(proyectos, cantProyectos);
    printf("Promedio de proyectos gestionados por al menos un desarrollador de 5anios de antiguedad: %.2f", promedio);
    //libero memoria
    liberarMemoria(proyectos, cantProyectos);
    return 0;

}
//para cargar por consola
/*void cargarProyectos(Proyecto *p, int cantP){

    for(int i=0; i<cantP; i++){
        printf("Proyecto nro %d\n", i+1);
        printf("Ingrese el codigo del proyecto(numero): \n");
        scanf("%d", &p[i].codigo);
        fflush(stdin);
        puts("Ingrese el estado actual del proyecto, elija uno: ");
        puts("Analisis");
        puts("Disenio");
        puts("Codificacion");
        puts("Pruebas");
        puts("Finalizado");
        gets(p[i].estado);
        fflush(stdin);
        puts("Costo total estimado del proyecto: ");
        scanf("%f", &p[i].costo);
        puts("Ingrese la cantidad de desarroladores");
        scanf("%d", &p[i].cantDesarrolladores);

        //asignacion de memoria para los desarrolladores
        p[i].desarolladores = (Desarrollador*)malloc(p[i].cantDesarrolladores*sizeof(Desarrollador));
        puts("INFORMACION DE DESARROLLADORES: ");
        for(int j=0; j<p[i].cantDesarrolladores; j++){
            printf("---Desarrollador nro %d ----\n", j+1);
            puts("Ingrese el DNI: ");
            scanf("%d", &p[i].desarolladores[j].dni);
            fflush(stdin);
            puts("Ingrese la cantidad de años de antiguedad: ");
            scanf("%d", &p[i].desarolladores[j].antiguedad);
            fflush(stdin);
            puts("Rol del desarrollador: ");
            gets(p[i].desarolladores[j].rol);
            fflush(stdin);
            puts("Leguaje de desarrollo: ");
            gets(p[i].desarolladores[j].lenguaje);
            fflush(stdin);
        }
    }
    
}*/

void cargarProyectos(Proyecto *p, int cantP){
    //en este caso voy a cargar 2 proyectos
    //proyecto 1
    p[0]=(Proyecto) {45, "Codificacion", 15000, 2, malloc(2*sizeof(Desarrollador))};
    //carga de datos de los desarrolladores(2)
    p[0].desarolladores[0]=(Desarrollador) {22698821, 6, "Backend", "Python"};
    p[0].desarolladores[1]=(Desarrollador){29568741, 2, "frontend", "javascript"};

    //proyecto 2
    p[1]=(Proyecto){87, "Finalizado", 450000, 1, malloc( 1*sizeof(Desarrollador))};
    //carga de datos para desarrolladores(1)
    p[1].desarolladores[0]=(Desarrollador){41002365, 6, "Backend", "Java"};
    
}
void mostrarProyectos(Proyecto *p,  int cantP){
    puts("------INFORMACION DE PROYECTOS CARGADOS------");
    for(int i=0; i<cantP; i++){
        printf("Proyecto nro %d \n", i+1);
        printf("Codigo: %d \n", p[i].codigo);
        printf("Estado: %s\n", p[i].estado);
        printf("Costo: %.2f\n", p[i].costo);
        printf("Cantidad de desarrolladores: %d \n", p[i].cantDesarrolladores);

        puts("INFORMACION DE LOS DESARROLADORES DEL PROYECTO: ");
            for (int j = 0; j < p[i].cantDesarrolladores; j++){
                printf("Desarrollador %d\n", j+1);
                printf("DNI: %d \n", p[i].desarolladores[j].dni);
                printf("Lenguaje de programacion: %s \n", p[i].desarolladores[j].lenguaje);
                printf("Rol: %s \n", p[i].desarolladores[j].rol);
                printf("Anios de antiguedad: %d\n", p[i].desarolladores[j].antiguedad);
            }
    }
}

void liberarMemoria(Proyecto *p, int cantP){
    for(int i=0; i<cantP; i++){
        free(p[i].desarolladores); //libero cada array de desarrolladores pertenecientes a cada proyecto (xq son varios desarroladores por proyecto)
    }
    free(p);//libero el array de proyecto
}

void mostrarDesarroladoresPorEstado(Proyecto *p, int cantP, char estadoIngresado[]){
    int encontrado = 0;
    for(int i=0; i<cantP; i++){
        if(strcmp(p[i].estado, estadoIngresado)==0){
            printf("Proyecto:%d(%s)\n", p[i].codigo, p[i].estado);
            for(int j=0; j<p[i].cantDesarrolladores; j++){
                printf("DNI: %d\n", p[i].desarolladores[j].dni);
                printf("Antiguedad: %d\n", p[i].desarolladores[j].antiguedad);
                printf("Rol: %s\n", p[i].desarolladores[j].rol);
                printf("Lenguaje de programacion: %s\n", p[i].desarolladores[j].lenguaje);
                puts("----------------------------");
                encontrado=1;
            }
        }
    }
    if(encontrado==0){
        printf("No se encontraron proyectos en ese estado.\n");
    }
}

void mostrarMenorAntiguedad (Proyecto *p, int cantP){
    int minAntig = 9999, dniMin=0;
    char rolMin[MAX];

    for(int i=0; i<cantP; i++){
        for(int j=0; j<p[i].cantDesarrolladores; j++){
            if(p[i].desarolladores[j].antiguedad<minAntig){
                minAntig=p[i].desarolladores[j].antiguedad;
                dniMin=p[i].desarolladores[j].dni;
                strcpy(rolMin, p[i].desarolladores[j].rol);
            }
        }
    }
    printf("Desarrollador con menor antiguedad: DNI %d | Rol: %s | %d anios.\n", dniMin, rolMin, minAntig);
}

void mostrarProyectosFinalizadosJavaBackend(Proyecto *p, int cantP){
    int encontrados =0;
    for(int i=0; i<cantP; i++){
        if(strcmp(p[i].estado, "Finalizado")==0){
            for(int j=0; j<p[i].cantDesarrolladores; j++){
                if(strcmp(p[i].desarolladores[j].rol, "Backend")==0){
                    if(strcmp(p[i].desarolladores[j].lenguaje, "Java")==0){
                        printf("---Proyectos finalizados que involucraron desarrolladores Backend con lenguaje Java:--- \n");
                        printf("Proyecto: %d (%s)\n", p[i].codigo, p[i].estado);
                        encontrados=1;
                    }
                }
            }
        }
    }

    if(encontrados==0){
        printf("No se encontraron proyetos finalizados con backend java.\n");
    }
}

void mostrarProyectoConMasDesarroladoresPorLenguaje(Proyecto *p, int cantP, char lenguaje[]){
    int max=-1, posMax=-1;
    
    for(int i=0; i<cantP; i++){//recorro los proyectos
        int contadorD=0;
        for(int j=0; j<p[i].cantDesarrolladores; j++){
            if(strcmp(lenguaje, p[i].desarolladores[j].lenguaje)==0){
                contadorD++;
            }
        }
        if(contadorD>max){
            max=contadorD;
            posMax=i;
        }
        
    }

    if(max>0){
        printf("El proyecto con mas desarrolladores de %s: %d(%d devs)\n", lenguaje, p[posMax].codigo, max);
    }else{
        printf("No se encontraros desarroladores de %s\n", lenguaje);
    }
}

float mostrarCostoPromedio(Proyecto *p, int cantP){
    int contador=0;
    int suma=0;
    
    for(int i=0; i<cantP; i++){
        int cumple=0;
        for(int j=0; j<p[i].cantDesarrolladores; j++){
            if(p[i].desarolladores[j].antiguedad>5){
                cumple=1; //usa bandera porque si tiene mas de 1 desarrollador con antiguedad>5 se va a sumar mas de una vez el costo y solo lo necesitamos una vez
            }
        }
        if(cumple==1){
            suma += p[i].costo;
            contador++;
        }
    }
    if(contador>0){
        return(float)suma/contador;
    }else{
        return 0;
    }
    
}
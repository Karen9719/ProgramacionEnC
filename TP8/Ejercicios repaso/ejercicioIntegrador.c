#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estructuras
typedef struct{
    char horario[50];
    char lugar[50];
}Encuentro;

typedef struct{
    char nombre[50];
    char dni[20];
    int edad;
}Voluntario;

typedef struct{//ESTRUCTURA PRINCIPAL
    char nombre_actividad[100];
    char area[50];
    char responsable[20];
    Encuentro encuentro; //estructura anidada para el horario y el lugar
    int num_voluntarios;
    Voluntario *voluntarios;//puntero dinamico para los voluntarios
}Actividad;

void mostrarActividades(Actividad *actividades, int num_actividades);
void listarVoluntarios(Actividad *actividades, int num_actividades);
void calcularEdadPromedio(Actividad *actividades, int num_actividades);
void contarActividadesPorArea(Actividad *actividades, int num_actividades, char *area);

int main(){
    //puntero actividades
    int num_actividades = 4; //numero fijo de actividades precargadas
    Actividad *actividades = (Actividad*)malloc(num_actividades*sizeof(Actividad)); //arreglo dinamico de actividad(tamaño 4)

    //precarga de datos con inicializacion estatica
    actividades[0]= (Actividad){
        "Restauracion de documentos historicos",
        "Conservacion",
        "Ana perez",
        {"10:00","sala de restauracion"},
        3,
        (Voluntario*)malloc(3*sizeof(Voluntario))//apunta a un arreglo dinamico que todavia no esta inicializado
    };
    //inicializo datos del arreglo voluntario para actividades 0
    actividades[0].voluntarios[0]=(Voluntario){"Lucas Martinez", "45879562",21};    
    actividades[0].voluntarios[1]=(Voluntario){"Maria lopez", "42569871", 21};
    actividades[0].voluntarios[2]=(Voluntario){"Franco diaz", "47455632", 22};

    actividades[1] = (Actividad){"Limpieza de artefactos arqueologicos","Arqueologia","Roberto Sanchez",{"14:00","Deposito"}, 2,(Voluntario *)malloc(2 * sizeof(Voluntario))};
    actividades[1].voluntarios[0] = (Voluntario){"Sofia Ramirez", "55667788", 19};
    actividades[1].voluntarios[1] = (Voluntario){"Pedro Fernandez", "66778899", 22};
    actividades[2] = (Actividad){"Catalogación de piezas de arte","Arte","Gabriela Torres",{"09:00", "Sala de exposicion"}, 4,(Voluntario *)malloc(4 * sizeof(Voluntario))};
    actividades[2].voluntarios[0] = (Voluntario){"Laura Garcia", "99887766", 24};
    actividades[2].voluntarios[1] = (Voluntario){"Tomas Diaz", "44556677", 20};
    actividades[2].voluntarios[2] = (Voluntario){"Valeria Cruz", "33445566", 26};
    actividades[2].voluntarios[3] = (Voluntario){"Diego Castro", "22334455", 23};
    actividades[3] = (Actividad){"Visitas guiadas educativas","Historia","Hist. Elena Morales",{"10:00", "Museo principal"},5,(Voluntario *)malloc(5 * sizeof(Voluntario))};
    actividades[3].voluntarios[0] = (Voluntario){"Camila Rodrguez", "77889900", 22};
    actividades[3].voluntarios[1] = (Voluntario){"Jorge Hernández", "55667788", 25};
    actividades[3].voluntarios[2] = (Voluntario){"Carla Mendoza", "11223344", 20};
    actividades[3].voluntarios[3] = (Voluntario){"Luis Navarro", "33445566", 23};
    actividades[3].voluntarios[4] = (Voluntario){"Fernanda Ortiz", "77889911", 24};

    mostrarActividades(actividades, num_actividades); //le paso el puntero y la variable num_actividades
    listarVoluntarios(actividades, num_actividades);
    calcularEdadPromedio(actividades, num_actividades);
    char area[20];
    printf("\nIngrese un area para buscar actividades: ");
    fflush(stdin);
    scanf("%s", &area);
    contarActividadesPorArea(actividades, num_actividades, area);

    for(int i=0; i<num_actividades; i++){
        free(actividades[i].voluntarios);
    }
    free(actividades);
    return 0;
}

void mostrarActividades(Actividad *actividades, int num_actividades){
    printf("\n-----Informacion de todas las actividades-----\n");
    for(int i=0; i<num_actividades; i++){
        printf("\nActividad: %s\n", actividades[i].nombre_actividad);
        printf("Area: %s\n", actividades[i].area);
        printf("Responsable: %s\n", actividades[i].responsable);
        printf("Horario: %s\n", actividades[i].encuentro.horario);
        printf("Lugar: %s\n", actividades[i].encuentro.lugar);
        printf("Numero de voluntarios: %d\n", actividades[i].num_voluntarios);
    }
}

void listarVoluntarios(Actividad *actividades, int num_actividades) {
    printf("\n------Voluntarios asignados a cada actividad-------\n");
    for(int i=0; i<num_actividades; i++){
        printf("Actividad: %s\n", actividades[i].nombre_actividad);
        for(int j=0; j<actividades[i].num_voluntarios; j++){
            printf("Nombre: %s, DNI: %s, Edad: %d\n", 
                actividades[i].voluntarios[j].nombre,
                actividades[i].voluntarios[j].dni,
                actividades[i].voluntarios[j].edad);
        }
    }
}

void calcularEdadPromedio(Actividad *actividades, int num_actividades){
    printf("\n----Edad promedio de los voluntarios por actividad----\n");
    for(int i=0; i<num_actividades; i++){
        int suma_edad = 0;
        for(int j=0; j<actividades[i].num_voluntarios; j++){
            suma_edad += actividades[i].voluntarios[j].edad;
        }
        float promedio;
        if(actividades[i].num_voluntarios>0){
            promedio = suma_edad / actividades[i].num_voluntarios;
        }else{promedio=0;}
        printf("Actividad: %s - edad promedio: %.2f \n", actividades[i].nombre_actividad, promedio);
    }
}

void contarActividadesPorArea(Actividad *actividades, int num_actividades, char *area){
    int contador =0;
    for(int i=0; i<num_actividades; i++){
        if(strcmp(actividades[i].area, area)== 0){
            contador++;
        }
    }
    printf("\n total de actividades en el area '%s': %d\n", area, contador);
}
#include <stdio.h>
#include <stdlib.h>     //para la función malloc
#include <string.h>     //para la funcion strcmp

// Estructura para los encuentros
typedef struct {
    char horario[50];
    char lugar[50];
} Encuentro;

// Estructura para los voluntarios
typedef struct {
    char nombre[50];
    char dni[20];
    int edad;
} Voluntario;

// Estructura para las actividades
typedef struct {
    char nombre_actividad[100];
    char area[50];
    char responsable[50];
    Encuentro encuentro; // Estructura anidada para el horario y el lugar
    int num_voluntarios;
    Voluntario *voluntarios; // Puntero dinámico para los voluntarios
} Actividad;


// Función para contar actividades por área
void contarActividadesPorArea(Actividad *actividades, int num_actividades, char *area);
// Función para calcular la edad promedio por actividad
void calcularEdadPromedio(Actividad *actividades, int num_actividades);
// Función para listar los voluntarios por actividad
void listarVoluntarios(Actividad *actividades, int num_actividades);
// Función para mostrar todas las actividades
void mostrarActividades(Actividad *actividades, int num_actividades);


int main() {
    int num_actividades = 4; // Número fijo de actividades precargadas
    Actividad *actividades = (Actividad *)malloc(num_actividades * sizeof(Actividad));

    // Precarga de datos con inicialización estática
    actividades[0] = (Actividad){
        "Restauración de documentos históricos",
        "Conservacion",
        "Dra. Ana Pérez",
        {"Lunes y miércoles, 10:00-14:00", "Sala de restauración"}, // Encuentro
        3,
        (Voluntario *)malloc(3 * sizeof(Voluntario))};
    actividades[0].voluntarios[0] = (Voluntario){"Lucas Martínez", "12345678", 21};
    actividades[0].voluntarios[1] = (Voluntario){"María López", "87654321", 25};
    actividades[0].voluntarios[2] = (Voluntario){"Julián Gómez", "11223344", 23};

    actividades[1] = (Actividad){
        "Limpieza de artefactos arqueológicos",
        "Arqueología",
        "Lic. Roberto Sánchez",
        {"Martes, 14:00-18:00", "Depósito de piezas"}, // Encuentro
        2,
        (Voluntario *)malloc(2 * sizeof(Voluntario))};
    actividades[1].voluntarios[0] = (Voluntario){"Sofía Ramírez", "55667788", 19};
    actividades[1].voluntarios[1] = (Voluntario){"Pedro Fernández", "66778899", 22};

    actividades[2] = (Actividad){
        "Catalogación de piezas de arte",
        "Arte",
        "Mtra. Gabriela Torres",
        {"Viernes, 09:00-13:00", "Sala de exposición"}, // Encuentro
        4,
        (Voluntario *)malloc(4 * sizeof(Voluntario))};
    actividades[2].voluntarios[0] = (Voluntario){"Laura García", "99887766", 24};
    actividades[2].voluntarios[1] = (Voluntario){"Tomás Díaz", "44556677", 20};
    actividades[2].voluntarios[2] = (Voluntario){"Valeria Cruz", "33445566", 26};
    actividades[2].voluntarios[3] = (Voluntario){"Diego Castro", "22334455", 23};

    actividades[3] = (Actividad){
        "Visitas guiadas educativas",
        "Historia",
        "Hist. Elena Morales",
        {"Sábado, 10:00-13:00", "Museo principal"}, // Encuentro
        5,
        (Voluntario *)malloc(5 * sizeof(Voluntario))};
    actividades[3].voluntarios[0] = (Voluntario){"Camila Rodríguez", "77889900", 22};
    actividades[3].voluntarios[1] = (Voluntario){"Jorge Hernández", "55667788", 25};
    actividades[3].voluntarios[2] = (Voluntario){"Carla Mendoza", "11223344", 20};
    actividades[3].voluntarios[3] = (Voluntario){"Luis Navarro", "33445566", 23};
    actividades[3].voluntarios[4] = (Voluntario){"Fernanda Ortiz", "77889911", 24};

    // Mostrar información de las actividades
    mostrarActividades(actividades, num_actividades);
    // Mostrar información de los voluntarios
    listarVoluntarios(actividades, num_actividades);
    // Calcular promedio por actividad
    calcularEdadPromedio(actividades, num_actividades);

    // Contar actividades por área
    char area_buscada[50];
    printf("\nIngrese un área para buscar actividades: ");
    scanf("%s", area_buscada);
    contarActividadesPorArea(actividades, num_actividades, area_buscada);

    // Liberar memoria dinámica
    for (int i = 0; i < num_actividades; i++) {
        free(actividades[i].voluntarios);
    }
    free(actividades);

    return 0;
}

// Función para mostrar todas las actividades
void mostrarActividades(Actividad *actividades, int num_actividades) {
    printf("\n--- Información de todas las actividades ---\n");
    for (int i = 0; i < num_actividades; i++) {
        printf("\nActividad: %s\n", actividades[i].nombre_actividad);
        printf("Área: %s\n", actividades[i].area);
        printf("Responsable: %s\n", actividades[i].responsable);
        printf("Horario: %s\n", actividades[i].encuentro.horario);
        printf("Lugar: %s\n", actividades[i].encuentro.lugar);
        printf("Número de voluntarios: %d\n", actividades[i].num_voluntarios);
    }
}


// Función para listar los voluntarios por actividad
void listarVoluntarios(Actividad *actividades, int num_actividades) {
    printf("\n--- Voluntarios asignados a cada actividad ---\n");
    for (int i = 0; i < num_actividades; i++) {
        printf("\nActividad: %s\n", actividades[i].nombre_actividad);
        for (int j = 0; j < actividades[i].num_voluntarios; j++) {
            printf("  Nombre: %s, DNI: %s, Edad: %d\n",
                actividades[i].voluntarios[j].nombre,
                actividades[i].voluntarios[j].dni,
                actividades[i].voluntarios[j].edad);
        }
    }
}

// Función para calcular la edad promedio por actividad
void calcularEdadPromedio(Actividad *actividades, int num_actividades) {
    printf("\n--- Edad promedio de voluntarios por actividad ---\n");
    for (int i = 0; i < num_actividades; i++) {
        int suma_edad = 0;
        for (int j = 0; j < actividades[i].num_voluntarios; j++) {
            suma_edad += actividades[i].voluntarios[j].edad;
        }
        float promedio = actividades[i].num_voluntarios > 0
                            ? (float)suma_edad / actividades[i].num_voluntarios
                            : 0.0;
        printf("Actividad: %s - Edad promedio: %.2f\n", actividades[i].nombre_actividad, promedio);
    }
}

// Función para contar actividades por área
void contarActividadesPorArea(Actividad *actividades, int num_actividades, char *area) {
    int contador = 0;
    for (int i = 0; i < num_actividades; i++) {
        if (strcmp(actividades[i].area, area) == 0) {
            contador++;
        }
    }
    printf("\nTotal de actividades en el área '%s': %d\n", area, contador);
}
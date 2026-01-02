/*
------------------------------------------------------------
TP6 - Punto 1: Estructuras en C

Este programa introduce el uso de estructuras (struct) para
organizar información compleja en C. A partir del registro
de una película, se busca trabajar con estructuras anidadas
(Fecha, Persona, Pelicula) y comprender cómo acceder a sus
miembros mediante el operador punto (.)

El objetivo de esta base es servir como guía inicial para
completar las funciones del programa. Los estudiantes deberán:
    - Implementar la carga completa de los datos de una película.
    - Mostrar la información registrada de forma legible.
    - Calcular el costo final de la película según ciertas condiciones.
    - Verificar si el género ingresado coincide con el de la película.

El código se entrega parcialmente comentado para orientar
la comprensión y favorecer la práctica autónoma.
------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

// ------------------------------------
// Definición de estructuras
// ------------------------------------

// Estructura para guardar una fecha (día, mes, año)
typedef struct
{
    int dia;
    int mes;
    int anio;

} Fecha;

// Estructura para guardar los datos del director
typedef struct
{
    char nombre[10];
    char apellido[10];
    int edad;
} Persona;

// Estructura principal: Película
typedef struct
{
    int codigo;
    char titulo[20];
    Persona director;//estructura anidada
    Fecha fechaEstreno;//estructura anidada
    float precioBase;
    char genero[20];
} Pelicula;

// ------------------------------------
// Arreglo de géneros disponibles
// ------------------------------------
char genero[6][20] = { //arreglo de 6 elementos con 20 caracteres maximo para cada elemento
    "Accion",
    "Comedia",
    "Drama",
    "Terror",
    "Ciencia ficcion",
    "Romance"};

// ------------------------------------
// Prototipos de funciones
// ------------------------------------
Pelicula cargarDatos();
void mostrarDatos(Pelicula p);
float calcularCosto(Pelicula p);
int verificarPorGenero(Pelicula p, int generoSeleccionado);

int main()
{
    // 1️- Declarar variable de tipo Pelicula
    Pelicula peli;
    int generoSelec;
    // 2- Cargar datos
    // Completar dentro de la función "cargarDatos"
    peli = cargarDatos();
    // 3- Mostrar datos
    // Completar dentro de la función "mostrarDatos"
    mostrarDatos(peli);
    // 4- Calcular costo final
    float costoFinal= calcularCosto(peli);
    printf("El costo final es: %.2f\n", costoFinal);
    // 5- Verificar género
    puts("\n--- VERIFICACION DE GENERO ---");
    printf("Ingrese un numero de genero (1-6) para verificar si coincide con la pelicula registrada: \n");
    printf("1-Accion. 2-Comedia. 3-Drama. 4-Terror. 5-Ciencia Ficcion. 6-Romance. \n");
    scanf("%d", &generoSelec);

    if (verificarPorGenero(peli, generoSelec)) {
        printf("El genero de la pelicula (%s) coincide con el seleccionado.\n", peli.genero);
    } else {
        printf("El genero de la pelicula (%s) NO coincide con el seleccionado.\n", peli.genero);
    }

    return 0;
}

// ------------------------------------
// Función para cargar datos
// ------------------------------------
Pelicula cargarDatos()
{
    Pelicula p;
    int generoSeleccionado;
    // ⚙️ Completar la carga de los datos paso a paso:
    // código, título, director, fecha, precio base y género.
    // Recordar: para acceder a los miembros de una estructura, se usa el operador punto (.)

    puts("Ingrese el codigo de la pelicula: ");
    scanf("%d", &p.codigo);

    puts("ingrese el titulo de la pelicula: ");
    fflush(stdin);
    gets(p.titulo);
    
    puts("Ingrese el nombre del director: ");
    fflush(stdin);
    gets(p.director.nombre);
    
    puts("Ingrese el apellido: ");
    fflush(stdin);
    gets(p.director.apellido);

    printf("Ingrese el dia de estreno de la pelicula: \n");
    scanf("%d", &p.fechaEstreno.dia);

    printf("Ingrese el mes de estreno de la pelicula: \n");
    scanf("%d", &p.fechaEstreno.mes);

    printf("Ingrese el anio de estreno de la pelicula: \n");
    scanf("%d", &p.fechaEstreno.anio);

    if(p.fechaEstreno.anio > 2025){
        printf("Año de estreno invalido, ingrese nuevamente un valor.");
        scanf("%d", &p.fechaEstreno.anio);
    }

    printf("Ingrese el precio base: \n");
    scanf("%f", &p.precioBase);

    puts("\nIngrese el genero de la pelicula, ingrese un numero:");
    printf("1-Accion. \n");
    printf("2-Comedia. \n");
    printf("3-Drama. \n");
    printf("4-Terror. \n");
    printf("5-Ciencia Ficcion. \n");
    printf("6-Romance. \n");
    scanf("%d", &generoSeleccionado);
    strcpy(p.genero, genero[generoSeleccionado-1]);
    
    return p;
    

}

// ------------------------------------
// Función para mostrar los datos
// ------------------------------------
void mostrarDatos(Pelicula p)
{
    printf("\n--- DATOS DE LA PELICULA ---\n");
    printf("Codigo: %d\n", p.codigo);
    printf("Titulo: ");
    puts(p.titulo);
    printf("Director: ");
    puts(p.director.nombre);
    puts(p.director.apellido);
    printf("Fecha de estreno: %d %d %d \n", p.fechaEstreno.dia, p.fechaEstreno.mes, p.fechaEstreno.anio);
    printf("Precio base: %.2f\n", p.precioBase);
    printf("Genero de la pelicula: %s\n", p.genero);
}

// ------------------------------------
// Función para calcular el costo final
// ------------------------------------
float calcularCosto(Pelicula p)
{
    if(p.fechaEstreno.anio == 2025 && (strcmp(p.genero, genero[0]) || strcmp(p.genero, genero[4]))){
        p.precioBase = p.precioBase + (p.precioBase*0.50);
    }else if(p.fechaEstreno.anio == 2024 && (strcmp(p.genero, genero[5]) || strcmp(p.genero, genero[1]))){
        p.precioBase = p.precioBase + (p.precioBase*0.25);
    }else{
        p.precioBase = p.precioBase;
    }
    return p.precioBase;
}

// ------------------------------------
// Función para verificar coincidencia de género
// ------------------------------------
int verificarPorGenero(Pelicula p, int generoSeleccionado)
{   
    // Verificar si el índice seleccionado es válido
    if (generoSeleccionado < 1 || generoSeleccionado > 6) {
        return 0;
    }
    // Retorna 1 si strcmp devuelve 0 (cadenas iguales), y 0 en caso contrario.
    if(strcmp(p.genero, genero[generoSeleccionado-1])==0){
        return 1;
    }else{
        return 0;
    }
}
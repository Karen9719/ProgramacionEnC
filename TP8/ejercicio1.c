#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct {
    int numero;
    int capacidadEsp;
    char tipoPantalla[MAX];
} Sala;

typedef struct {
    char titulo[MAX];
    char genero[MAX];
    int cantidadFunciones;
    int *espectadoresPorFuncion;
    Sala sala;
} Pelicula;

// ====== PROTOTIPOS DE FUNCIONES ======					
void cargarPeliculas(Pelicula *pelis, int cant);
void cargarEspectadores(Pelicula *pelis, int cant);
void mostrarPeliculas(Pelicula *pelis, int cant);
void listarPorGenero(Pelicula *pelis, int cant, char genero[]);
float calcularPromedioEspectadores(Pelicula p);
void mostrarSalasGrandes(Pelicula *pelis, int cant);
int contarPeliculasIMAX(Pelicula *pelis, int cant);
void mostrarPeliculasSalaLlena(Pelicula *pelis, int cant);
void liberarMemoria(Pelicula *pelis, int cant);

int main() {
    // Declarar variable para cantidad de películas
    // Declarar puntero de tipo Pelicula
    int cantPeliculas=2;
    Pelicula *p_peliculas=(Pelicula*)malloc(cantPeliculas*sizeof(Pelicula));

    // Invocar a la función cargarPeliculas y cargarEspectadores
    cargarPeliculas(p_peliculas, cantPeliculas);
    cargarEspectadores(p_peliculas, cantPeliculas);
    
    // Mostrar el listado general para controlar la carga
    mostrarPeliculas(p_peliculas, cantPeliculas);
    
    
    //INFORMES:
        // Declarar una variable para leer el género e invocar listarPorGenero
        char generoElegido[10];
        printf("Elija un genero: \n");
        fflush(stdin);
        gets(generoElegido);
        
        listarPorGenero(p_peliculas, cantPeliculas, generoElegido);
        // Calcular el promedio de espectadores por película con calcularPromedioEspectadores
        
        for(int i=0; i<cantPeliculas; i++){
            float promedio;
            printf("Pelicula: %s\n", p_peliculas[i].titulo);
            promedio= calcularPromedioEspectadores(*(p_peliculas+1));
            printf("El promedio de espectadores por la pelicula es: %.2f\n", promedio);
            
            
        }
        // Mostrar películas proyectadas en salas grandes con mostrarSalasGrandes
        mostrarSalasGrandes(p_peliculas, cantPeliculas);
        // Declarar una variable para la cantidad de IMAX y asignar lo que retorne contarPeliculasIMAX
        int cantImax;
        cantImax =contarPeliculasIMAX(p_peliculas,cantPeliculas);
        printf("Cantidad de pelis en formato IMAX: %d\n", cantImax);
        // Mostrar las películas con alguna función con sala llena (mostrarPeliculasSalaLlena)
        mostrarPeliculasSalaLlena(p_peliculas, cantPeliculas);
    
    // Liberar la memoria (liberarMemoria)
    liberarMemoria(p_peliculas,cantPeliculas);
    return 0;
}


void cargarPeliculas(Pelicula *pelis, int cant) {
    // Completar: leer los datos de cada película y su sala (o precargar datos)
    //pelicula 1
    pelis[0]=(Pelicula){"El viaje", "Aventura", 2, NULL, {1, 100, "2D"}};

    //pelicula 2
    pelis[1]=(Pelicula){"Titanic", "Drama", 3, NULL, {2, 250, "IMAX"}};

    //Asignar memoria dinamica para los arreglos
    pelis[0].espectadoresPorFuncion =malloc(pelis[0].cantidadFunciones * sizeof(int));
    pelis[1].espectadoresPorFuncion = malloc(pelis[1].cantidadFunciones * sizeof(int));
}

void cargarEspectadores(Pelicula *pelis, int cant) {
   // Completar: leer cantidad de espectadores por función (o precargar datos)
   //pelicula 1- 2 funciones
    pelis[0].espectadoresPorFuncion[0]=95;
    pelis[0].espectadoresPorFuncion[1]=80;

    //pelicula 2- 3 funciones
    pelis[1].espectadoresPorFuncion[0] = 110;
    pelis[1].espectadoresPorFuncion[1] = 107;
    pelis[1].espectadoresPorFuncion[2] = 250;
}

void mostrarPeliculas(Pelicula *pelis, int cant) { 
   // Completar: mostrar datos básicos de cada película
    for(int i=0; i<cant; i++){
        printf("Titulo: ");
        puts(pelis[i].titulo);
        printf("Genero: ");
        puts(pelis[i].genero);
        printf("Cantidad total de funciones: %d\n", pelis[i].cantidadFunciones);
        
        printf("Cantidad de espectadores por funcion: \n");
        for(int j=0; j<pelis[i].cantidadFunciones; j++){
            printf("%d \n", pelis[i].espectadoresPorFuncion[j]);
        }
        printf("Datos de la sala: \n");
        printf("Numero de sala: %d\n", pelis[i].sala.numero);
        printf("Capacidad total de espectadores: %d\n", pelis[i].sala.capacidadEsp);
        printf("Tipo de pantalla: ");
        puts(pelis[i].sala.tipoPantalla);

    }
}

void listarPorGenero(Pelicula *pelis, int cant, char genero[]) {
   // Completar: mostrar títulos del género indicado
    for (int  i = 0; i < cant; i++)
    {
        if(strcmp(genero, pelis[i].genero) == 0){
            printf("Pelis del genero seleccionado: \n");
            printf("%s\n", pelis[i].titulo);
        }
    }
    
}

float calcularPromedioEspectadores(Pelicula p) { //no deberia ser una funcion void?
    int total = 0;
    float prom=0;
   // Completar: recorrer el arreglo de espectadores y calcular promedio
    for(int i=0; i<p.cantidadFunciones; i++){
        total  += p.espectadoresPorFuncion[i];
    }
    prom= total / p.cantidadFunciones;
    return prom;
}

void mostrarSalasGrandes(Pelicula *pelis, int cant) {
     // Completar: mostrar películas con capacidad > 200
    printf("\n--- Peliculas en salas grandes (> 200) ---\n");
    for(int i=0; i<cant; i++){
        
            if(pelis[i].sala.capacidadEsp>200){
                printf("Peli con capacidad de sala mayor a 200: %s \n", pelis[i].titulo);
            }
        
    }
    
}

int contarPeliculasIMAX(Pelicula *pelis, int cant) {
    int contador = 0;
    // Completar: contar películas con tipoPantalla "IMAX"
    for(int i=0; i<cant; i++){
        if(strcmp(pelis[i].sala.tipoPantalla, "IMAX")==0){
            contador++;
        }
    }
    return contador;
}

void mostrarPeliculasSalaLlena(Pelicula *pelis, int cant) {
   // Completar: mostrar películas con alguna función a sala llena
   for(int i=0; i<cant; i++){
    for(int j=0; j<pelis[i].cantidadFunciones; j++){
        if(pelis[i].sala.capacidadEsp == pelis[i].espectadoresPorFuncion[j]){
            printf("Peliculas con al menos una funcion a sala llena: %s\n", pelis[i].titulo);
        }
    }
   }
}

void liberarMemoria(Pelicula *pelis, int cant) {
    // Completar: liberar memoria dinámica de espectadoresPorFuncion y pelis
    for(int i=0; i<cant; i++){
        free(pelis[i].espectadoresPorFuncion);
    }
    free(pelis);
}
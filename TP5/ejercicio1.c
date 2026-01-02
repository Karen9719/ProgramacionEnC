#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20

// Declaracion de funciones
void cargarArreglo(int arreglo[], int tama);
void mostrarArreglo(int arreglo[], int tama);
int buscarEliminado(int arreglo[], int tama, int salvado1, int salvado2, int salvado3);

int main()
{
    int puntuaciones[TAM];
    int tama;
    int salvado1, salvado2, salvado3;
    int eliminado;
    int valido = 0;

    printf("Ingrese la cantidad de participantes (<=20): ");
    scanf("%d", &tama);

    srand(time(NULL));

    cargarArreglo(puntuaciones, tama);
    mostrarArreglo(puntuaciones, tama);

    // Leer y validar salvados
    do
    {
        printf("\nIngrese el numero de los 3 participantes salvados (1 a %d, sin repetir):\n", tama);
        scanf("%d %d %d", &salvado1, &salvado2, &salvado3);

        if (salvado1 < 1 || salvado1 > tama ||
            salvado2 < 1 || salvado2 > tama ||
            salvado3 < 1 || salvado3 > tama) {
            printf("Error: Los números deben estar entre 1 y %d.\n", tama);
        } else if (salvado1 == salvado2 || salvado1 == salvado3 || salvado2 == salvado3) {
            printf("Error: No se pueden repetir los participantes.\n");
        } else {
            valido = 1;
        }
    } while (valido == 0);

    // Buscar el puntaje mínimo entre no salvados
    eliminado = buscarEliminado(puntuaciones, tama, salvado1, salvado2, salvado3);

    // Mostrar resultados
    printf("\n++++++++++++++++ RESULTADOS FINALES ++++++++++++++++:\n");
    mostrarArreglo(puntuaciones, tama);
    printf("Eliminado: Participante %d con %d puntos\n", eliminado + 1, puntuaciones[eliminado]);
    printf("Puntuaciones de los participantes salvados:\n");
    printf("Participante %d: %d puntos\n", salvado1, puntuaciones[salvado1 - 1]);
    printf("Participante %d: %d puntos\n", salvado2, puntuaciones[salvado2 - 1]);
    printf("Participante %d: %d puntos\n", salvado3, puntuaciones[salvado3 - 1]);

    return 0;
}

// Definicion de funciones
void cargarArreglo(int arreglo[], int tama){
    int i;
    for(i=0; i<tama; i++){
        int suma = 0;
        int j, aleatorio;
        printf("Participante %d -> puntajes parciales: ", i + 1);
        for(j=0; j<3; j++){
            aleatorio= 1 + rand()%10;
            suma = suma + aleatorio;
            printf("%d ", aleatorio);
        }
        arreglo[i]=suma;
        printf("\n");
    }
}

void mostrarArreglo(int arreglo[], int tama) {
    printf("\n--- Puntajes finales ---\n");
    for (int i = 0; i < tama; i++) {
        printf("Participante %d -> Puntaje total: %d\n", i + 1, arreglo[i]);
    }
}

int buscarEliminado(int arreglo[], int tama, int salvado1, int salvado2, int salvado3){
    int min = 9999;
    int eliminado = -1;
    for(int i=0; i<tama; i++){
        if((i+1)!=salvado1 && (i+1)!=salvado2 && (i+1)!=salvado3){
            if(arreglo[i] < min){
                min = arreglo[i];
                eliminado = i;
            }
        }
    }
    return eliminado;
}
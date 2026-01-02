#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    // Declaración de variables
    char car;
    int cantPalabras = 0, totalCaracteres = 0, espacios = 0, longitudActual = 0;
    int longitudMax = 0, longitudMin = 9999;
    float promedioCaracteres, porcentajeEspacios;
    bool enPalabra = false, valido = true;

    // Entrada de datos
    printf("Ingrese una secuencia de caracteres (termine con '.'): ");
    car = getchar();

    // Procesar la secuencia hasta encontrar el punto
    while (car != '.' && valido) {
        totalCaracteres++;

        // Validar que el carácter sea letra, número o espacio
        if (!isalnum(car) && car != ' ') {
            printf("Carácter inválido detectado: %c\n", car);
            valido = false;
        } else {
            // Contar espacios
            if (car == ' ') {
                espacios++;
                if (enPalabra) {
                    // Fin de palabra
                    cantPalabras++;
                    if (longitudActual > longitudMax) {
                        longitudMax = longitudActual;
                    }
                    if (longitudActual < longitudMin && longitudActual > 0) {
                        longitudMin = longitudActual;
                    }
                    enPalabra = false;
                    longitudActual = 0;
                }
            } else {
                // Es un carácter de palabra (letra o número)
                if (!enPalabra) {
                    enPalabra = true;
                }
                longitudActual++;
            }
        }

        // Leer el próximo carácter
        car = getchar();
    }

    // Procesar la última palabra si existe
    if (enPalabra && valido) {
        cantPalabras++;
        if (longitudActual > longitudMax) {
            longitudMax = longitudActual;
        }
        if (longitudActual < longitudMin && longitudActual > 0) {
            longitudMin = longitudActual;
        }
    }

    // Ajustar longitudMin si no se encontraron palabras
    if (cantPalabras == 0) {
        longitudMin = 0;
    }

    // Calcular promedio y porcentaje
    if (cantPalabras > 0) {
        promedioCaracteres = (float)(totalCaracteres - espacios) / cantPalabras;
    } else {
        promedioCaracteres = 0;
    }

    if (totalCaracteres > 0) {
        porcentajeEspacios = (float)(espacios * 100) / totalCaracteres;
    } else {
        porcentajeEspacios = 0;
    }

    // Mostrar informe final
    printf("\nINFORME FINAL\n");
    printf("Cantidad de palabras: %d\n", cantPalabras);
    printf("Longitud de la palabra más larga: %d\n", longitudMax);
    printf("Longitud de la palabra más corta: %d\n", longitudMin);
    printf("Promedio de caracteres por palabra: %.2f\n", promedioCaracteres);
    printf("Porcentaje de espacios sobre el total de caracteres: %.2f%%\n", porcentajeEspacios);

    return 0;
}
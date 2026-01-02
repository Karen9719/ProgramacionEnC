#include <stdio.h>
#include <ctype.h>

int main() {
    // Variables
    char frase, letra;
    int longitud = 0, cantVocales = 0, cantLetra = 0, cantPalabras = 0, cantPalabrasLetra = 0;
    char MF = '.';
    char anterior = ' ';

    // Entrada de la letra a analizar
    printf("Ingrese la letra que desea analizar: ");
    scanf(" %c", &letra);
    while (getchar() != '\n'); // Limpiar el buffer

    // Entrada de la frase
    printf("Ingrese la frase finalizando con un punto(.): ");
    frase = getchar();

    // Procesar la secuencia
    while (frase != MF) {
        longitud = longitud + 1;

        // Contar vocales (insensible a mayúsculas/minúsculas)
        if (tolower(frase) == 'a' || tolower(frase) == 'e' || tolower(frase) == 'i' ||
            tolower(frase) == 'o' || tolower(frase) == 'u') {
            cantVocales = cantVocales + 1;
        }

        // Contar apariciones de la letra
        if (tolower(frase) == tolower(letra)) {
            cantLetra = cantLetra + 1;
        }

        // Contar palabras y palabras que inician con la letra
        if (anterior == ' ' && frase != ' ' && frase != MF) {
            cantPalabras++;
            if (tolower(frase) == tolower(letra)) {
                cantPalabrasLetra++;
            }
        }

        anterior = frase;
        frase = getchar();
    }

    // Salidas
    printf("\nLongitud de la secuencia: %d\n", longitud);
    printf("Cantidad de vocales: %d\n", cantVocales);
    printf("Cantidad de apariciones de la letra '%c': %d\n", letra, cantLetra);
    printf("Cantidad de palabras: %d\n", cantPalabras);
    printf("Cantidad de palabras que inician con la letra '%c': %d\n", letra, cantPalabrasLetra);

    return 0;
}
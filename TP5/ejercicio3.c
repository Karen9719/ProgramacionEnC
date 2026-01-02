#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

int main() {
    char palabra[MAX], adivinada[MAX];
    char letra;
    int len, intentos = 3, aciertos = 0, i;
    int completa = 0;

    printf("Jugador 1 ingrese la palabra a adivinar: ");
    scanf("%s", palabra);

    len = strlen(palabra);

    // Inicializar la palabra adivinada con guiones
    for(i = 0; i < len; i++) {
        adivinada[i] = '_';
    }
    adivinada[len] = '\0';

    while(intentos > 0 && !completa) {
        printf("\nPalabra: ");
        for(i = 0; i < len; i++) {
            printf("%c ", adivinada[i]);
        }
        printf("\nIntentos disponibles: %d\n", intentos);

        printf("Jugador 2 ingrese una letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra);

        int acierto_en_turno = 0;
        for(i = 0; i < len; i++) {
            if(palabra[i] == letra && adivinada[i] == '_') {
                adivinada[i] = letra;
                acierto_en_turno = 1;
            }
        }

        if(!acierto_en_turno) {
            intentos--;
        }

        // Verificar si la palabra fue adivinada
        completa = 1;
        for(i = 0; i < len; i++) {
            if(adivinada[i] == '_') {
                completa = 0;
                break;
            }
        }
    }

    if(completa) {
        printf("\n¡Felicidades! Adivinaste la palabra: %s\n", palabra);
    } else {
        printf("\n¡Agotaste los intentos! La palabra era: %s\n", palabra);
    }

    return 0;
}
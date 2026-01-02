//Lea y almacene una frase en minúscula en un arreglo de nombre frase[100]. Cuente las
//consonantes y conviértelas a mayúsculas.
//Use variables punteros para manejar los contadores.

#include <stdio.h>
#include <ctype.h>
#define TAMA 100

int main() {
    char frase[TAMA];
    char *puntero = frase;
    int contConsonantes = 0;

    printf("Ingrese la frase en minúsculas (máx. 100 caracteres, terminar con '.'):\n");
    scanf("%c", frase);
    

    while (*puntero) {
        if (*puntero >= 'a' && *puntero <= 'z' && 
            *puntero != 'a' && *puntero != 'e' && *puntero != 'i' && 
            *puntero != 'o' && *puntero != 'u') {
            *puntero = toupper(*puntero);
            contConsonantes++;
        }
        puntero++;
    }

    printf("\nLa frase con consonantes en mayúsculas es: %s\n", frase);
    printf("Cantidad de consonantes: %d\n", contConsonantes);

    return 0;
}
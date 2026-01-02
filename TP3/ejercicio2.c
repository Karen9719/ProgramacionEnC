#include <stdio.h>

int main (){
    //variables
    char frase;

    int cantPalabras = 0;
    int longMasLarga = 0;
    int longMasCorta = 100;
    int longPalabraActual = 0;
    char anterior = ' ';
    

    printf ("Ingrese la frase:\n");
    scanf("%c", &frase);

    while(frase!='.'){
        while (frase!='.' && frase!=' '){
            if(anterior ==' ' && frase!=' '){
                cantPalabras=cantPalabras+1;
            }
            longPalabraActual=longPalabraActual + 1;
            anterior=frase;
            scanf("%c", &frase);
        }
        
        if(longPalabraActual>longMasLarga){
            longMasLarga=longPalabraActual;
        }
        if(longPalabraActual<longMasCorta){
            longMasCorta=longPalabraActual;
        }
        longPalabraActual=0;
        if(frase==' '){
            anterior=frase;
            scanf("%c", &frase);
        }
    }

    printf("Cantidad de palabras:%d\n", cantPalabras);
    printf("Longitud de la palabra mas larga:%d\n", longMasLarga);
    printf("Longitud de la palabra mas corta: %d\n ", longMasCorta);
    return 0;
}
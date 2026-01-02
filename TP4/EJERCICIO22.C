#include <stdio.h>
#include <ctype.h>
#include <math.h>


/* ---- Declaración de funciones ---- */
int   es_vocal(char car);
float porcentaje(int parte, int total); 
float indice_equilibrio(int vocales, int consonantes);
void  imprimir_conteos(int mayus, int minus, int letras, int vocales, int consonantes, int digitos, int espacios, int total_car);

/* ---- Programa principal ---- */
int main(void) {
    //entrada
    char c; //esta es la frase que va ingresar el usuario

    /* Contadores */
    int mayus = 0, minus = 0, letras = 0, vocales = 0, digitos = 0, espacios = 0;
    int total_car = 0;  /* todos los caracteres leidos antes del '.' */
    int consonantes=0;

    /* Rachas */
    // variables para contar y almacenar la mayor racha
    int racha_letras = 0, racha_max_letras = 0;   
    int racha_digitos = 0, racha_max_digitos = 0;

    printf("Ingrese texto y finalice con un punto (.):\n");
    fflush(stdin);
    c = getchar();
    while (c  != '.') {
    
        /* contar caracter total */
        total_car++;
        /* contar si es espacio */
        if(c==' '){
            espacios++;
        }
        /* contar si es letra, además si es mayúscula, minúscula y vocal (invocar la función es_vocal) */
                //Analizar la racha de letras y cortar la de digígitos

        if (isalpha(c)==1) {
            letras++;
            // ... continuar  ...
				}
        /* contar si dígito */
                //Analizar la racha de dígitos y cortar la de letras

         /* Cuando no es letra ni digito: cortan ambas rachas */
        
        c = getchar();
    }

    //calcular consonantes

    /* Calcular Porcentajes mayúsculas, vocales, dígitos (redondeados con floorf/ceilf) invoque a la función porcentaje */

    /* calcular IE invocando a la función */

    /* Salidas */
    
    return 0;
}


/* ---- Implementación de funciones ---- */
int   es_vocal(char car){
    bool resultado = false;
    switch (car)
    {
    case 'a':
        resultado=true;
        break;
    case 'e':
        resultado=true;
        break;
    case 'i':
        resultado=true;
        break;
    case 'o':
        resultado=true;
        break;
    case 'u':
        resultado=true;
        break;
    }
    return(resultado);
}

float porcentaje(int parte, int total){
    float porcentaje = (parte/total)*100;
    return(porcentaje);
}

float indice_equilibrio(int vocales, int consonantes){
    int letras=vocales+consonantes;
    float IE;
    if(letras==0){
        printf("0.00\n");
    }else{
        IE=fabsf(vocales-consonantes)/vocales+consonantes;
    }
    return(IE);
}

void  imprimir_conteos(int mayus, int minus, int letras, int vocales, int consonantes, int digitos, int espacios, int total_car){
    printf("Mayusculas: %d\n", mayus);
    printf("Minusculas: %d\n", minus);
    printf("Letras totales: %d\n", letras);
    printf("Mayusculas: %d\n", mayus);
}
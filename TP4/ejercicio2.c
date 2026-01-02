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
    char c;

    /* Contadores */
    int mayus = 0, minus = 0, letras = 0, vocales = 0, digitos = 0, espacios = 0;
    int total_car = 0;  /* todos los caracteres leidos antes del '.' */
    int consonantes=0;

    /* Rachas */
    int racha_letras = 0, racha_max_letras = 0;   
    int racha_digitos = 0, racha_max_digitos = 0;

    printf("Ingrese texto y finalice con un punto (.):\n");
    fflush(stdin);
    c = getchar();
    while (c  != '.') {
        total_car++;

        if (c == ' ') {
            espacios++;
            racha_letras = 0;
            racha_digitos = 0;
        }
        else if (isalpha(c)) {
            letras++;
            if (isupper(c)) mayus++;
            if (islower(c)) minus++;
            if (es_vocal(c)) vocales++;
            racha_letras++;
            if (racha_letras > racha_max_letras) racha_max_letras = racha_letras;
            racha_digitos = 0;
        }
        else if (isdigit(c)) {
            digitos++;
            racha_digitos++;
            if (racha_digitos > racha_max_digitos) racha_max_digitos = racha_digitos;
            racha_letras = 0;
        }
        else {
            racha_letras = 0;
            racha_digitos = 0;
        }
        c = getchar();
    }

    consonantes = letras - vocales;

    int porc_mayus = letras ? (int)ceilf(porcentaje(mayus, letras)) : 0;
    int porc_vocales = letras ? (int)ceilf(porcentaje(vocales, letras)) : 0;
    int porc_digitos = total_car ? (int)ceilf(porcentaje(digitos, total_car)) : 0;

    float ie = indice_equilibrio(vocales, consonantes);

    imprimir_conteos(mayus, minus, letras, vocales, consonantes, digitos, espacios, total_car);

    printf("Porcentajes (enteros, redondeo con floorf/ceilf):\n");
    printf("- Mayusculas sobre letras: %d%%\n", porc_mayus);
    printf("- Vocales sobre letras: %d%%\n", porc_vocales);
    printf("- Digitos sobre total: %d%%\n", porc_digitos);

    printf("Rachas maximas:\n");
    printf("- Letras consecutivas: %d\n", racha_max_letras);
    printf("- Digitos consecutivos: %d\n", racha_max_digitos);

    printf("Índice de equilibrio (IE): %.2f\n", ie);

    return 0;
}

/* ---- Implementación de funciones ---- */
int es_vocal(char car) {
    car = tolower(car);
    return car == 'a' || car == 'e' || car == 'i' || car == 'o' || car == 'u';
}

float porcentaje(int parte, int total) {
    if (total == 0) return 0;
    return ((float)parte / total) * 100;
}

float indice_equilibrio(int vocales, int consonantes) {
    int suma = vocales + consonantes;
    if (suma == 0) return 0.00;
    return fabs((float)(vocales - consonantes) / suma);
}

void imprimir_conteos(int mayus, int minus, int letras, int vocales, int consonantes, int digitos, int espacios, int total_car) {
    printf("--- Resumen ---\n");
    printf("Mayusculas: %d\n", mayus);
    printf("Minusculas: %d\n", minus);
    printf("Letras totales: %d\n", letras);
    printf("Vocales: %d\n", vocales);
    printf("Consonantes: %d\n", consonantes);
    printf("Digitos: %d\n", digitos);
    printf("Espacios: %d\n", espacios);
    printf("Caracteres leidos (sin el punto final): %d\n", total_car);
}
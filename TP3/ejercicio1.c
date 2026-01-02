#include <stdio.h>
#include <stdbool.h>

int main() {
    // Declaración de variables
    int numero, copiaNumero, digito, contadorDigitos = 0, contadorPrimos = 0, sumaPrimos = 0, sumaImpares = 0;
    bool esPrimo;

    // Entrada de datos
    printf("Ingrese un numero entero entre 10 y 999999: ");
    scanf("%d", &numero);

    // Validar que el número esté en el rango
    while (numero < 10 || numero > 999999) {
        printf("Numero fuera de rango. Ingrese un numero entre 10 y 999999: ");
        scanf("%d", &numero);
    }

    // Inicializar copia del número
    copiaNumero = numero;

    // Procesar cada dígito
    while (copiaNumero > 0) {
        // Extraer el último dígito
        digito = copiaNumero % 10;
        copiaNumero = copiaNumero / 10;
        contadorDigitos++;

        // Verificar si el dígito es primo (2, 3, 5, 7)
        if (digito == 2 || digito == 3 || digito == 5 || digito == 7) {
            contadorPrimos++;
            sumaPrimos += digito;
        }

        // Verificar si el dígito es impar
        if (digito % 2 != 0) {
            sumaImpares += digito;
        }
    }

    // Mostrar resultados
    printf("\nNumero ingresado: %d\n", numero);
    printf("Cantidad de digitos: %d\n", contadorDigitos);
    printf("Cantidad de digitos primos: %d\n", contadorPrimos);
    printf("Suma de digitos primos: %d\n", sumaPrimos);
    printf("Suma de digitos impares: %d\n", sumaImpares);

    return 0;
}
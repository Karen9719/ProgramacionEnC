#include <stdio.h>
#include <ctype.h>

int cantPares(int arreglo[], int tama);
void ordenAscendente(int arreglo[], int tama);

int main(){
    int tama;
    int cantIngreso = 0;

    // Validación de tamaño, suponemos que el usuario solo puede ingresar numeros, contempla el caso de los negativos
    printf("Ingrese la cantidad de terminos a generar (tamaño del arreglo): \n");
    scanf("%d", &tama);
    while (tama <= 0) {
        cantIngreso++;
        if (cantIngreso == 3) {
            printf("Supero los intentos permitidos, ejecute nuevamente el programa.\n");
            return 1;
        } else {
            printf("El numero ingresado no es valido, ingrese nuevamente: ");
            scanf("%d", &tama);
        }
    }

    int arreglo[tama];

    // Genero el arreglo
    for (int i = 0; i < tama; i++) {
        arreglo[i] = (i + 1) * (i + 1);
    }

    // Muestro el arreglo original
    printf("Arreglo generado: ");
    for (int i = 0; i < tama; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    // Ordeno el arreglo en forma descendente
    int aux;
    for (int i = 0; i < tama - 1; i++) {
        for (int j = i + 1; j < tama; j++) {
            if (arreglo[i] < arreglo[j]) {
                aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
    }

    // Muestro el arreglo descendente
    printf("Arreglo ordenado de forma descendente: ");
    for (int i = 0; i < tama; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    // Muestro el arreglo en forma ascendente usando la función
    ordenAscendente(arreglo, tama);

    // Cantidad de números pares
    int cantidad = cantPares(arreglo, tama);
    printf("Cantidad de numeros pares en el arreglo: %d\n", cantidad);

    return 0;
}

int cantPares(int arreglo[], int tama){
    int cantPares = 0;
    for (int i = 0; i < tama; i++) {
        if (arreglo[i] % 2 == 0) {
            cantPares++;
        }
    }
    return cantPares;
}

void ordenAscendente(int arreglo[], int tama){
    // Copio el arreglo para no modificar el original
    int copia[tama];
    for (int i = 0; i < tama; i++) {
        copia[i] = arreglo[i];
    }

    // Ordeno la copia en forma ascendente
    int aux;
    for (int i = 0; i < tama - 1; i++) {
        for (int j = i + 1; j < tama; j++) {
            if (copia[i] > copia[j]) {
                aux = copia[i];
                copia[i] = copia[j];
                copia[j] = aux;
            }
        }
    }

    printf("Arreglo ordenado de forma ascendente: ");
    for (int i = 0; i < tama; i++) {
        printf("%d ", copia[i]);
    }
    printf("\n");
}
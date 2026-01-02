#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void cargarMatriz(int matriz[MAX][MAX], int dim);
void mostrarMatriz(int matriz[MAX][MAX], int dim, char nombre);
void sumarMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int dim);

int main() {
    int dim;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Ingrese la dimension de la matriz cuadrada (1 a 10): ");
    scanf("%d", &dim);

    if(dim < 1 || dim > MAX) {
        printf("Dimension invalida.\n");
        return 1;
    }

    srand(time(NULL));

    cargarMatriz(A, dim);
    cargarMatriz(B, dim);
    sumarMatrices(A, B, C, dim);

    printf("\nMatriz A:\n");
    mostrarMatriz(A, dim, 'A');
    printf("\nMatriz B:\n");
    mostrarMatriz(B, dim, 'B');
    printf("\nMatriz C = A + B:\n");
    mostrarMatriz(C, dim, 'C');

    return 0;
}

void cargarMatriz(int matriz[MAX][MAX], int dim) {
    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            matriz[i][j] = rand() % 10; // valores aleatorios entre 0 y 9
        }
    }
}

void mostrarMatriz(int matriz[MAX][MAX], int dim, char nombre) {
    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void sumarMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int dim) {
    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
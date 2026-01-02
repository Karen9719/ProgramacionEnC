#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Prototipos
float area_circulo(float r);
float perimetro_circulo(float r);
float diagonal_rectangulo(float a, float b);
float area_triangulo_equi(float s);
float perimetro_triangulo_equi(float s);
float area_poligono_regular(int n, float s);
float perimetro_poligono_regular(int n, float s);
int hojas_necesarias(float area_total, float ancho, float alto);

int main(void) {
    float ancho_hoja, alto_hoja, area_hoja;
    int tipo, n;
    float k, r, a, b, s;
    float area, perimetro, diagonal;
    // Acumuladores
    int cant_circulo = 0, cant_rectangulo = 0, cant_triangulo = 0, cant_poligono = 0;
    float area_circulo_acum = 0, area_rectangulo_acum = 0, area_triangulo_acum = 0, area_poligono_acum = 0;
    float area_total = 0, perimetro_total = 0;

    // Leer dimensiones de la hoja
    printf("Dimensiones de hoja:\nAncho: ");
    scanf("%f", &ancho_hoja);
    printf("Alto: ");
    scanf("%f", &alto_hoja);
    area_hoja = ancho_hoja * alto_hoja;

    // Procesar piezas
    do {
        printf("Tipo de figura (1=Círculo, 2=Rectángulo, 3=Triángulo, 4=Polígono regular, 0=Fin): ");
        scanf("%d", &tipo);
        if (tipo == 0) break;

        printf("Escala k: ");
        scanf("%f", &k);
        if (k <= 0) k = 1;

        switch (tipo) {
            case 1: // Círculo
                printf("Radio r: ");
                scanf("%f", &r);
                area = area_circulo(r) * k * k;
                perimetro = perimetro_circulo(r) * k;
                printf("CÍRCULO\nr=%.3f k=%.3f\nÁrea=%.3f Perímetro=%.3f\n", r, k, area, perimetro);
                cant_circulo++;
                area_circulo_acum += area;
                area_total += area;
                perimetro_total += perimetro;
                break;
            case 2: // Rectángulo
                printf("Base a: ");
                scanf("%f", &a);
                printf("Altura b: ");
                scanf("%f", &b);
                area = a * b * k * k;
                perimetro = 2 * (a + b) * k;
                diagonal = diagonal_rectangulo(a, b) * k;
                printf("RECTÁNGULO\na=%.3f b=%.3f k=%.3f\nÁrea=%.3f Perímetro=%.3f Diagonal=%.3f\n", a, b, k, area, perimetro, diagonal);
                cant_rectangulo++;
                area_rectangulo_acum += area;
                area_total += area;
                perimetro_total += perimetro;
                break;
            case 3: // Triángulo equilátero
                printf("Lado s: ");
                scanf("%f", &s);
                area = area_triangulo_equi(s) * k * k;
                perimetro = perimetro_triangulo_equi(s) * k;
                printf("TRIANG. EQUILÁTERO\ns=%.3f k=%.3f\nÁrea=%.3f Perímetro=%.3f\n", s, k, area, perimetro);
                cant_triangulo++;
                area_triangulo_acum += area;
                area_total += area;
                perimetro_total += perimetro;
                break;
            case 4: // Polígono regular
                printf("Número de lados n (>=3): ");
                scanf("%d", &n);
                printf("Lado s: ");
                scanf("%f", &s);
                if (n < 3) {
                    printf("Cantidad de lados inválida.\n");
                    break;
                }
                area = area_poligono_regular(n, s) * k * k;
                perimetro = perimetro_poligono_regular(n, s) * k;
                printf("POLÍGONO REGULAR\nn=%d s=%.3f k=%.3f\nÁrea=%.3f Perímetro=%.3f\n", n, s, k, area, perimetro);
                cant_poligono++;
                area_poligono_acum += area;
                area_total += area;
                perimetro_total += perimetro;
                break;
            default:
                printf("Tipo inválido.\n");
                break;
        }
    } while (tipo != 0);

    // RESUMEN FINAL
    printf("== RESUMEN ==\n");
    printf("Piezas por tipo y area acumulada:\n");
    printf("- Circulo: %d Área=%.3f\n", cant_circulo, area_circulo_acum);
    printf("- Rectángulo: %d Área=%.3f\n", cant_rectangulo, area_rectangulo_acum);
    printf("- Triángulo: %d Área=%.3f\n", cant_triangulo, area_triangulo_acum);
    printf("- Polígono: %d Área=%.3f\n", cant_poligono, area_poligono_acum);
    printf("Acumulados:\n");
    printf("- Área total: %.3f m^2\n", area_total);
    printf("- Perímetro total: %.3f m\n", perimetro_total);
    printf("Hoja estándar: ancho=%.3fm alto=%.3fm (área=%.3f m^2)\n", ancho_hoja, alto_hoja, area_hoja);

    int hojas = hojas_necesarias(area_total, ancho_hoja, alto_hoja);
    float sobrante = hojas * area_hoja - area_total;
    printf("Hojas necesarias: %d\n", hojas);
    printf("Sobrante estimado: %.3f m^2\n", sobrante);

    return 0;
}

// Implementación de funciones
float area_circulo(float r) {
    return PI * r * r;
}
float perimetro_circulo(float r) {
    return 2 * PI * r;
}
float diagonal_rectangulo(float a, float b) {
    return sqrtf(a * a + b * b);
}
float area_triangulo_equi(float s) {
    return (sqrtf(3) / 4) * s * s;
}
float perimetro_triangulo_equi(float s) {
    return 3 * s;
}
float area_poligono_regular(int n, float s) {
    float angulo = PI / n;
    return (n * s * s) / (4 * tanf(angulo));
}
float perimetro_poligono_regular(int n, float s) {
    return n * s;
}
int hojas_necesarias(float area_total, float ancho, float alto) {
    float area_hoja = ancho * alto;
    if (area_hoja == 0) return 0;
    return (int)ceilf(area_total / area_hoja);
}
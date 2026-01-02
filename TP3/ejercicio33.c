#include <stdio.h>
#include <stdbool.h>

int main() {
    // Declaración de variables
    int billetes1000, billetes2000, billetes10000, billetes20000;
    int monto, totalRetiros = 0, dineroEntregado = 0;
    int cant1000, cant2000, cant10000, cant20000;
    long dineroDisponible;
    char continuar;
    bool cajeroVacio = false;

    // Carga inicial de billetes
    printf("Ingrese cantidad de billetes de 1000: ");
    scanf("%d", &billetes1000);
    printf("Ingrese cantidad de billetes de 2000: ");
    scanf("%d", &billetes2000);
    printf("Ingrese cantidad de billetes de 10000: ");
    scanf("%d", &billetes10000);
    printf("Ingrese cantidad de billetes de 20000: ");
    scanf("%d", &billetes20000);

    // Validar que las cantidades no sean negativas
    while (billetes1000 < 0 || billetes2000 < 0 || billetes10000 < 0 || billetes20000 < 0) {
        printf("Error: Las cantidades no pueden ser negativas. Ingrese nuevamente.\n");
        printf("Ingrese cantidad de billetes de 1000: ");
        scanf("%d", &billetes1000);
        printf("Ingrese cantidad de billetes de 2000: ");
        scanf("%d", &billetes2000);
        printf("Ingrese cantidad de billetes de 10000: ");
        scanf("%d", &billetes10000);
        printf("Ingrese cantidad de billetes de 20000: ");
        scanf("%d", &billetes20000);
    }

    // Calcular dinero disponible
    dineroDisponible = billetes1000 * 1000 + billetes2000 * 2000 + billetes10000 * 10000 + billetes20000 * 20000;

    // Procesar retiros
    do {
        printf("\n¿Desea realizar un retiro? (S/N): ");
        scanf(" %c", &continuar);
        if (continuar == 'S' || continuar == 's') {
            // Verificar si hay dinero disponible
            if (dineroDisponible == 0) {
                printf("El cajero se quedó sin dinero.\n");
                cajeroVacio = true;
            } else {
                printf("Ingrese el monto a retirar (múltiplo de 1000): ");
                scanf("%d", &monto);

                // Validar que el monto sea múltiplo de 1000
                while (monto % 1000 != 0) {
                    printf("Error: El monto debe ser múltiplo de 1000. Ingrese otro monto: ");
                    scanf("%d", &monto);
                }

                // Verificar si hay suficiente dinero
                if (monto > dineroDisponible) {
                    printf("Error: No hay suficiente dinero en el cajero.\n");
                } else {
                    // Inicializar contadores de billetes a entregar
                    cant20000 = cant10000 = cant2000 = cant1000 = 0;
                    int montoRestante = monto;

                    // Intentar con billetes de 20000
                    cant20000 = (montoRestante / 20000 < billetes20000) ? montoRestante / 20000 : billetes20000;
                    montoRestante -= cant20000 * 20000;

                    // Intentar con billetes de 10000
                    cant10000 = (montoRestante / 10000 < billetes10000) ? montoRestante / 10000 : billetes10000;
                    montoRestante -= cant10000 * 10000;

                    // Intentar con billetes de 2000
                    cant2000 = (montoRestante / 2000 < billetes2000) ? montoRestante / 2000 : billetes2000;
                    montoRestante -= cant2000 * 2000;

                    // Intentar con billetes de 1000
                    cant1000 = (montoRestante / 1000 < billetes1000) ? montoRestante / 1000 : billetes1000;
                    montoRestante -= cant1000 * 1000;

                    // Verificar si se puede entregar el monto exacto
                    if (montoRestante == 0) {
                        // Actualizar stock
                        billetes20000 -= cant20000;
                        billetes10000 -= cant10000;
                        billetes2000 -= cant2000;
                        billetes1000 -= cant1000;
                        dineroDisponible -= monto;
                        totalRetiros++;
                        dineroEntregado += monto;

                        // Mostrar desglose
                        printf("Retiro exitoso. Desglose de billetes:\n");
                        printf("Billetes de 20000: %d\n", cant20000);
                        printf("Billetes de 10000: %d\n", cant10000);
                        printf("Billetes de 2000: %d\n", cant2000);
                        printf("Billetes de 1000: %d\n", cant1000);
                    } else {
                        printf("Error: No se puede entregar el monto con los billetes disponibles.\n");
                    }
                }
            }
        }
    } while ((continuar == 'S' || continuar == 's') && !cajeroVacio);

    // Mostrar resumen final
    printf("\nRESUMEN FINAL\n");
    printf("Cantidad total de retiros realizados: %d\n", totalRetiros);
    printf("Dinero total entregado: %d\n", dineroEntregado);
    printf("Stock final de billetes:\n");
    printf("Billetes de 1000: %d\n", billetes1000);
    printf("Billetes de 2000: %d\n", billetes2000);
    printf("Billetes de 10000: %d\n", billetes10000);
    printf("Billetes de 20000: %d\n", billetes20000);
    if (cajeroVacio) {
        printf("El cajero se quedó sin dinero.\n");
    } else {
        printf("Simulación terminada por decisión del usuario.\n");
    }

    return 0;
}
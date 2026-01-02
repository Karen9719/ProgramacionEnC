#include <stdio.h>

int main() {
    //CONSTANTES
    const float IVA=0.21;

    //VARIABLES
    float consumo;
    int categoria, metodoPago;
    float subTotal, subTotalIVA, monto, totalAPagar;
    

    printf("Ingrese el consumo del cliente:");
    scanf("%f", &consumo);

    printf("Ingrese la categoria del cliente (1, 2 o 3):\n");
    printf("1.Hogar\n");
    printf("2.Comercio\n");
    printf("3.Industria\n");
    scanf("%d", &categoria);

    printf("Ingrese el metodo de pago del cliente (1, 2 o 3):\n");
    printf ("1.Efectivo\n");
    printf("2.Tarjeta\n");
    printf("3.Débito\n");
    scanf("%d", &metodoPago);

    //Estructura SEGUN para determinar el subtotal segun la categoria
    switch (categoria){
        case 1: 
        if(consumo<=20){
            monto = (consumo*45)+1200;
        }else{
            monto = (20*45)+((consumo-20)*70)+1200;
        }
            break;
        case 2:
        if (consumo<=50){
            monto= (consumo*60)+3000;
        }else{
            monto = (50*60)+((consumo-50)*95)+3000;
        }
            break;
        case 3:
        monto = (consumo*130)+7500;
            break;
        default:
            printf("Categoria invalida.\n");
            return 1;
    }
    subTotal = monto;
    if(consumo>=120){
        subTotal = monto * 1.02;
    }
    subTotalIVA = subTotal*(1+IVA);

    switch (metodoPago){
        case 1: totalAPagar = subTotalIVA -(subTotalIVA*0.04);
            break;
        case 2: totalAPagar = subTotalIVA * 1.015;
            break;
        case 3: totalAPagar = subTotalIVA; 
            break;
        default:
            printf("Metodo de pago invalido.\n");
            return 1;
    }

    printf("Monto final sin IVA:%.2f\n", subTotal);
    printf("Monto final con IVA:%.2f\n", subTotalIVA);
    printf("Total a pagar segun metodo de pago:%.2f\n", totalAPagar);

    return 0;
}
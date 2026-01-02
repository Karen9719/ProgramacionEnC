#include <stdio.h>
#include <ctype.h>

/* ---- Prototipos exigidos ---- */
float monto_item(int categoria, int cantidad, float precio_unidad);
void mostrar_item(int categoria, int cantidad, float precio_unidad, float monto);
float total_con_medio_pago(char medio, int cuotas, float total);
int validacion(int categoria, int cantidad, float precio_unidad);
void mostrar_menu_categorias(void);

/* ---- Programa principal ---- */
int main(void) { 
    /* Declarar Entradas */
    int categoria, cantidad, cuotas;
    float precio_unidad;
    char medio;
    medio = toupper(medio);
    /* Declarar e inicializar acumuladores por categoría (unidades y montos) */
    float monto1 = 0, monto2 = 0, monto3 = 0, monto4 = 0, monto5 = 0;
    int unidades1 = 0, unidades2 = 0, unidades3 = 0, unidades4 = 0, unidades5 = 0;
    /* Declarar salidas */
    float monto, precioFinalVenta;
    int totalProductos;

    /* Variables auxiliares */
    int control = 0;

    /* Programar función para mostrar el menú */
    mostrar_menu_categorias();

    /* LEER LAS ENTRADAS */
    printf("\ningrese categoria (0 para cerrar): ");
    scanf("%d", &categoria);
    printf("\nIngrese la cantidad de productos: ");
    scanf("%d", &cantidad);
    printf("\nIngrese el precio del producto: ");
    scanf("%f", &precio_unidad);

    control = validacion(categoria, cantidad, precio_unidad);
    while(control == 1) {
        /* Calcular y mostrar ítem */
        monto = monto_item(categoria, cantidad, precio_unidad);
        mostrar_item(categoria, cantidad, precio_unidad, monto);

        /* Acumular por categoría */
        switch (categoria) {
            case 1:
                unidades1 += cantidad;
                monto1 += monto;
                break;
            case 2:
                unidades2 += cantidad;
                monto2 += monto;
                break;
            case 3:
                unidades3 += cantidad;
                monto3 += monto;
                break;
            case 4:
                unidades4 += cantidad;
                monto4 += monto;
                break;
            case 5:
                unidades5 += cantidad;
                monto5 += monto;
                break;
            default:
                break;
        }
        /* Acumular totales */
        totalProductos = unidades1 + unidades2 + unidades3 + unidades4 + unidades5;

        /* LEER - Nueva lectura dentro del while */
        printf("\ningrese categoria (0 para cerrar): ");
        scanf("%d", &categoria);
        if(categoria == 0) break;
        printf("\nIngrese la cantidad de productos: ");
        scanf("%d", &cantidad);
        printf("\nIngrese el precio del producto: ");
        scanf("%f", &precio_unidad);
        control = validacion(categoria, cantidad, precio_unidad);
    }

    monto = monto1 + monto2 + monto3 + monto4 + monto5;

    /* Aplicar Medio de pago */
    printf("Ingrese el medio de pago ('C' para credito, 'D' para debito, 'E' para efectivo o transferencia): ");
    scanf(" %c", &medio);
    medio = toupper(medio);
    if(medio == 'C'){
        printf("Ingrese la cantidad de cuotas (1, 3, 6, 12): ");
        scanf("%d", &cuotas);
    } else {
        cuotas = 1;
    }
    precioFinalVenta = total_con_medio_pago(medio, cuotas, monto);

    /* Mostrar Resumen final */
    printf("\n--Total de la venta:--\n");
    printf("1-Alimentos: Unidades=%d Monto=$%.2f\n", unidades1, monto1);
    printf("2-Limpieza: Unidades=%d Monto=$%.2f\n", unidades2, monto2);
    printf("3-Perfumería: Unidades=%d Monto=$%.2f\n", unidades3, monto3);
    printf("4-Bebidas s/alcohol: Unidades=%d Monto=$%.2f\n", unidades4, monto4);
    printf("5-Bebidas c/alcohol: Unidades=%d Monto=$%.2f\n", unidades5, monto5);
    printf("Total de productos: %d\n", totalProductos);
    printf("Precio final de la venta: $%.2f\n", monto);
    printf("Medio de pago: ");
    switch(medio){
        case 'C': printf("Crédito\n"); break;
        case 'D': printf("Débito\n"); break;
        case 'T':printf("Transferencia\n"); break;
        case 'E': printf("Efectivo\n"); break;
        default: printf("Desconocido\n"); break;
    }
    printf("Precio final según medio pago: $%.2f\n", precioFinalVenta);
    return 0;
}

/* ---- DEFINIR LAS FUNCIONES ---- */
void mostrar_menu_categorias(void){
    printf("CATEGORIAS: \n");
    printf("1-Alimentos.\n2-Limpieza.\n3-Perfumería.\n4-Bebidas s/alcohol.\n5-Bebidas c/alcohol.\n");
}

int validacion(int categoria, int cantidad, float precio_unidad){
    if(categoria<=0 || categoria>5 || cantidad<=0 || precio_unidad <=0){
        return 0;
    }else{
        return 1;
    }
}

float monto_item(int categoria, int cantidad, float precio_unidad){
    float monto = 0;
    switch (categoria){
        case 1: // Alimentos: 3x2
            monto = precio_unidad * (cantidad - cantidad / 3);
            break;
        case 2: { // Limpieza: segunda unidad al 50%
            int pares = cantidad / 2;
            int impares = cantidad % 2;
            monto = pares * (precio_unidad + precio_unidad * 0.5) + impares * precio_unidad;
            break;
        }
        case 3: // Perfumería: 5% de descuento
            monto = cantidad * (precio_unidad * 0.95);
            break;
        case 4: // Bebidas sin alcohol: sin promoción
            monto = cantidad * precio_unidad;
            break;
        case 5: // Bebidas con alcohol: 5% de recargo
            monto = cantidad * precio_unidad * 1.05;
            break;
    }
    return monto;
}

void mostrar_item(int categoria, int cantidad, float precio_unidad, float monto){
    printf("\nCategoría: %d\nCantidad: %d\nPrecio unidad: $%.2f\nTotal: $%.2f\n", categoria, cantidad, precio_unidad, monto);
}

float total_con_medio_pago(char medio, int cuotas, float total){
    float precioFinalVenta = total;
    if(medio=='C'){
        switch(cuotas){
            case 1:
                break;
            case 3:
                precioFinalVenta += total * 0.10;
                break;
            case 6:
                precioFinalVenta += total * 0.25;
                break;
            case 12:
                precioFinalVenta += total * 0.60;
                break;
            default:
                printf("Cuotas no válidas. Se aplica precio de lista.\n");
                break;
        }
    }else if(medio=='D'){
        // Débito: sin descuento ni recargo
        precioFinalVenta = total;
    }else if (medio=='E' || medio =='T'){
        precioFinalVenta -= total * 0.15;
    }else {
        printf("Medio de pago no válido. Se aplicará el total sin descuento.\n");
    }
    return precioFinalVenta;
}
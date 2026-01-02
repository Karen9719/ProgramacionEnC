#include <stdio.h>
#include <ctype.h>

/* ---- Prototipos exigidos ---- */
float monto_item(int categoria, int cantidad, float precio_unidad);
void mostrar_item(int categoria, int cantidad, float precio_unidad, float precio_cantidad);
float total_con_medio_pago(char medio, int cuotas, float total);
int validacion(int categoria, int cantidad, float precio);
void mostrar_menu_categorias(void);

/* ---- Programa principal ---- */
int main(void) {
    /* Declarar Entradas */
    int categoria, cantidad;
    float precio_unidad;
    char medio_pago;
    int cuotas;

    /* Declarar e inicializar acumuladores por categoría (unidades y montos) */
    int cantidad_alimentos = 0, cantidad_limpieza = 0, cantidad_perfumeria = 0;
    int cantidad_bebidas_sin = 0, cantidad_bebidas_con = 0;
    float monto_alimentos = 0.0, monto_limpieza = 0.0, monto_perfumeria = 0.0;
    float monto_bebidas_sin = 0.0, monto_bebidas_con = 0.0;

    /* Declarar salidas */
    float monto;
    float total_venta = 0.0;
    int total_productos = 0;

    /* Variables auxiliares */
    int control = 0;

    /* Programar función para mostrar el menú */
    mostrar_menu_categorias();

    /* LEER LAS ENTRADAS */
    scanf("%d", &categoria);
    scanf("%d", &cantidad);
    scanf("%f", &precio_unidad);

    /* Bucle MIENTRAS, validamos las entradas */
    control = validacion(categoria, cantidad, precio_unidad);
    while (control == 1) {
        /* Calcular y mostrar ítem */
        monto = monto_item(categoria, cantidad, precio_unidad);
        mostrar_item(categoria, cantidad, precio_unidad, monto);

        /* Acumular por categoría */
        switch (categoria) {
            case 1: // Alimentos
                cantidad_alimentos += cantidad;
                monto_alimentos += monto;
                break;
            case 2: // Limpieza
                cantidad_limpieza += cantidad;
                monto_limpieza += monto;
                break;
            case 3: // Perfumería
                cantidad_perfumeria += cantidad;
                monto_perfumeria += monto;
                break;
            case 4: // Bebidas sin alcohol
                cantidad_bebidas_sin += cantidad;
                monto_bebidas_sin += monto;
                break;
            case 5: // Bebidas con alcohol
                cantidad_bebidas_con += cantidad;
                monto_bebidas_con += monto;
                break;
        }

        /* Acumular totales */
        total_productos += cantidad;
        total_venta += monto;

        /* LEER - Nueva lectura dentro del while */
        mostrar_menu_categorias();
        scanf("%d", &categoria);
        scanf("%d", &cantidad);
        scanf("%f", &precio_unidad);
        control = validacion(categoria, cantidad, precio_unidad);
    }

    /* Aplicar Medio de pago */
    scanf(" %c", &medio_pago); // Espacio antes de %c para consumir salto de línea
    medio_pago = toupper(medio_pago);
    if (medio_pago == 'C') {
        scanf("%d", &cuotas);
    } else {
        cuotas = 0;
    }

    /* Calcular total con medio de pago */
    total_venta = total_con_medio_pago(medio_pago, cuotas, total_venta);

    /* Mostrar Resumen final */
    printf("Resumen del ticket:\n");
    printf("1-Alimentos: Unidades=%d Monto=$%.2f\n", cantidad_alimentos, monto_alimentos);
    printf("2-Limpieza: Unidades=%d Monto=$%.2f\n", cantidad_limpieza, monto_limpieza);
    printf("3-Perfumería: Unidades=%d Monto=$%.2f\n", cantidad_perfumeria, monto_perfumeria);
    printf("4-Bebidas s/alcohol: Unidades=%d Monto=$%.2f\n", cantidad_bebidas_sin, monto_bebidas_sin);
    printf("5-Bebidas c/alcohol: Unidades=%d Monto=$%.2f\n", cantidad_bebidas_con, monto_bebidas_con);
    printf("--Total de la venta:--\n");
    printf("Total de productos: %d\n", total_productos);
    printf("Precio final de la venta: $%.2f\n", total_venta);
    printf("Medio de pago: ");
    switch (medio_pago) {
        case 'E': printf("Efectivo\n"); break;
        case 'T': printf("Transferencia\n"); break;
        case 'D': printf("Débito\n"); break;
        case 'C': printf("Crédito\n"); break;
        default: printf("Desconocido\n"); break;
    }
    printf("Precio final según medio pago: $%.2f\n", total_venta);

    return 0;
}

/* ---- DEFINIR LAS FUNCIONES ---- */
float monto_item(int categoria, int cantidad, float precio_unidad) {
    switch (categoria) {
        case 1: // Alimentos: 3x2
            return ((cantidad * 2) / 3) * precio_unidad;
        case 2: // Limpieza: segunda unidad al 50%
            return ((cantidad / 2) * 1.5 * precio_unidad) + ((cantidad % 2) * precio_unidad);
        case 3: // Perfumería: 5% descuento
            return cantidad * precio_unidad * 0.95;
        case 4: // Bebidas sin alcohol: sin promoción
            return cantidad * precio_unidad;
        case 5: // Bebidas con alcohol: 5% recargo
            return cantidad * precio_unidad * 1.05;
        default:
            return 0.0; // Caso inválido
    }
}

void mostrar_item(int categoria, int cantidad, float precio_unidad, float precio_cantidad) {
    printf("Categoría:%d Cantidad:%d Precio unidad: $%.2f Total: $%.2f\n",
           categoria, cantidad, precio_unidad, precio_cantidad);
}

float total_con_medio_pago(char medio, int cuotas, float total) {
    switch (medio) {
        case 'E': // Efectivo: 15% descuento
        case 'T': // Transferencia: 15% descuento
            return total * 0.85;
        case 'D': // Débito: sin ajuste
            return total;
        case 'C': // Crédito: según cuotas
            switch (cuotas) {
                case 1: return total;
                case 3: return total * 1.10;
                case 6: return total * 1.25;
                case 12: return total * 1.60;
                default: return total; // Cuotas inválidas
            }
        default:
            return total; // Medio de pago inválido
    }
}

int validacion(int categoria, int cantidad, float precio) {
    if (categoria < 1 || categoria > 5 || cantidad <= 0 || precio <= 0) {
        return 0;
    }
    return 1;
}

void mostrar_menu_categorias(void) {
    printf("1. Alimentos\n");
    printf("2. Limpieza\n");
    printf("3. Perfumería\n");
    printf("4. Bebidas sin alcohol\n");
    printf("5. Bebidas con alcohol\n");
}
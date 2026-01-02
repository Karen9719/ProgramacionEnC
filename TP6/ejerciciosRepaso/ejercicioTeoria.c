#include <stdio.h>
#define cte 10.0

float modificarPrecio(float *Insumo1, float *Insumo2);

int main(){
    float Insumo1, Insumo2, precioProd;

    printf("Ingrese el precio del Insumo 1: \n");
    scanf("%f", &Insumo1);//devuelvo la direccion modificada

    printf("Ingrese el precio del Insumo 2: \n");
    scanf("%f", &Insumo2);

    // 2. Llamada a la función con Pasaje por Referencia
    // Se pasa la DIRECCIÓN (&) de las variables Insumo1 e Insumo2.
    precioProd = modificarPrecio(&Insumo1, &Insumo2);

    printf("Insumo 1 modificado (3%% de aumento) es: %.2f \n", Insumo1); //ya estan modificadas porque pasaron por la funcion 
    printf("Insumo 2 modificado (5%% de aumento) es: %.2f \n", Insumo2);
    printf("El nuevo precio del producto (Insumo1 + Insumo2 + %.2f) es: %.2f \n", cte, precioProd);
    return 0;
}
float modificarPrecio(float *Insumo1, float *Insumo2){//la funcion indica que recibe como parametro las DIRECCIONES de las variables a modificar o utilizar

    float precioProd;
    // El operador * (indirección) se usa para ACCEDER y MODIFICAR el valor 
    // almacenado en la dirección de memoria apuntada.
    *Insumo1 = *Insumo1 * 1.03;//incrementa el valor original de Insumo1 en la funcion
    *Insumo2 = *Insumo2* 1.05;//incrementa el valor original de Insumo2 en la funcion

    //se calcula precioProd con los valores ya modificados
    precioProd= *Insumo1 + *Insumo2 +cte;

    return(precioProd); //devuelve un valor (precioProd)
}
/*Dentro de la función: Al usar *Insumo1 y *Insumo2 (operador de indirección)
se accede al valor de las variables originales de main.
La asignación *Insumo1 = *Insumo1 * 1.03; 
modifica directamente el valor almacenado en la dirección de memoria de la variable Insumo1 de main. 
Esto permite que la función "devuelva" dos valores modificados (Insumo1 e Insumo2)
además del valor retornado explícitamente (precioProd).*/
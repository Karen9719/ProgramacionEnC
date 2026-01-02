//EJERCICIO VERSION 2, TRABAJAMOS CON PUNTEROS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct
{
    char modelo[MAX];
    float precio;
}typedef producto;

struct
{
    char marca[MAX];
    char categoria[MAX];
    int stock;
    producto *disponibles; //para que se cargue la cantidad de productos segun el stock, si ingreso stock de 4 celulares se deberian cargar los modelos y precios de los 4 celulares que tengo en stock
}typedef venta;

void mostrarProductos(venta producto);
int main (){
    venta articulo;

    printf("Ingrese la marca del producto: ");
    gets(articulo.marca);
    printf("Ingrese la categoria del producto: ");
    gets(articulo.categoria);
    printf("Ingrese el stock: ");
    scanf("%d", &articulo.stock);
    fflush(stdin);

    articulo.disponibles = (producto*)malloc(articulo.stock*(sizeof(producto)));//el puntero definido dentro de la estructura producto, lo utilizaremos para realizar una reserva dinamica de memoria, esto nos permitira cargar la cantidad de productos segun el stock cargado

    for(int i=0; i<articulo.stock;i++){
        printf("Ingrese el modelo del producto: ");
        gets(articulo.disponibles[i].modelo);
        fflush(stdin);
        printf("Ingrese el precio del producto: ");
        scanf("%f", &articulo.disponibles[i].precio);
        fflush(stdin);
    }
    mostrarProductos(articulo);
    free(articulo.disponibles);//libero la memoria solicitada
    return 0;
}
void mostrarProductos(venta producto){
    puts("*****MERCADERIA*****");
        printf("MARCA => %s \n", producto.marca);
        printf("categoria: %s \n", producto.categoria);
        printf("STOCK: %d \n", producto.stock);//siempre es 3 por lo definido en la teoria ya que todavia no estamos usando punteros

        printf("----PRODUCTOS DISPONIBLES----\n");
        for (int j=0; j< producto.stock; j++){//acá no deberia de ser 3 en vez de producto.stock? no porque stock por defecto ya es 3
            printf("Modelo: %s\n", producto.disponibles[j].modelo);
            printf("Precio: %.2f\n", producto.disponibles[j].precio);
        }
    puts("------------------------");
}
//VERSION 4. Para que el vendedor cargue distintos productos de distinta marca, este ejemplo es para la cantidad de productos que ingrese el usuario (el anterior era solo para 2 productos de distintas marcas)
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
    producto *disponibles;
}typedef venta;

void mostrarProductos(venta *producto, int cant);
int main (){

    int cantArt;
    printf("Ingrese la cantidad de articulos a cargar: ");
    scanf("%d", &cantArt);

    venta *articulo = (venta*)malloc(cantArt*sizeof(venta));

    for(int j=0; j<cantArt; j++){
        printf("----------ARTICULO--------%d\n", j+1);
        fflush(stdin);
        printf("Ingrese la marca del producto: ");
        gets(articulo[j].marca);
        fflush(stdin);
        printf("Ingrese la categoria del producto: ");
        gets(articulo[j].categoria);
        fflush(stdin);
        printf("Ingrese el stock:");
        scanf("%d",&articulo[j].stock);
        //hago la reserva de memoria dinamica para los articulos disponibles segun el stock
        articulo[j].disponibles = (producto*)malloc(articulo[j].stock* (sizeof(producto)));

        fflush(stdin);
        for(int i=0; i< articulo[j].stock; i++){
            printf("Ingrese el modelo del producto: ");
            gets(articulo[j].disponibles[i].modelo);
            fflush(stdin);
            printf("Ingrese el precio del producto: ");
            scanf("%f", &articulo[j].disponibles[i].precio);
            fflush(stdin);
        }
    }
    mostrarProductos(articulo,  cantArt);
    free(articulo);//libera el puntero de veentas
    return 0;
    
}

void mostrarProductos(venta *producto, int cant){
    puts("-------MERCADERIA----------");
    for (int j = 0; j <cant ; j++)
    {
        printf("MARCA: %s\n", producto[j].marca);
        printf("categoria: %s\n", producto[j].categoria);
        printf("STOCK: %d\n", producto[j].stock);

        puts("------PRODUCTOS DISPONIBLES-------");
        for(int i = 0; i< producto[j].stock; i++){
            printf("Modelo: %s\n", producto[j].disponibles[i].modelo);
            printf("Precio: %f\n", producto[j].disponibles[i].precio);
        }
        puts("---------------------------");
        free(producto[j].disponibles); //se libera la memoria del puntero disponible, asi lo puede utilizar el siguiente producto
    }

}
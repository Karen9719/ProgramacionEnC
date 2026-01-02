//VERSION 1 ASUMIENDO QUE SOLO PODEMOS CARGAR 3 PRODUCTOS POR MARCA
#include <stdio.h>
#define MAX 20

struct{
    char modelo[MAX];
    float precio;
}typedef producto;

struct{
    char marca[MAX];
    char categoria[MAX];
    int stock;
    producto disponibles[3];//en este caso suponemos que solo seran cargados 3 productos por marca
}typedef venta;

void mostrarProductos(venta producto);
int main(){

    venta prod1;

    printf("Ingrese la marca del producto: ");
    gets(prod1.marca);
    printf("Ingrese la categoria del producto: ");
    gets(prod1.categoria);
    printf("Ingrese el stock: ");
    scanf("%d", &prod1.stock);
    fflush(stdin);

    for(int i=0; i<3; i++){
        printf("Ingrese el modelo del producto: ");
        gets(prod1.disponibles[i].modelo);
        fflush(stdin);
        printf("Ingrese el precio del producto: ");
        scanf("%f", &prod1.disponibles[i].precio);
        fflush(stdin);
    }

    mostrarProductos(prod1);
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
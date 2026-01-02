#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    int  capacidad=5, longitud=0;
    char *p_frase, frase;
    
    //asigno memoria al puntero 
    p_frase=malloc(capacidad*sizeof(char));
    
    //pido que el usuario ingrese la frase
    printf("Ingrese una frase, enter para finalizar: \n");

    while( (frase=getchar()) != '\n'){
    if(longitud >=capacidad){//si se cumple la condicion pido mas memoria
            capacidad*=2;
            char *p_nuevo= realloc(p_frase, capacidad*sizeof(char));
            p_frase=p_nuevo;//asigno la nueva memoria al puntero anterior
        };
        p_frase[longitud]=frase;//no importa que acá use indices para asignar la letra al lugar que le toca?
        longitud++;
    }

    printf("Frase ingresada: \n");
    char *p_aux1=p_frase;//use puntero para recorrer la frase, esta bien?
    for(int i=0; i<longitud; i++){
        printf("%c", *p_aux1);
        p_aux1++;
    }
    
    //ahora trabajo con el puntero del arreglo destino
    char *p_destino;
    p_destino = malloc(longitud*sizeof(char));

    char *p_origen=p_frase;//siempre uso un auxiliar para recorrer el arreglo xq sino pierdo la direccion?
    char *p_destino_lectura=p_destino;//siempre uso un puntero auxiliar para modificar el arreglo xq pierdo la direccion inicial?
    int j =0;
    while(*p_origen !='\0' ){
        if(*p_origen!=' '){
            if(j % 2 == 0){
                *p_destino_lectura=tolower(*p_origen);
            }else{
                *p_destino_lectura=toupper(*p_origen);
            }
            j++;
            p_destino_lectura++;
        }
    
        p_origen++;
    }
    

    printf("\nLa frase modificada es: \n");
    char *p_aux2=p_destino;
    for(int i=0; i<j; i++){
        printf("%c", *p_aux2);
        p_aux2++;
    }
    free(p_destino);
    free(p_frase);
    return 0;
}
#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>


int main(){
    int  longitud1= 0, capacidad1=5, longitud2= 0;
    char *p_origen, *p_destino, frase;
    char *p_lectura=p_origen, *p_escritura=p_destino;
    
    //asignacion inicial de memoria
    p_origen=(char *)malloc(capacidad1*sizeof(char));

    printf("Ingrese la frase: \n");


    while (( frase = getchar()) != '\n'){// Leer caracter por caracter hasta Enter (\n)
        if(longitud1>=capacidad1){
            capacidad1 *=2;//duplico la capacidad porque la que asige al comienzo es menor a la que esta pidiendo el usuario
            char *nuevo_puntero = (char*)realloc(p_origen, capacidad1*sizeof(char));
            p_origen = nuevo_puntero; //resigno la nueva cantidad de memoria a mi anterior puntero con poca memoria
        }
        p_origen[longitud1]=frase;
        longitud1++;
        
    }
    char *p_aux1=p_origen;
    printf("El contenido del arreglo dinamico es: \n");
    for (int i = 0; i < longitud1; i++)
    {
        printf("%c", *p_aux1);
        p_aux1++;
    }
    
    p_destino=(char *)malloc(capacidad1*sizeof(char)); 
    int i=0;
    while(i<= longitud1){
        
        // Obtener el carácter de p_origen
        frase = p_origen[i];
        
        if(frase !=' '){
            if(longitud2 % 2 != 0){
                frase = toupper(frase);
            }
            p_destino[longitud2]=frase;
            longitud2++;
        }
        i++;
    }
    char *p_aux2=p_destino;
    printf("El contenido del arreglo modificado es: \n");
    for (int i = 0; i < longitud2; i++)
    {
        printf("%c", *p_aux2);
        p_aux2++;
    }
    free(p_destino);
    free(p_origen);

    return 0;
    }
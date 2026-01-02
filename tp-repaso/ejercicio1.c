#include <stdio.h>
#include <ctype.h>

int main(){
    //entradas
    char frase;
    //salidas
    int longitud=0, cantHiatos=0;
    //variables auxiliares
    char MF='.', anterior =' ';

    printf("Ingrese la frase finalizada por un punto(.): ");
    frase = getchar();

    while(frase!=MF){
        longitud = longitud +1;
        if(frase=='a' || frase=='e' || frase=='o'){
            if(frase == anterior){
                cantHiatos= cantHiatos +1;
            }
            if(anterior=='í' || anterior=='ú'){
                cantHiatos= cantHiatos + 1;
            }
        }else{
            if(frase =='ú' || frase=='í'){
                if(anterior=='a' || anterior=='e' || anterior=='o'){
                    cantHiatos=cantHiatos+1;
                }
            }
        }
        anterior=frase;
        frase=getchar();
    }
    printf("Longitud de la frase: %d\n", longitud);
    printf("Cantidad de hiatos: %d\n", cantHiatos);
    return 0;
}
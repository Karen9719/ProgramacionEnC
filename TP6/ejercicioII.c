/*Lea y almacene una frase en minúscula en un arreglo de nombre frase[100].
Cuente las consonantes y conviértelas a mayúsculas.
Use variables punteros para manejar los contadores.*/ 
#include <stdio.h>
#include <ctype.h>

int main (){
    char frase[100]; //arreglo de 100 chars donde se guarda la frase
    char *p_frase; //punteo a char que se usara para recorrer el arreglo
    int contConsonantes = 0;
    int *p_consonantes;
    
    puts("Introducir una frase en minusculas, debe tener hasta 99 caracteres:\n ");
    gets(frase);//Lee una línea desde teclado y la guarda en cadena

    puts("Esta es la nueva frase con consonantes en mayusculas");
    p_frase = frase; // el puntero apunta al inicio del arreglo 'cadena' (Recordá: el nombre del arreglo = dirección del primer elemento)
    p_consonantes = &contConsonantes; //Ahora tienes a p_consonantes vigilando la caja llamada contConsonantes.

    while (*p_frase != '\0'){ //Recorre carácter por carácter hasta llegar al fin de la cadena (el \0 es el terminador de los strings)
        if(*p_frase!= ' ' && *p_frase !='a' && *p_frase != 'e' && *p_frase!='i' && *p_frase != 'o' && *p_frase != 'u'){
            printf("%c", toupper(*p_frase));
            (*p_consonantes)++; //incremento contConsonante mediante puntero
        }else{
            printf("%c",*p_frase);
        }
        p_frase++;//paso a la siguiente direccion de memoria del array
    }
    
    printf("\n La cantidad de consonantes en la frase es: %d\n", *p_consonantes);

    /*1*/char *punt;
    /*2*/ punt = frase; //asigo la primera posicion del arreglo para inicilizar en esa posicion del puntero
        punt = &frase[0];//hace lo mismo que arriba
    
    /*3*/ 
    printf("Direccion de la variable puntero: %p\n", &punt);
    printf("La direccion de la primer componente del arreglo frase es: %p y su contenido:%c \n", punt, *punt);

    /*4*/
    printf("El cuarto elemento del arreglo es: \n");
    //notacion de subindice del arreglo (frase[i])
    printf("Notacion de subindice del arreglo: %c\n", frase[3]);
    //notacion de puntero con desplazamiento mediante punt
    printf("Notacion de puntero con desplazamiento: %c\n", *(punt+3));

    /*5*/
    /*la direccion referenciada por punt+5 es &(punt+5) y el valor almacenado en esa direccion es *(punt+5)
    Al mostrar el valor almacenado en punt+5 el puntero no se movio Para que el puntero se mueva o cambie su valor (es decir, apunte a una nueva ubicación), debes usar un operador de asignación:Asignación: punt = punt + 5;Incremento/Decremento: punt++ o punt--;*/
    printf("Direccion referenciada por punt+5: %p\n", punt+5); //consulta, no me deja usar &(punt+5)
    printf("Valor almacenado en la direccion de punt+5 es: %c\n", *(punt+5)); //consulta

    /*6*/
    printf("Componentes del vector frase: \n");
    //a
    
    printf("Utilizando notación de punteros con el puntero punt: \n");
    while(*punt !='\0'){
        printf("%c\n", *punt);
        punt++;//// ESTA INSTRUCCIÓN MUEVE el puntero 'punt'!
    }
    /*Resultado: Después de este bucle, la variable punt ha sido modificada. Ya no apunta a frase[0], sino que apunta a la posición de memoria que contiene el terminador de cadena (\0).*/
    //b
    printf("Mediante subindices del puntero punt:\n");
    punt = frase; //inicializo de nuevo porque el while anterior me dejo el puntero en la posicion final del arreglo de la frase
    for(int i=0; punt[i]!='\0'; i++){//Dentro de este bucle, el puntero punt se utiliza como la dirección base. El acceso al elemento es a través de la notación de subíndice punt[i].
        printf("%c\n", punt[i]);
    }
    //punt[i] es equivalente a *(punt + i): Esta operación calcula una dirección temporal (punt más el desplazamiento i), pero no modifica el valor almacenado en la variable punt.Por lo tanto el puntero punt no se movio de la componente 0



    return 0;
    
}
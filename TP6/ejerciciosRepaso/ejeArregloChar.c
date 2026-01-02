#include <stdio.h>
#include <ctype.h>

int main (){
    char cadena[80]; //arreglo de 80 chars donde se guarda la frase
    char *p_cadena; //puntero a char que se usara para recorrer el arreglo

    puts("Introducir una cadena en mayuscula");
    gets(cadena);//Lee una línea desde teclado y la guarda en cadena

    puts("Esta es la cadena en minuscula");
    p_cadena = cadena; // el puntero apunta al inicio del arreglo 'cadena' (Recordá: el nombre del arreglo = dirección del primer elemento)

    while (*p_cadena != '\0'){ //Recorre carácter por carácter hasta llegar al fin de la cadena (el \0 es el terminador de los strings)
        printf("%c", tolower(*p_cadena));
        p_cadena++;
    }

    return 0;
}
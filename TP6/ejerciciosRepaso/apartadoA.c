//Escriba un programa que lea dos números enteros y los almacene en las variables a y b.
//Muestre en pantalla los valores leídos en a y b y sus direcciones de memoria

#include <stdio.h>

int main(){
    //declaracion de variables
    int a=5, b=10;
    //declaracion de punteros de dichas variables
    int *p_a, *p_b;
    //asigno la direccion de memoria de las variables a sus respectivos punteros
    p_a=&a;
    p_b=&b;

    
    printf("Valor de a desde la variable: %d\n", a);
    printf("Valor de a desde el puntero: %d\n", *p_a);
    printf("Valor de la direcion de a: %p\n", p_a);

    printf("Valor de b desde la variable: %d\n", b);
    printf("Valor de b desde el puntero: %d\n", *p_b);
    printf("Valor de la direcion de b: %p\n", p_b);

    // Cree dos punteros enteros llamados p y q. Asigne en los punteros p y q la dirección de
    //memoria de a y b respectivamente
    int *p,*q;

    p=&a;
    q=&b;
    //Muestre el contenido de p y q (mostrar las direcciones(punteros))
    printf("Direccion de memoria de a en el puntero *p: %p\n", p);
    printf("Direccion de memoria de b en el puntero *q: %p\n", q);
    //Muestre el contenido apuntado por p y q.
    printf("Contenido apuntado por p: %d\n", *p);
    printf("Contenido apuntado por q: %d\n", *q);
    //Muestre las direcciones de memoria de p y q. (consulta)
    printf("Direccion de memoria de p: %p\n", &a);
    printf("Direccion de memoria de q: %p\n", &b);

    //Lea un número y guárdelo en una variable llamada c. Muestre el contenido de c y la
    //dirección de memoria de la variable c.
    int c;
    printf("Ingrese un numero: \n");
    scanf("%d", &c);

    int *p_c;
    p_c=&c;

    printf("Contenido de la variable c: %d\n", c);
    printf("Direccion de memoria de la variable c:%p\n", &c);

    // Asigne a la variable c el valor de a utilizando el puntero p. Muestre las variables a y c
    c=*p;
    printf("a = %d\n", a); //vale igual porque le estoy asignando el valor predefinido de a mediante el puntero *p
    printf("c = %d\n", c);

    //En la variable c guarde la suma de a+b utilizando los punteros p y q. Muestre las variables
    //a, b y c
    c =*p+*q;
    printf("Contenido de la variable a: %d\n", a);
    printf("Contenido de la variable b: %d\n", b);
    printf("Contenido de la variable c: %d\n", c);

    //¿Qué sucede si ejecutamos *p=*p+1? incrementa en 1 la variable guardada en ese puntero
    *p=*p+1;
    printf("Lo que sucede si ejecutamos *p=*p+1: %d\n", *p);

    //¿Qué sucede si ejecutamos p=p+1? incrementa la direccion del puntero?
    p=p+1;
    printf("Lo que sucede si ejecutamos p=p+1: %p\n", p);

    // Dada la siguiente asignación: p=&a:  ¿Las sentencias *p=*p+1 y *p=a+1 son equivalentes? no, porque una ingrementa el valor de la variable y el otro no
    *p=*p+1;
    printf("valor de la sentencia *p=*p+1: %d\n", *p);
    *p=a+1;
    printf("valor de la sentencia *p=a+1: %d\n", *p);
    
    //Dada la siguiente asignación: p=&a: ¿Las sentencias p=p+1 y p=&a+1 son equivalentes? no
    p=p+1; //corre 4bytes hacia la derecha
    printf("valor de la sentencia p=p+1: %p\n", p);
    p=&a+1;
    printf("valor de la sentencia p=&a+1: %p\n", p);
    return 0;
}
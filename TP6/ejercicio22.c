#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    int longitud1 = 0, capacidad1 = 5, longitud2 = 0;
    char *p_origen, *p_destino, frase;
    
    // Asignación inicial de memoria
    p_origen = (char *)malloc(capacidad1 * sizeof(char)); 
    
    // Usamos un puntero auxiliar para escribir en p_origen y llevar la cuenta de longitud1
    char *p_escritura_origen = p_origen; 

    printf("Ingrese la frase: \n");

    // 1. Lectura de la frase usando punteros y realloc
    while ((frase = getchar()) != '\n'){// Leer caracter por caracter hasta Enter (\n)
        
        if(longitud1 >= capacidad1){
            capacidad1 *= 2;
            char *nuevo_puntero = (char*)realloc(p_origen, capacidad1 * sizeof(char));
            
            // Recalcular la posición del puntero de escritura después del realloc
            p_escritura_origen = nuevo_puntero + longitud1;
            p_origen = nuevo_puntero; 
        }
        
        // Escribir en el arreglo usando el puntero
        *p_escritura_origen = frase; 
        p_escritura_origen++; // Avanzar el puntero de escritura
        longitud1++;          // Incrementar la longitud
    }

    // 2. Impresión del arreglo original usando punteros
    char *p_lectura_aux1 = p_origen;
    printf("\nEl contenido del arreglo dinamico (ORIGEN) es: \n");
    
    // Recorrer hasta la posición (p_origen + longitud1)
    while (p_lectura_aux1 < p_origen + longitud1) 
    {
        printf("%c", *p_lectura_aux1);
        p_lectura_aux1++;
    }
    printf("\n");
    
    // 3. Preparación para el arreglo destino
    // Asignamos memoria inicial (mismo tamaño máximo que el origen)
    p_destino = (char *)malloc(capacidad1 * sizeof(char)); 
    
    // Punteros para el proceso de copia y modificación
    char *p_lectura = p_origen;      
    char *p_escritura_destino = p_destino; 
    int contador_destino = 0;        // Usamos un contador para la lógica par/impar
    
    // 4. Copia, Modificación (Mayúsculas/Minúsculas) y Eliminación de Espacios
    while(p_lectura < p_origen + longitud1){ 
        
        frase = *p_lectura; // Leer el carácter del origen
        
        // Si NO es un espacio
        if(frase != ' '){
            
            // Aplicar la modificación al carácter que SÍ se va a guardar
            // La condición par/impar se aplica al contador_destino (sin contar espacios)
            if(contador_destino % 2 != 0){ 
                frase = (char)toupper((unsigned char)frase); 
            }
            
            // Escribir en el destino usando el puntero
            *p_escritura_destino = frase;
            
            // Avanzar el puntero de escritura y el contador
            p_escritura_destino++;
            contador_destino++;
        }
        
        p_lectura++; // Siempre avanzamos el puntero de lectura del origen
    }
    
    // El valor final de longitud2 es la longitud real del nuevo arreglo sin espacios
    longitud2 = contador_destino; 
    
    // 5. Impresión del arreglo modificado usando punteros
    char *p_lectura_aux2 = p_destino;
    printf("\nEl contenido del arreglo modificado (DESTINO) es: \n");
    
    // Recorrer hasta la nueva posición final (p_destino + longitud2)
    while (p_lectura_aux2 < p_destino + longitud2) 
    {
        printf("%c", *p_lectura_aux2);
        p_lectura_aux2++;
    }
    printf("\n");
    
    // 6. Liberación de memoria
    free(p_destino);
    free(p_origen);

    return 0;
}
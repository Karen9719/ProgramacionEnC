#include <stdio.h>
#include <stdlib.h>

    int main() {
        int *puntero; // declaro un puntero entero, este será la "direccion base" del arreglo dinamico
        int capacidad = 5; //establece un tamaño inicial del bloque de memoria que se va a solicitar 
        int longitud = 0; // lleva la cuenta de cuantos elementos reales ha ingresado el usuario hasta el momento
        int numero; //variable TEMPORAL para almacenar el entero que el usuario ingresa en cada ciclo
        //2.asignacion de memoria
        puntero = (int *)malloc(capacidad * sizeof(int)); //esta linea reserva el primer bloque de memoria en el heap(monticulo/pila)
        //capacidad * sizeof(int): Calcula la cantidad total de bytes necesarios para 5 enteros (ej: $5 \times 4$ bytes = 20 bytes).
        //malloc(...): Solicita ese bloque de memoria al sistema.
        //(int *): Realiza un cast (conversión) para asegurar que la dirección retornada se trate como un puntero a entero.
        printf("Ingrese enteros (0 para finalizar):\n");//Se solicita al usuario que ingrese el primer número.
        scanf("%d", &numero);

        //3.Bucle de Lectura y Crecimiento Dinámico
        while (numero != 0){
            //A. Verificación de Capacidad (Condición de Crecimiento)
            if (longitud >= capacidad){ //Verifica si el arreglo está lleno. Si la cantidad de elementos ingresados (longitud) es igual o mayor a la capacidad actual, es momento de agrandar el arreglo.
                //B. Reasignación (realloc)
               capacidad *= 2; // Duplicar la capacidad (ej: de 5 a 10, de 10 a 20, etc.).
               int *nuevo_puntero = (int *)realloc(puntero, capacidad * sizeof(int));
                /* (realloc):
                Toma la dirección actual del bloque (puntero).
                Toma el nuevo tamaño deseado (capacidad * sizeof(int)).
                Devuelve una nueva dirección de memoria para el bloque agrandado. realloc se encarga de mover y copiar el contenido anterior al nuevo bloque.*/
                puntero = nuevo_puntero; //Se actualiza el puntero principal con la dirección del nuevo bloque de memoria.
            }
            //C.Inserción de Elemento y Avance
            puntero[longitud] = numero;//El número ingresado por el usuario se guarda en la siguiente posición libre del arreglo dinámico.
            longitud++; //Se incrementa el contador de elementos reales.
            printf("Ingrese el siguiente elemento: ");
            scanf("%d", &numero); //Se lee el siguiente número para la próxima iteración del bucle.
        }
        //4. Impresión de Resultados y Liberación
        printf("Elementos ingresados:\n");
        for (int i = 0; i < longitud; i++) { //Se recorre el arreglo dinámico desde el índice 0 hasta el número total de elementos ingresados (longitud), e imprime su contenido.
            printf("%d ", puntero[i]);
        }
        
        free(puntero); //Esta es la línea más importante para el manejo de memoria dinámica. Libera el bloque de memoria asignado por malloc/realloc y lo devuelve al sistema operativo. Si no se llama a free(), ocurre una fuga de memoria.
        return 0;
    }

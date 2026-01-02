  #include <stdio.h>
  #include<stdlib.h>
  #define MAX 5

  void cargarArreglo(int *parce, int cant);
  void mostrarArreglo(int *parre, int cant);

  int main(){
      int cantidad, indice1=0, indice2=0, suma=0, mayor1=0, mayor2=0;
      int *pnum, *psub; //punteros para reserva dinamica

      printf("Ingrese la cantidad de numeros a cargar: ");
      scanf("%d", &cantidad);

      //reserva dinamica para los arreglos
      psub = malloc(sizeof(int)*MAX);
      pnum = malloc(sizeof(int)*cantidad);

      cargarArreglo(pnum, cantidad);
      mostrarArreglo(pnum, cantidad);

      for (int i = 0; i < cantidad; i++) { //busco mayores
          if(mayor1<pnum[i]){
            mayor2=mayor1; //el antiguo mayor pasa a ser el segundo mayor
            mayor1= pnum[i];// El elemento actual es el nuevo mayor1
            indice1 = i;
          }else if(mayor2<pnum[i] && pnum[i] != mayor1){
            mayor2=pnum[i];
            indice2 =i;
          }
      }
      printf("\n MAYOR 1: %d\n", mayor1);
      printf("MAYOR 2: %d\n", mayor2);
      
      suma = mayor1+mayor2;
      printf("Suma de ambos mayores: %d\n", suma);

      //armo el sub arreglo
      psub[0]=mayor1;//consultar si esta bien esto
      psub[1]=mayor2;
      psub[2]=indice1;
      psub[3]=indice2;
      psub[4]=suma;

      printf("\n-------------------DATOS DE SALIDA---------.-------------------\n");
      mostrarArreglo(psub, 5);
      
      //liberamos memoria
      free(psub);
      free(pnum);

    return 0;
  }

  //modulos
  void cargarArreglo(int *parce, int cant){
    for(int i =0; i<cant; i++){
      printf("Ingrese un elemento: \n");
      scanf("%d", &parce[i]); //voy guardando en cada direccion que apunta el puntero los distintos elementos ingresados por el usuario
    }
  }

  void mostrarArreglo(int *parre, int cant){
    int *puntAux = parre;//necesario para luego poder liberar la memoria
    printf("El contenido del arreglo dinamico es: \n");
    for(int i=0; i<cant; i++){//recorre todas las direcciones que apunta el puntero parre, hasta la cantidad determinada
      printf("%d ",*puntAux);
      puntAux++;//pasa a la siguiente direccion
    }
  }
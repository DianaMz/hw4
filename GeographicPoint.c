// Librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int columnas = 744;
int filas = 500;


//int *randcol, *randfil;



float leer()
{
  FILE *mapdata;
  mapdata  = fopen("map_data.txt", "r");

  int l = 1500;
	char buffer[l];
	char *linea, *divlinea;

  float matrix[filas][columnas];

  int i, j;

  while ((linea = fgets(buffer ,sizeof(buffer), mapdata)) != NULL)
  {
    //printf("La variable linea es %s\n", linea);
    divlinea = strtok(linea, " ");
    while (divlinea != NULL)
    {
      //printf("La variable en la posicion %d, %d es:%s\n", i,j,divlinea);
      matrix[i][j] = atoi(divlinea);
      divlinea = strtok(NULL, " ");
      j++;
    }
    j=0;
    i++;
  }
  return matrix;
}



int rand2(int hasta) {
  int randnum = rand() %hasta;

  printf("%d \n", randnum);

  //Genera num aleatorios por columna y por fila
  // srand(time(NULL));
  // int randcol = rand() %columnas;


  int randfil = rand() %filas;


  return randnum;
}


int valormatrix(float matrix, int randcol, int randfil){

  printf("%d\n", matrix[randfil][randcol]);
  return matrix[randfil][randcol];
}

// //Convierte entre los indices (Pointers) de un arreglo lineal y de una matriz
// int pos()
// {
//   int randcol = rand() %columnas;
//   int randfil = rand() %filas;
//     return columnas*randfil + randcol;
// }



int main()
{
  leer();

  rand2();
  // srand48(1);
  //
  // float aa = drand48();
  //
  // printf("%f\n", aa);
  //printf("%f\n", matrix[randfil][randcol]);

  valormatrix(matrix, randcol, randfil);

  return 0;
}

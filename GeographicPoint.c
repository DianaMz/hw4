// Librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int columnas = 744;
int filas = 500;
int dcol = 200;
int dfil = 200;

float *matrix;
//int *randcol, *randfil;



int pos(int fil, int col) {
  //cond periodica para filas
  if (fil < 0) {
    fil = filas + fil;
  }
  if (fil >= filas) {
    fil = fil%filas;
  }

  //cond periodica para columnas
  if (col < 0) {
    col = columnas + col;
  }
  if (col >= columnas) {
    col = col%columnas;
  }


  return columnas*fil + col;
}



void leer()
{
  FILE *mapdata;
  mapdata  = fopen("map_data.txt", "r");

  int l = 1500;
	char buffer[l];
	char *linea, *divlinea;

  matrix = malloc(columnas*filas*sizeof(float));

  int i, j;

  while ((linea = fgets(buffer ,sizeof(buffer), mapdata)) != NULL)
  {
    //printf("La variable linea es %s\n", linea);
    divlinea = strtok(linea, " ");
    while (divlinea != NULL)
    {
      //printf("La variable en la posicion %d, %d es:%s\n", i,j,divlinea);
      matrix[pos(i,j)] = atoi(divlinea);
      divlinea = strtok(NULL, " ");
      j++;
    }
    j=0;
    i++;
  }
}



int rand2(int hasta) {
  srand(time(NULL));
  int randnum = rand() %hasta;

  //printf("%d \n", randnum);

  return randnum;
}



float radio(int fil, int col) {
  int r, i, j;

  for (r = 0; r < filas; r++) {
    for (i = 0; -r < i < r; i++) {
      for (j = 0; -r < j < r; j++) {
        if ( (pow(i, 2.) + pow(j, 2.)) < pow(r, 2) && matrix[pos(i+1,j+1)] ==1 ) {
          return r;
        }
      }
    }
  }
}



int main()
{
  leer();

  // int i,

  // for (i = 0; i < count; i++) {
  //   /* code */
  // }

  // rand2();
  // srand48(1);
  //
  // float aa = drand48();
  //
  // printf("%f\n", aa);
  //printf("%f\n", matrix[randfil][randcol]);

  return 0;
}

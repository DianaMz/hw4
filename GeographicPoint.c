// Librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int columnas = 744;
int filas = 500;

//int *randcol, *randfil;


void leer(void)
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
}



int rand2() {
  int randcol = rand() %columnas;
  int randfil = rand() %filas;

  return randcol, randfil;

  //printf("%d %d\n", randcol, randfil);
}

//Convierte entre los indices (Pointers) de un arreglo lineal y de una matriz
int pos()
{
  int randcol = rand() %columnas;
  int randfil = rand() %filas;
    return columnas*randfil + randcol;
}



int main()
{
  leer();

//  rand2();

  pos();


  return 0;
}

// Librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int columnas = 744;
int filas = 500;



int main() {

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


  //print los num aleatorios generados
  printf("%d %d\n", randcol, randfil);

  //print el valor en la matriz de acuerdo a las posiciones aleatorias
  printf("%f\n", matrix[randfil][randcol]);


  for (i = 0; i < (columnas*filas); i++) {
    //Genera num aleatorios por columna y por fila
    //srand(time(NULL));
    int randcol = rand() %columnas;
    int randfil = rand() %filas;

    if (matrix[randfil][randcol] == 0) {
      printf("%d %d\n", randcol, randfil);
      printf("%f\n", matrix[randfil][randcol]);
    }
  }

  return 0;
}

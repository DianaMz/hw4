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


  for (i = 0; i < (columnas*filas); i++) {
    //Genera num aleatorios por columna y por fila
    srand(time(NULL));
    int randcol = rand() %columnas;
    int randfil = rand() %filas;

    // while (matrix[randfil][randcol] == 0) {
    //   printf("%d %d\n", randcol, randfil);
    //   printf("%f\n", matrix[randfil][randcol]);
    // }
    if (matrix[randfil][randcol] == 0) {
      printf("%d %d %f\n", randcol, randfil, matrix[randfil][randcol]);
      break;
    }
    int r, i, j;

    for (r = 0; r < columnas; r++) {
      for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
          if (pow(matrix[i][j], 2.)+pow(matrix[i][j], 2.) < pow(r, 2.)) {
            matrix[randfil+i][randcol+j];
            printf("hola\n");
          }
        }
      }
    }

  }

  return 0;
}

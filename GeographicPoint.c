// Librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int iteraciones = 1000;

int columnas = 744;
int filas = 500;

int dcol = 120;
int dfil = 120;

float *matrix;

int periodicidad(int indice, int maximo)
{
  if (indice < 0) {
    indice = maximo + indice%maximo;
  }
  if (indice >= maximo) {
    indice = indice%maximo;
  }
  return indice;
}

int pos(int fil, int col) {
  //cond periodica para filas
  fil = periodicidad(fil, filas);

  //cond periodica para columnas
  col = periodicidad(col, columnas);

  return columnas*fil + col;
}



void leer()
{
  FILE *mapdata;
  mapdata  = fopen("map_data.txt", "r");

  int l = 1500;
	char buffer[l];
	char *divlinea;

  matrix = malloc(columnas*filas*sizeof(float));

  int i=0, j=0;

  while ((fgets(buffer, l, mapdata)) != NULL)
  {
    //printf("La variable linea es %s\n", linea);
    divlinea = strtok(buffer, " ");
    while (divlinea != NULL)
    {
      //printf("La variable en la posicion %d, %d es:%s\n", i,j,divlinea);
      matrix[pos(i,j)] = atof(divlinea);
      divlinea = strtok(NULL, " ");
      j++;
    }
    j=0;
    i++;
  }
}



int rand2(int hasta) {
    // srand(time(NULL));
  int randnum = rand() %hasta;

  //printf("%d \n", randnum);

  return randnum;
}



int radio(int fil, int col) {
  int r, i, j;

  for (r = 1; r < filas; r++) {
    for (i = -r; i <= r; i++) {
      for (j = -r; j <= r; j++) {
        if ( (pow(i, 2.) + pow(j, 2.) <= pow(r, 2.)) && (matrix[pos(fil+i, col+j)] == 1 )) {
          return r;
        }
      }
    }
  }
}



int main() {
  srand(time(NULL));

  leer();

  int randfil = rand2(filas);
  int randcol = rand2(columnas);

  int randfil_nuevo, randcol_nuevo, r, r_nuevo;

  while(matrix[pos(randfil, randcol)] == 1)
  {
    randfil = rand2(filas);
    randcol = rand2(columnas);
  }

  r = radio(randfil, randcol);

  int i;

  float alpha, beta;


  int maxfil = 0, maxcol = 0, maxr = 0;

 for (i = 0; i < iteraciones; i++) {
   randfil_nuevo = periodicidad(randfil + (1 - 2*rand()/(float) RAND_MAX)*dfil, filas);
   randcol_nuevo = periodicidad(randcol + (1 - 2*rand()/(float) RAND_MAX)*dcol, columnas);
   while(matrix[pos(randfil_nuevo, randcol_nuevo)] == 1)
   {
     randfil_nuevo = periodicidad(randfil + (1 - 2*rand()/(float) RAND_MAX)*dfil, filas);
     randcol_nuevo = periodicidad(randcol + (1 - 2*rand()/(float) RAND_MAX)*dcol, columnas);
   }
         r_nuevo = radio(randfil_nuevo, randcol_nuevo);
         alpha = exp(-r + r_nuevo);

        //  if (alpha >= 1){
        //    randfil = randfil_nuevo;
        //    randcol = randcol_nuevo;
        //    r = r_nuevo;
        //  }

        //  else{
           beta = rand()/(float) RAND_MAX;
           if(alpha >= beta)
           {
             randfil = randfil_nuevo;
             randcol = randcol_nuevo;
             r = r_nuevo;
           }
        //  }

         if(r > maxr)
         {
           maxr = r;
           maxfil = randfil;
           maxcol = randcol;
         }
  }

  printf("las coordenadas del punto mas alejado son: %f %f\n", maxcol*360.0/columnas-180, 90-maxfil*180.0/filas);
  FILE *archivo;
  archivo = fopen("cadena.txt", "w");
  fprintf(archivo, "%d %d %d \n", maxfil, maxcol, maxr);

  return 0;
}

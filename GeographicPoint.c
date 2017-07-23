// Librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define columnas 477
#define filas 500



//Convierte entre los indices (Pointers) de un arreglo lineal y de una matriz
int pos(int i, int j)
{
    return columnas*i + j;
}

void leer(void)
{
  FILE *mapdata;
  mapdata  = openf("map_data.txt", "r");

  int l = 500;
	char linea_temp[l];
	char *divlinea;

  float matrix[filas][477]

  int i, j;

	for (i = 0; i < columnas; i++)
	{
			fgets(linea_temp, l, coordenadas);
			divlinea = strtok(linea_temp, ",");
			for (j = 0; j < filas; j++)
			{
					if(j != 0)
					{
							matrix[i][j-1] = atof(divlinea);
					}
					divlinea = strtok(NULL, ",");
			}
	}
    //printf("%f\n", matrix);
}

int main()
{
  return 0;
}

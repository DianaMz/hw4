import matplotlib.pyplot as plt
import numpy as np

continentes = np.loadtxt("map_data.txt")
plt.imshow(continentes)

archivo = open("cadena.txt")
linea = archivo.readline()
lat,lon,r = linea.split(" ")[:-1]

circle = plt.Circle((float(lon), float(lat)), float(r), color='w', fill=False)

ax = plt.gca()
ax.add_artist(circle)

plt.xlabel("Longitud")
plt.ylabel("Latitud")
plt.show()

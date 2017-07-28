PuntoNemo.pdf : Plots.py cadena.txt
	python Plots.py

cadena.txt : GeographicPoint.x map_data.txt
	./GeographicPoint.x

GeographicPoint.x : GeographicPoint.c
	gcc GeographicPoint.c -lm -o GeographicPoint.x

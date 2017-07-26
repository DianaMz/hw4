PuntoNemo.pdf : Plots.py circulo.txt
	python Plots.py

circulo.txt : GeographicPoint.x
	./GeographicPoint.x

GeographicPoint.x : GeographicPoint.c
	cc GeographicPoint.c -lm -o GeographicPoint.x

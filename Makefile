all: main.cc Initialisation.cpp Algebre.cpp Fonction.cpp
	g++ -std=c++11 -o run Initialisation.cpp Algebre.cpp Fonction.cpp main.cc

clear:
	rm ./run
	rm ./CommandGnuplot.txt
	rm *.png

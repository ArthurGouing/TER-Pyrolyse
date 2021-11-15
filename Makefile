all: main.cc Initialisation.cpp Algebre.cpp Fonction.cpp
	g++ -std=c++11 -I EigenLibrary/Eigen -o run Initialisation.cpp Fonction.cpp main.cc

clear:
	rm ./run
	rm ./CommandGnuplot.txt
	rm *.png

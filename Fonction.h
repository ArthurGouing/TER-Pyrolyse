#include <string>
#include <vector>
#include "SparseLU"

//using namespace std;

//Sauvegarde dans un fichier les instants t et l'ensemble des cellules
std::string Sauvegarde_tout_le_maillage(std::string name,Eigen::VectorXd& T, int Nx, int Ny, double dx, double dy);

//Sauvegarde dans un fichier les instants t et les cellules qui sont sur la colonne k
std::string Sauvegarde_colonne(std::string name, int k,Eigen::VectorXd& T, int Nx, int Ny, double dy);

//créé le fichier CommandGnuplot.txt pour avoir juste à faire load CommandGnuplot dans CommandGnuplot
//void Fichier_Gnuplot(string name, string cas, int smooth);
void Fichier_Gnuplot(std::string name, int i, int smooth);

//Appel des fonctions: remplissage A et b?
void un_pas_de_temps(Eigen::VectorXd& Tn, double (&phi)(double), double tn,  double dx, std::vector<double> dy,double dt, int Nx, int Ny);
void remplissageA(std::vector<Eigen::Triplet<double>>& triplets,double dx,std::vector<double> dy,double dt, int Nx, int Ny);
//void remplissageb

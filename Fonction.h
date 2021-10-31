# include <string>
# include <vector>
using namespace std; // on sait pas s'il le faut?? on-a-t-on le droit?

//Sauvegarde dans un fichier les instants t et l'ensemble des cellules
string Sauvegarde_tout_le_maillage(string name,vector<double> T, int Nx, int Ny, double dx, double dy);

//Sauvegarde dans un fichier les instants t et les cellules qui sont sur la colonne k
string Sauvegarde_colonne(string name, int k,vector<double> T, int Nx, int Ny, double dy);

//créé le fichier CommandGnuplot.txt pour avoir juste à faire load CommandGnuplot dans CommandGnuplot
//void Fichier_Gnuplot(string name, string cas, int smooth);
void Fichier_Gnuplot(string name, int i, int smooth);

//Appel des fonctions: remplissage A et b?
void un_pas_de_temps(vector<double>& Tn,vector<vector<double>> A, double (&phi)(double), double tn,  double dx, vector<double> dy,double dt, int Nx, int Ny);
void remplissageA(vector<vector<double>>& A,double dx,vector<double> dy,double dt, int Nx, int Ny);
//void remplissageb

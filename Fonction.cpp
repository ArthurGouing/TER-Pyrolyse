# include <iostream>
# include <string>
# include <cmath>
#include <vector>
#include <fstream>
# include "Initialisation.h"
using namespace std;








/*      FONCTION D ECRITURE DANS UN FICHIER     */


//Sauvegarde dans un fichier l'ensemble des cellules pour un instant donné
string Sauvegarde_tout_le_maillage(string name)
{
  ofstream flux;
  string a("Resultat/"+name+".dat");
  flux.open(a); // il faut fermer le flulx ?
  for (size_t i = 0; i < T.size(); i++)  // T en argument ou pas besoin ?
  {
    flux << pos(x) << pos(y) << T(x,y) << endl; //avec un splot, ou map 2D (cas 2D)
  }
  return a
}

//Sauvegarde dans un fichier les cellules qui sont sur la colonne k pour un instant donné
string Sauvegarde_colonne(string name, init k)
{
  ofstream flux;
  string a("Resultat/"+name+".dat");
  flux.open(a); // il faut fermer le flulx ?
  for (i = 0; i < T.size(); i++)
  {
    flux << pos(y) << T(k,y) << endl; // plot classique de  courbe (cas 1D)
  }
  return a;
}

void Fichier_Gnuplot(sting cas)
{
  ofstream flux;
  flux.open("CommandGnuplot.txt")
  if (flux) // il parait qu'il en faut un
  {
    switch (cas)
    {
      case "1D":
      flux << "" << endl;
      break;

      case "2D":
      flux << "" << endl;
      break;
    }
  }
}
// NOTE :(normalement la forme des fonctions y est,
// il faut juste remplir les ce qu il faut dans les flux)





// INITIALISATION ET REMPLISSAGE DE A + UN PAS DE TEMPS 


int Nx(3),Ny(4), i, j; // Nx: nombre de colonnes , Ny: nombre de lignes 
double dx=2., dy=3., dt=1, K=1.; // valeurs simples choisies pour tester le remplissage de A 
vector<vector<double>> A(12, vector<double>(12,0.0));

void un_pas_de_temps(vector<double> Tn,vector<vector<double>> A, double (&phi)(double), double tn,  double dx, double dy,double dt); 
void remplissageA(vector<vector<double>>& A,double dx,double dy,double dt, int Nx, int Ny); 





int main() // Affichage de la matrice pour vérification 
{
  remplissageA(A,dx,dy,dt,Nx,Ny); 


  for (int i=0; i<=A.size()-1; i++)
    {
      for (int j=0; j<=A.size()-1; j++)
	{
	  cout << "  ||  "  << A[i][j] << "  ||  ";
	}
      cout << "\n";
    }

  return 0;
}





void un_pas_de_temps(vector<double> Tn,vector<vector<double>> A, double (&phi)(double), double tn,  double dx, double dy,double dt) // On considère K une variable globale
{
  for (int i=Nx*Ny-Nx+1; i<=Nx*Ny; i++)
    {
      Tn[i]=Tn[i]+(dt/dy)*K*phi(tn+dt)-K*dt/pow(dx,2);
    }
  // Tn=resolutionsystlin(A,Tn);
}





void remplissageA(vector<vector<double>>& A,double dx,double dy,double dt, int Nx, int Ny)
{

  A.resize(Nx*Ny); 
  for (int i=1; i<=A.size()-1; i++)//premiere sous et sur diagonale
    {
      (A[i-1]).resize(Nx,0.0);
      if (i%Nx !=0)
	{
	  A[i-1][i]=-K*dt/pow(dx,2);
	  A[i][i-1]=-K*dt/pow(dx,2);
	}

    }

  for (int i=1; i<=A.size()-Nx; i++) //troisieme sous et sur diagonale 
    {
      A[i-1+Nx][i-1]=-K*dt/pow(dy,2);
      A[i-1][i-1+Nx]=-K*dt/pow(dy,2);
    }

  for (int i=1; i<=A.size(); i++) // diagonale principale 
    {
      if ((i==1) || (i==Nx) || (i==Nx*Ny) || (i==Nx*Ny-Nx+1))
	{
	  A[i-1][i-1]=1.+K*dt*((1./pow(dx,2))+(1./pow(dy,2)));
	}

      else if (((i>=2) && (i<=Nx-1)) || ((i>=Nx*Ny-Nx+2) && (i<=Nx*Ny-1)))
	{
	  A[i-1][i-1]=1.+K*dt*((2/pow(dx,2))+(1./pow(dy,2)));
	}

      else if ((i%Nx==1) || (i%Nx==0))
	{
	  A[i-1][i-1]=1.+K*dt*((1./pow(dx,2))+(2/pow(dy,2)));
	}

      else
	{
	  A[i-1][i-1]=1.+2*K*dt*((1./pow(dx,2))+(1./pow(dy,2)));
	}

    }
}

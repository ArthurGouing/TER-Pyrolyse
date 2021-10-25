# include <iostream>
# include <string>
# include <cmath>
#include <vector>
#include <fstream>
#include <stdio.h>
//# include "Initialisation.h"
#include "Fonction.h"
#include"Algebre.h"
using namespace std;





/*      FONCTION D ECRITURE DANS UN FICHIER   ( PAS TESTER )  */


//Sauvegarde dans un fichier l'ensemble des cellules pour un instant donné
string Sauvegarde_tout_le_maillage(string name , vector<double> T, int Nx, int Ny)
{
  ofstream flux;
  string a("Resultat/"+name+".txt");
  flux.open(a); // il faut fermer le flux ? "REPONSE OUI"
    if (flux)
    {

  for (int i = 0; i < T.size(); i++)  // T en argument ou pas besoin ? "T EN ARGUMENT OUI"
  {
    //cout << i << endl;
    if (i%Nx == 0)
    {
      flux << endl; // il faut sauter une ligne quand on change de lignes pour splot
    }
    flux << /*x : reste de la division i/nx*/ i%Nx << " " << /*y : partie entière de i/ny*/ i/Ny << " "<< T[i] << endl;
      }

  }
    flux.close();
    return a;
}

//Sauvegarde dans un fichier les cellules qui sont sur la colonne k pour un instant donné
string Sauvegarde_colonne(string name, int k,vector<double> T) // utilise T, Nx et Ny
{
  int Nx,Ny;
  ofstream flux;
  string a("Resultat/"+name+".txt");
  flux.open(a); // il faut fermer le flulx ?
  for (int i = 0; i < Ny; i++) // on parcour la colonne k du maillage // verif les derrnier terms
  {
    flux << i << " " << T[k+Nx*i] << endl; // T=(k,i)
  }
  return a;
}

// Créé un fichier de command gnuplot qui affiche la fonction name
//void Fichier_Gnuplot(string name ,string cas, int smooth) // cas = "1D" ou "2D"
void Fichier_Gnuplot(string name ,int i, int smooth) // cas = "1D" ou "2D"
{
  ofstream flux;
    flux.open("CommandGnuplot.txt");
  if (flux) // il parait qu'il en faut un
  {
    switch (i)
    {
      //case "1D":
        case 1:

      flux << "set title 'Titre'" << endl;
      flux << "set xlabel 'Position y'" << endl;
      flux << "set ylabel 'Température'" << endl;
      flux << "plot '"+name+"' using 1:2 with lines" << endl; // plot classique de  courbe (cas 1D)
      break;

      case 2:
      flux << "set term png" << endl;
      flux << "set output 'Resultat.png'" << endl;

      flux << "set view map" << endl; //avec un splot, ou map 2D (cas 2D).
      flux << "set title 'Titre'" << endl;
      flux << "set xlabel 'Position x'" << endl;
      flux << "set ylabel 'Position y'" << endl;
      flux << "set palette rgbformulae 22,13,-31" << endl;
      if (smooth == 1)
      {
        flux << "set pm3d map interpolate 0,0" << endl;
      }
      else
      {
        flux << "set pm3d map" << endl;
      }
      flux << "plot 'Resultat/"+name+".txt' with image " << endl;
      break;
    }
  }
}
// T(x,y) = T(x + Nx*y)




// INITIALISATION ET REMPLISSAGE DE A + UN PAS DE TEMPS


void un_pas_de_temps(vector<double>& Tn,vector<vector<double>> A, double (&phi)(double), double tn,  double dx, vector<double> dy,double dt) // On considère K une variable globale
{
     //Déclaration de Nx et Ny
    int Nx,Ny;
    double K;
  for (int i=Nx*(Ny-1)+1; i<=Nx*Ny; i++)
    {
      Tn[i-1]=Tn[i-1]+(dt/dy[(i-1)/Nx])*K*phi(tn+dt)-K*dt/pow(dx,2);
    }
  // Tn=resolutionsystlin(A,Tn);
    //vector<vector<double>> M(Nx*Ny);
  vector<vector<double>> M; // Matrice abritant L et U.
  vector<double> Tnplusun(Tn.size());
  Decomposition_LU(A,M);
  Resolution_LU(M,Tn,Tnplusun);
  Tn=Tnplusun;
}



void remplissageA(vector<vector<double>>& A,double dx,vector<double> dy,double dt, int Nx, int Ny) 

{
    double K=1.;

  for (int i=1; i<=A.size()-1; i++)//premiere sous et sur diagonale
    {
      if (i%Nx !=0)
    
	{
	  A[i-1][i]=-K*dt/pow(dx,2);
	  A[i][i-1]=-K*dt/pow(dx,2);
	}
    }
  for (int i=1; i<=A.size()-Nx; i++) //troisieme sous et sur diagonale
    {
      A[i-1+Nx][i-1]=-K*dt/pow(dy[(i-1+Nx)/Nx],2);
      A[i-1][i-1+Nx]=-K*dt/pow(dy[(i-1)/Nx],2);
    }
    cout<<"1"<<endl;
  for (int i=1; i<=A.size(); i++) // diagonale principale
    {
      if ((i==1) || (i==Nx) || (i==Nx*Ny) || (i==Nx*Ny-Nx+1))
	{
	  A[i-1][i-1]=1.+K*dt*((1./pow(dx,2))+(1./pow(dy[(i-1)/Nx],2)));
	}

      else if (((i>=2) && (i<=Nx-1)) || ((i>=Nx*Ny-Nx+2) && (i<=Nx*Ny-1)))
	{
	  A[i-1][i-1]=1.+K*dt*((2/pow(dx,2))+(1./pow(dy[(i-1)/Nx],2)));
	}

      else if ((i%Nx==1) || (i%Nx==0))
	{
	  A[i-1][i-1]=1.+K*dt*((1./pow(dx,2))+(2/pow(dy[(i-1)/Nx],2)));
	}

      else
	{
	  A[i-1][i-1]=1.+2*K*dt*((1./pow(dx,2))+(1./pow(dy[(i-1)/Nx],2)));
	}

    }
}











/*int Nx(3),Ny(4), i, j; // Nx: nombre de colonnes , Ny: nombre de lignes
double dx=2., dy=3., dt=1, K=1.; // valeurs simples choisies pour tester le remplissage de A
vector<vector<double>> A(12, vector<double>(12,0.0));*/


/*int main() // Affichage de la matrice pour vérification
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
}*/


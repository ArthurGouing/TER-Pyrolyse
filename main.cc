#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <stdio.h>
#include "SparseLU"   
#include "OrderingMethods"
#include "Initialisation.h" 
#include "Fonction.h"
using namespace Eigen;
using namespace std;

int main()
{

  /*        INITIALISATION        */

  //Init des constantes
  double a(1000.), TA(6000.), rho_v(1500.), rho_p(1000.), tf/*(100.)*/, T_init(283.),C_p(1000.), lambda(1.),lambda_v(1.), K(1./150000), dx(4.*pow(10,-4)), dt(0.1);

  cout << "tf ?" << endl;
  cin >> tf ;

  int Nx(125), Ny(250);
  vector<double> dy(Ny, 4.*pow(10,-5));
  // dy.resize(Ny); //Nx*Ny
  // for(int i=0;i<dy.size();i++)
  //   {
  //     dy[i]=4.*pow(10,-5);
  //   }

  //recalcul de dt
  dt = tf/int(ceil(tf/dt));

  //Init de A
  //vector<vector<double>> A(Nx*Ny,vector<double>(Nx*Ny,0.0));
  SparseMatrix<double> A(Nx*Ny,Nx*Ny);           
  vector<Triplet<double>> triplets; 
  remplissageA(triplets, dx, dy, dt, Nx, Ny);              // pour le remplissage d'une matrice Sparse il y a 
  A.setFromTriplets(triplets.begin(), triplets.end());     //besoin d'utiliser un triplets pour optimisation
  //cout << A << endl;

  //Init du solveur
  SparseLU<SparseMatrix<double>, COLAMDOrdering<int> > solver;
  // Compute the ordering permutation vector from the structural pattern of A
  solver.analyzePattern(A); 
  // Compute the numerical factorization 
  solver.factorize(A);

  //Init de Tn
  VectorXd Tn(Nx*Ny);
  for (int i=0 ; i<Nx*Ny ; i++)
    {
      Tn.coeffRef(i) =293;          //aucune idée de comment remplir ce truc sinon
    }
  //cout << Tn << endl;
  
  VectorXd Tnplusun(Tn.size());


  // On regarde les parametres de base
  cout << "dt : " << dt << endl;
  cout << "dx : " << dx << endl;
  cout << "dy : " << dy[0] << endl;
  cout << "Lx : " << Nx*dx << endl;// Lx est la largeur totale
  cout << "Ly : " << Ny*dy[0] << endl;// ly est la longeur totale
  cout << endl;


  
  /*    CALCUL DE LA SOLUTION     */

  double tn=0;
  for(int i=0;i<tf/dt+dt;i++)
    {
      tn=i*dt;
      un_pas_de_temps(Tn,flux,tn,dx,dy,dt,Nx,Ny);
      Tnplusun = solver.solve(Tn);
      Tn = Tnplusun;
    }

  cout << "temp finale : "<< tf <<endl;
  cout << "temp final réel : "<< tn << endl;


  
  /*       SAVE SOLUTION        */

  string results, name="solution"; //Mettre le nom du fichier
    
  int dimensionsol;
  cout<< "choisissez votre dimension"<<endl;
  cin >> dimensionsol;
  cout << "Pour voir la solution,"<<endl;
  cout << "Ouvrir gnuplot et lancer la commande :"<<endl;
  cout << "load 'CommandGnuplot.txt"<< endl;
  // Test des fonction d'affichage
  // for (int i(0) ; i<Nx*Ny ; i++)
  //   {
  // 	Tn[i] = i+1;
  //   }   
  if (dimensionsol == 1)
    {
      results = Sauvegarde_colonne(name, ceil(Nx/2), Tn, Nx, Ny, dy[0]);
    }
  else if (dimensionsol == 2)
    {
      results = Sauvegarde_tout_le_maillage(name, Tn, Nx, Ny, dx, dy[0]);
    }
  else
    {
      cout << "Ce choix n'est pas possible" << endl;
    }
    
  Fichier_Gnuplot(results,dimensionsol,0);
  
  return 0;
}
                    

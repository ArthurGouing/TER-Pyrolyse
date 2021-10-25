#include <iostream>
# include <iostream>
# include <string>
# include <cmath>
#include <vector>
#include <fstream>
#include "Initialisation.h"
# include "Fonction.h"
#include "Algebre.h"
using namespace std;

int main()
{
    double a(1000.), TA(6000.), rho_v(1500.), rho_p(1000.), tf(100.), T_init(283.),C_p(1000.), lambda(1.),lambda_v(1.), K(1.), dx(4.*pow(10,-4)), dt;
    int Nx(125), Ny(250);
    vector<double> dy;
    dy.resize(Ny); //Nx*Ny
    for(int i=0;i<dy.size();i++)
    {
        dy[i]=4.*pow(10,-5);
    }
    vector<double> x;
   
    int N= int(ceil(tf/dt)); //Nbre d'itération
    // Recalcul de dt
    dt = tf/ N;

    vector<vector<double>> A(Nx*Ny,vector<double>(Nx*Ny,0.0));
    remplissageA( A, dx, dy, dt,Nx, Ny);
    double tn=0;
    vector<double> Tn(Nx*Ny,293.);
   // double phi;
    //cout << "fin initialisation" << endl ;
    for(int i=0;i<N;i++)
    {
        //cout << i << endl;
        tn=i*dt;
        //phi= flux(tn);
        un_pas_de_temps(Tn,A,flux,tn,dx,dy,dt);
        //cout << x[i]<<endl;
    }
    cout <<Tn[5]<<endl;
    int i;
    cout<< "choisissez votre dimension"<<endl;
    cin >> i;
    
    
    string results = "solution";
    cout <<Tn[3]<<endl;
    results = Sauvegarde_tout_le_maillage("solution", Tn, Nx, Ny);
    cout << results << endl ;
    Fichier_Gnuplot("solution",i,0);
    
}
                    

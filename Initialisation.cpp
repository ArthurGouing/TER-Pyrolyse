# include <iostream>
# include <string>
# include <cmath>
#include <vector>
#include <fstream>
# include "Initialisation.h"
using namespace std;




// double T(double t,double x) //Resolution T
// {
//     return 200.+80000*t*(0.01-x);
 
// }





 
// void psi(float psi,int rho_v, int rho_p, float rho(t,x,y))//degré d'avancement de la réaction de pyrolyse
// {
//   psi = (rho_v-rho)/(rho_v-rho_p);
//    }

//  void lambda1(float lambda1,float psi, int lambda_v, int lambda_p) //Conductivité du matériau
//    {
//      lambda1 = (1-psi)*lambda_v+psi*lambda_p;
//    }
 
//  void C_p1 (float C_p1, float rho(t,x,y), float psi, int C_pv, int C_pp)// C_pp et C_pv constantes dépendant du matériau considéré
//    {
//      rho*C_p1 = (1-psi)*rho_v*C_pv+psi*rho_p*C_pp;
//    }



// void Euler(double& y, double tn, double dt, double (&f)(double, double))
// {

//   y=y+dt*f(tn,y);

// }

// double derivee_rho(double t, double& y){
//   for(int i=0;i<N;i++)
//     {
//       double xi=i*dx;
//       return -rho_v*A*((y-rho_p)/(rho_v-rho_p))*exp(-(TA/(200.+80000*t*(0.01-xi))));
//     }
//   return 0;
// }

//rho=x dans notre code


//double rho(double y0, double dt, double y,vector<double> int_vect,vector<double> it_vect)

// int main()
// {
//   double y0=0.;
//   double dt=tf/N;   //Nbre de pts
//   double y=y0;
//   vector<double> int_vect;
//   vector<double> it_vect;
//   for(int i=1; i<=N; i++) { //1000pts
//     double  tn = i*dt;
//     double x= i*dx;
//     int_vect.push_back(tn);
//     Euler(y,tn,dt,derivee_rho);
//     it_vect.push_back(y);
//   }

//   ofstream mon_flux; // Contruit un objet "ofstream"
//   string name_file("ma_solution.txt"); // Le nom de mon fichier
//   mon_flux.open(name_file, ios::out); // Ouvre un fichier appelé name_file
//   if(mon_flux) // Vérifie que le fichier est bien ouvert
//     {
//       // Remplit le fichier
//       for (int i = 0 ; i < N ; i++)
//         {
//           mon_flux << int_vect[i] << " " <<  " " << it_vect[i] << " "  <<endl;
//         }
//     }
//   else // Renvoie un message d’erreur si ce n’est pas le cas
//     {
//       cout << "ERREUR: Impossible d’ouvrir le fichier." << endl;
//     }
//   mon_flux.close(); // Ferme le fichier



//     return 0;

// }


double flux(double t)
{
  if(t<=50.)
    {
      return 10000.*t;
    }
        
  else
    {
      return  500000.-9000.*(t-50.);
    }
}



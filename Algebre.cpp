#include <iostream>
#include <vector>

using namespace std;


//fonction permettant l'affichage d'une matrice dans le terminal
void Display_matrice(vector<vector<double>> M)
{
  for (int i=0 ; i< M.size() ; i++)
    {
      for (int j=0 ; j< M.size() ; j++)
	{
	  cout << M[i][j] << " " ;
	}
      cout << endl;
    }
}

//fonction permettant l'affichage d'un vecteur dans le terminal
void Display_vect(vector<double> x)
{
  for (int i=0 ; i< x.size() ; i++)
    {
	  cout << x[i] << endl;
    }
}
  


// fonction renvoyant la decomposition LU de la matrice A dans une matrice M avec L trouvée sous sa diagonale et U au dessus de la diag incluse.
void Decomposition_LU(vector<vector<double>> A , vector<vector<double>> &M) 
{
  int n = A.size()-1;
  M=A;
  for (int k=0 ; k < n ; k++)
    {
      for (int i = k+1; i <= n; i++)
	{
	  M[i][k]=M[i][k]/M[k][k];
	}
      for (int i = k+1; i <= n; i++)
	{
	  for (int j = k+1; j <= n; j++)
	    {
	      M[i][j]=M[i][j]-M[i][k]*M[k][j];
	    }
	}
    }
}

//resolution par LU de Ax=b (algo de descente)
void Resolution_LU(vector<vector<double>> &M, vector<double> b , vector<double> &x )
{
  int n=b.size();
  // calcul de y avec LUx=b et Ux=y (donc Ly=b)
  x[0] = b[0];
  for (int i=1 ; i < n  ; i++)
    {
      x[i] = b[i];
	for (int k=0 ; k < i ; k++)
	  {
	    x[i] += -M[i][k]*x[k];
	  }
    }
  cout << "affichage du vecteur y de Ly=b :" << endl;
  Display_vect(x);

  //calcul de x
  x[n-1]=x[n-1]/M[n-1][n-1];
  for (int i=n-2 ; i>=0 ; --i)
    {
      for (int k=i+1 ; k < n ; k++)
	{
	  x[i] += -M[i][k]*x[k];
	}
      x[i] = x[i]/M[i][i];
    }
  cout << "affichage du vecteur x de LUx=b :" << endl;
  Display_vect(x);
}

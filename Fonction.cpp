# include <iostream>
# include <string>
# include <cmath>
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

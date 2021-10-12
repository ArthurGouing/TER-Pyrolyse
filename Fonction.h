# include <string>
# include <vector>


//Sauvegarde dans un fichier les instants t et l'ensemble des cellules
string Sauvegarde_tout_le_maillage(string name);

//Sauvegarde dans un fichier les instants t et les cellules qui sont sur la colonne k
string Sauvegarde_colonne(string name, int k);

//créé le fichier CommandGnuplot.txt pour avoir juste à faire load CommandGnuplot dans CommandGnuplot
void Fichier_Gnuplot(string cas);

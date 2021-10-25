# include <string>
# include <vector>
using std::vector;

void Display_matrice(vector<vector<double>> M);
void Display_vect(vector<double> x);
void Decomposition_LU(vector<vector<double>> A , vector<vector<double>> &M);
void Resolution_LU(vector<vector<double>> &M, vector<double> b , vector<double> &x );



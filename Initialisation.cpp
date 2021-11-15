# include <iostream>
# include <string>
# include <cmath>
#include <vector>
#include <fstream>
# include "Initialisation.h"
using namespace std;


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



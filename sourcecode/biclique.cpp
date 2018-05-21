#include <Rcpp.h>
#include "bigraph2.h"
#include <iostream>
#include <string>
#include <fstream>

typedef int LT;		
typedef int RT;		
//[[Rcpp::export]]
int biclique()
{

  char *arg1 = "bigraph.txt";
 
  char *arg2 = "biclique.txt";
  char *arg3 = "bicliquesize.txt";
  
  SimpleBigraph<LT, RT> SBG;
  
  ofstream bicliq_fs(arg2), size_fs(arg3);
  
  if (!bicliq_fs || !size_fs) {
    cout << "Error output files!" << endl;
    return 0;
  }
  
  cout << "Read edges: " << SBG.read(arg1) << endl;
  cout << "Left: " << SBG.l_size() << endl;
  cout << "Right: " << SBG.r_size() << endl;
  
  SBG.mica(bicliq_fs, size_fs, cout);
  cout << endl;
  
  bicliq_fs.close();
  size_fs.close();
  
  return 0;
}



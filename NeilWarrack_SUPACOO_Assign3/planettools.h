// header file for sorting
#ifndef PLANETTOOLS_H
#define PLANETTOOLS_H

// use, for example:
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//*  sort( planets.begin(), planets.end(), sortByName );              *
//*  cout << "\n A list of planets in alphabetical order:\n";                 *
//*  for ( int j = 0; j < lines ; j++){                               *
//*    cout << "\t" << j+1 << ") " << planets[j].getName() << endl ;  *
//*   }                                                               * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


 
using namespace std;

  bool SortByName(Planet &lhs, Planet &rhs){ return lhs.GetName() < rhs.GetName() ; }
  bool SortByMass(Planet &lhs, Planet &rhs){ return lhs.GetMass() < rhs.GetMass() ; }


#endif

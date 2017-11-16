#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "planets.h"
#include "datafileprocess.h"


using namespace std;

//sort functions
bool sortByName(Planet &lhs, Planet &rhs){ return lhs.getName() < rhs.getName() ; }
bool sortByMass(Planet &lhs, Planet &rhs){ return lhs.getMass() < rhs.getMass() ; }
bool sortByDist(Planet &lhs, Planet &rhs){ return lhs.getDist() < rhs.getDist() ; }


int main (){

  /*
  Planet x ("Earth", 25, 1);

  cout << "The planets name is: " << x.getName() << endl;
  cout << "The planets mass is: " << x.getMass() 
       << "kg" << endl;
  cout << "The planets distance, in AU, is: " 
       << x.getDist() << endl;
  */

  ifstream mydata;
  // Now open an existing input file...
  mydata.open("input.txt");
  // check that operation worked...
  if ( mydata.fail() ) {
    cout << "ERROR: Sorry, couldn’t open file input.txt -- It does not exisit in this location!" << endl;
    return 1;
  }

  //   count lines in file
  int lines = lineCounter(mydata);

  
  vector<Planet> planets;
  Planet x ;
  string name;
  double mass;
  double distance;


  while ( mydata.good() ){

    mydata >> name >> mass >> distance ;
    if( mydata.eof() ) break ;
    x.setName(name);
    x.setMass(mass);
    x.setDist(distance);
    planets.push_back(x);

    // test setter and getter functions functions
    if (x.getName() == "") { cout << "ERROR-1" ; return 1;}
    if (x.getMass() == 0 ) { cout << "ERROR-2" ; return 1;}
    if (x.getDist() == 0 ) { cout << "ERROR-3" ; return 1;}
  }

  // ++++++++++++++ SORT BY ALPHABET +++++++++++++++++++

  sort( planets.begin(), planets.end(), sortByName );
  cout << "\n - Planets in alphabetical order:\n";   
  for ( int j = 0; j < lines ; j++){
    cout << "\t" << j+1 << ") " << planets[j].getName() << endl ;
  }

  // ++++++++++++++ SORT BY MASS ++++++++++++++++++++++++
  sort( planets.begin(), planets.end(), sortByMass ); 
  cout << "\n - Planets in order of increasing mass:\n";    
  for ( int k = 0; k < lines; k++){
    cout << "\t" << k+1 << ") " << planets[k].getName() << " (" <<  planets[k].getMass() 
	 << " kg)\n" ;
  }
  cout << endl;

  // Identify most and least massive planets
  string mass_max = planets[lines - 1].getName() ;
  string mass_min = planets[0].getName() ;

  // ++++++++++++++ SORT BY DISTANCE ++++++++++++++++++++
  sort( planets.begin(), planets.end(), sortByDist ); 
  cout << "\n - Planets in order of increasing distance from the sun:\n";    
 for ( int l = 0; l < lines; l++){
   cout << "\t" << l+1 << ") " << planets[l].getName() << " (" <<  planets[l].getDist() 
	<< " AU)\n" ;
  }
  cout << endl;

  // Identify most and least distant (from sun) planets
  string dist_max = planets[lines - 1].getName() ;
  string dist_min = planets[0].getName() ;

  // Print the planet with the smallest and largest mass. Same for distance to the sun.
 
  cout << " - " << mass_min << " is the planet with smallest mass." << endl ;
  cout << " - " << mass_max << " is the planet with largest mass." << endl ;
  cout << " - " << dist_min << " is the planet with smallest distance from the sun." << endl ;
  cout << " - " << dist_max << " is the planet with largest distance from the sun." << endl ;
  
    //computed weighted distance
    double tot_mass = 0;
    double tot_wMass = 0;
    for (Planet planetX : planets ){
      tot_wMass += (planetX.getDist()*planetX.getMass());
      tot_mass += planetX.getMass();}


    cout << " - The (mass) weighted average distance to a planet is: " 
	 << tot_wMass/tot_mass << " AU.\n" << endl ;

  mydata.close();
  
  return 0;
}

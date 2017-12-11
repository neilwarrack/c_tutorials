#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "planets.h"
#include "datafileprocess.h"
#include "planettools.h"

using namespace std;


int main (int argc, char *argv[] ){
  // Return error if no or incorrect arguments are passed at command line.
  if (argc != 3) {
    cout << "ERROR: You must run this program with two arguments of type float\n"
         << "The first argument specifies in days the time interval over which\n"
         << "evolutionary acceleration may be considered constant. The second\n"
         << "argument specifies in days the total tim eof evolution required\n"
         << "$ ./thisScript.sh 0.5 365\n"
         << "will calculate the evolution of the system over a year acording to\n"
         << "the assumption that the 'constant' acceleration of each body be\n"
         << "recalculated every half day." << endl;
    return 1; }

  // convert user defined argument to doubles
  const float dt = atof(argv[1]) ;
  const float total_time = atof(argv[2]) ;

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

  
  vector<Planet> planets ;
  Planet planet ;
  string name = "empty" ;
  double mass = 0.0 ;
  double x0 = 0.0 ;
  double y0 = 0.0 ;
  double xv0 = 0.0 ;
  double yv0 = 0.0 ;

  cout << dt << endl ;
  cout << total_time << endl ;

  while ( mydata.good() ){

    mydata >> name >> mass >> x0 >> y0 >> xv0 >> yv0  ;
    if( mydata.eof() ) break ;
    planet.SetName( name ) ;
    planet.SetMass( mass ) ;
    planet.SetX0( x0 ) ;
    planet.SetY0( y0 ) ;
    planet.SetXV0( xv0 ) ;
    planet.SetYV0( yv0 ) ;
    planets.push_back( planet ) ;

    // Test setter and getter functions
    if (planet.GetName() == "empty") { cout << "ERROR: vector not filled during while loop" ; return 1; }
    if (planet.GetMass() == 0.0 ) { cout << "ERROR: no mass!" ; return 1;} 
  }

  cout << planets[3].GetYV0() << " <- GetYV0 for planet " << planets[3].GetName() 
       << "before evolution." << endl ;
  planets[3].EvolveY(dt, total_time) ;
  cout << planets[3].GetYV0() << " <- GetYV0 for planet " << planets[3].GetName() 
       << "after evolution." << endl ;


  // ++++++++++++++ SORT BY ALPHABET +++++++++++++++++++
  
  sort( planets.begin(), planets.end(), SortByName );
  cout << "\n - Planets in alphabetical order:\n";   
  for ( int j = 0; j < lines ; j++){
    cout << "\t" << j+1 << ") " << planets[j].GetName() << endl ;
  }
  

  // ++++++++++++++ SORT BY MASS ++++++++++++++++++++++++
  /*
  sort( planets.begin(), planets.end(), sortByMass ); 
  cout << "\n - Planets in order of increasing mass:\n";    
  for ( int k = 0; k < lines; k++){
    cout << "\t" << k+1 << ") " << planets[k].getName() << " (" <<  planets[k].getMass() 
	 << " kg)\n" ;
  }
  */


  // Identify most and least massive planets
  /*
  string mass_max = planets[lines - 1].getName() ;
  string mass_min = planets[0].getName() ;
  */

  // ++++++++++++++ SORT BY DISTANCE ++++++++++++++++++++
  /*
  sort( planets.begin(), planets.end(), sortByDist ); 
  cout << "\n - Planets in order of increasing distance from the sun:\n";    
 for ( int l = 0; l < lines; l++){
   cout << "\t" << l+1 << ") " << planets[l].getName() << " (" <<  planets[l].getDist() 
	<< " AU)\n" ;
  }
  */

  // Identify most and least distant (from sun) planets
  /*
  string dist_max = planets[lines - 1].getName() ;
  string dist_min = planets[0].getName() ;
  */

  // Print the planet with the smallest and largest mass. Same for distance to the sun.
  /* 
  cout << " - " << mass_min << " is the planet with smallest mass." << endl ;
  cout << " - " << mass_max << " is the planet with largest mass." << endl ;
  cout << " - " << dist_min << " is the planet with smallest distance from the sun." << endl ;
  cout << " - " << dist_max << " is the planet with largest distance from the sun." << endl ;
  */

    //computed weighted distance
  /*
    double tot_mass = 0;
    double tot_wMass = 0;
    for (Planet planetX : planets ){
      tot_wMass += (planetX.getDist()*planetX.getMass());
      tot_mass += planetX.getMass();}


    cout << " - The (mass) weighted average distance to a planet is: " 
	 << tot_wMass/tot_mass << " AU.\n" << endl ;
  */


  // Close data file
  mydata.close();
  
  return 0;
}

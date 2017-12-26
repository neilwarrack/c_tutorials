//* N. Warrack

// * * * * * * * *  * *  * * *  * * * *  * * * * * * * * * * * * * *  * * * * 
// argv[4] = varcodes
// 
// 1 = X ; 2 = Y ; 3 = XV ; 4 = YV ; 5 = XA ; 6 = YA
//
// FYI: index codes / planet codes
// 1 = EARTH ; 2 = MOON ; 3 = SUN ; 4 = MERCURY ; 5 = VENUS ; 6 = MARS
// 7 = JUPITER ; 8 = SATURN ; 9 = URANUS ; NEPTUNE = 0
// * * * * * ** * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * *

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>
#include "planets.h"
#include "system.h"
//#include "datafileprocess.h"
#include "planettools.h"

using namespace std;


int main (int argc, char *argv[] ){
  // Return error if no or incorrect arguments are passed at command line.
  if (argc != 5) {
    cout << "ERROR: You must run this program with two arguments of type double\n"
         << "The first argument specifies in days the time interval over which\n"
         << "evolutionary acceleration may be considered constant. The second\n"
         << "argument specifies in days the total tim eof evolution required\n"
         << "$ ./thisScript.sh 0.5 365\n"
         << "will calculate the evolution of the system over a year acording to\n"
         << "the assumption that the 'constant' acceleration of each body be\n"
         << "recalculated every half day." << endl;
    return 1; }



  // read command line arguments (convert to doubles)
  const double dt = atof(argv[1]) ;
  const double total_time = atof(argv[2]) ;
  const int steps = total_time/dt ;


  // Open an existing input file 
  ifstream mydata;
  mydata.open("input.txt");
  if ( mydata.fail() ) {
    cout << "ERROR: Sorry, couldn’t open file input.txt "
         << "-- It does not exisit in this location!" << endl ;
    return 1 ;
  }
  // create output files
  ofstream f_earth;
  ofstream f_moon;
  ofstream f_sun ;
  ofstream f_mercury ;
  ofstream f_venus ;
  ofstream f_mars ;
  ofstream f_jupiter ;
  ofstream f_saturn ;
  ofstream f_uranus ;
  ofstream f_neptune ;



  // Fill vector of <Planet>s from file

  string name = "empty" ;
  double mass = 0.0 ;
  double x0 = 0.0 ;
  double y0 = 0.0 ;
  double xv0 = 0.0 ;
  double yv0 = 0.0 ;
  vector<Planet> planets ;

  while ( mydata.good() ){

    mydata >> name >> mass >> x0 >> y0 >> xv0 >> yv0  ;
    if( mydata.eof() ) break ;
    Planet planet(name, mass, x0, y0, xv0, yv0);
   
    if (planet.GetName() == "empty") {     // Test getter functions
      cout << "ERROR: vector not filled during while loop" ; 
      return 1; 
    }
    
    planets.push_back( planet ) ;
    cout << " - push_back success for: " << planet.GetName() << endl ;
  }

  // Read code arguments
  const int planetcode = atoi(argv[3]) ;
  //  cout << "planet code: " << planetcode << endl ;
  const int varcode = atoi(argv[4]) ;
  cout << "variable code: " ;
  if (varcode == 1) cout << "X position" << endl ;
  if (varcode == 2) cout << "Y position" << endl ;
  if (varcode == 3) cout << "X velocity" << endl ;
  if (varcode == 4) cout << "Y velocity" << endl ;
  if (varcode == 5) cout << "X acceleration" << endl ;
  if (varcode == 6) cout << "Y acceleration" << endl ;

 
  // index planets according to readme1.txt
  System system (planets) ;
  system.IndexSolarSystem() ;

 
  for (Planet& n : system.GetPlanets() ){
    // cout << planetcode << n.GetIndex() << endl ;
     if ( planetcode == n.GetIndex() ){
      if (planetcode == 1 ) cout << "PLANETCODE: " << planetcode << "=" << n.GetName() << endl ;
      if (planetcode == 2 ) cout << "PLANETCODE: " << planetcode << "=" << n.GetName() << endl ;
      if (planetcode == 3 ) cout << "PLANETCODE: " << planetcode << "=" << n.GetName() << endl ;
      if (planetcode == 4 ) cout << "PLANETCODE: " << planetcode << "=" << n.GetName() << endl ;
      if (planetcode == 5 ) cout << "PLANETCODE: " << planetcode << "=" << n.GetName() << endl ;
      if (planetcode == 6 ) cout << "PLANETCODE: " << planetcode << "=" << n.GetName() << endl ;
      if (planetcode == 7 ) cout << "PLANETCODE: " << planetcode << "=" << n.GetName() << endl ;
      if (planetcode == 8 ) cout << "PLANETCODE: " << planetcode << "=" << n.GetName() << endl ;
      if (planetcode == 9 ) cout << "PLANETCODE: " << planetcode << "=" << n.GetName() << endl ;
      if (planetcode == 0 ) cout << "PLANETCODE: " << planetcode << "=" << n.GetName() << endl ;    
     }
  }
  cout << endl ;
  
  
  f_earth.open ("out_earth.txt");
  f_moon.open ("out_moon.txt");  
  f_sun.open ("out_sun.txt");
  f_mercury.open ("out_mercury.txt");  
  f_venus.open ("out_venus.txt");  
  f_mars.open ("out_mars.txt"); 
  f_jupiter.open ("out_jupiter.txt");  
  f_saturn.open ("out_saturn.txt");
  f_uranus.open ("out_uranus.txt");  
  f_neptune.open ("out_neptune.txt");    
  
  
  // evolve system
  for (int i = 1 ; i <= steps ; i++){
    
  
  for (Planet& n : system.GetPlanets() ){

    if (n.GetIndex() == 1){
      f_earth << i << " " << i*dt << "days " << n.GetX0() << " " << n.GetY0() << endl ;
    }
    if (n.GetIndex() == 2){
      f_moon  << i << " " << i*dt << "days " << n.GetX0() << " " << n.GetY0() << endl ;
    }
    if (n.GetIndex() == 2){
      f_sun << i << " " << i*dt << "days " << n.GetX0() << " " << n.GetY0() << endl ;
    }
    if (n.GetIndex() == 3){
      f_mercury << i << " " << i*dt << "days " << n.GetX0() << " " << n.GetY0() << endl ;
    }
    if (n.GetIndex() == 4){
      f_venus << i << " " << i*dt << "days " << n.GetX0() << " " << n.GetY0() << endl ;
    }
    if (n.GetIndex() == 5){
      f_mars << i << " " << i*dt << "days " << n.GetX0() << " " << n.GetY0() << endl ;
    }
    if (n.GetIndex() == 6){
      f_jupiter << i << " " << i*dt << "days " << n.GetX0() << " " << n.GetY0() << endl ;
    }
    if (n.GetIndex() == 7){
      f_saturn << i << " " << i*dt << "days " << n.GetX0() << " " << n.GetY0() << endl ;
    }
    if (n.GetIndex() == 8){
      f_uranus << i << " " << i*dt << "days " << n.GetX0() << " " << n.GetY0() << endl ;
    }
    if (n.GetIndex() == 9){
      f_neptune << i << " " << i*dt << "days " << n.GetX0() << " " << n.GetY0() << endl ;
    }
  system.EvolveSystem( dt, planetcode, varcode ) ; 
  }
  }


  f_earth.close() ;  
  f_moon.close() ;
  f_sun.close() ;
  f_mercury.close() ;  
  f_venus.close() ;
  f_mars.close() ; 
  f_jupiter.close() ; 
  f_saturn.close() ; 
  f_uranus.close() ;
  f_neptune.close() ;  
  
  // Close data file
  mydata.close();


  return 0;
  }

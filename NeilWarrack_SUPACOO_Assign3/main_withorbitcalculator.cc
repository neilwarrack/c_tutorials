//* N. Warrack

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>
#include "planets.h"
#include "system.h"
#include "datafileprocess.h"

using namespace std;


int main (int argc, char *argv[] ){
  // Return error if no or incorrect arguments are passed at command line.
  if (argc != 3) {
    cout << "ERROR: You must run this program with two arguments of type double\n"
         << "The first argument specifies in days the time interval over which\n"
         << "evolutionary acceleration may be considered constant. The second\n"
         << "argument specifies in days the total time of evolution required\n"
         << "$ ./thisScript 0.5 365\n"
         << "will calculate the evolution of the system over a year acording to\n"
         << "the assumption that the 'constant' acceleration of each body be\n"
         << "recalculated every half day." << endl;
    return 1; }


  // read command line arguments (convert to doubles)
  const static double dt = atof(argv[1]) ;
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
  }
 
  // index planets according to readme1.txt
  System system (planets) ;
  system.IndexSolarSystem() ;

  
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
  system.EvolveSystem( dt ) ; 
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

  //__________________________________________________________________


  string n_time = "empty" ;
  int n_step = 0 ;   
  double x = 0.0 ;
  double y = 0.0 ;
  double previous_x = 5.0e15 ;
  int line_counter = 1 ;  
  bool orbitCalculated = false ;
  
  for (int g = 1 ; g < planets.size(); g++){
  ifstream a;
  if (g==1){ 
    a.open("out_earth.txt");
    cout << "Earth: " << endl ;}
  if (g==2){ 
    a.open("out_moon.txt");
    cout << "moon: " << endl ;}
  if (g==3){ 
    a.open("out_sun.txt");
    cout << "Sun: " << endl ;}
  if (g==4){ 
    a.open("out_mercury.txt");
    cout << "Mercury: " << endl ;}
  if (g==5){ 
    a.open("out_venus.txt");
    cout << "Venus: " << endl ;}
  if (g==6){ 
    a.open("out_mars.txt");
    cout << "Mars: " << endl ;}
  if (g==7){ 
    a.open("out_jupiter.txt");
    cout << "Jupiter: " << endl ;}
  if (g==8){ 
    a.open("out_saturn.txt");
    cout << "Saturn: " << endl ;}
  if (g==9){ 
    a.open("out_uranus.txt");
    cout << "Uranus: " << endl ;}
  if (g==0){ 
    a.open("out_neptune.txt");
    cout << "Neptune: " << endl ;}
  
  if ( a.fail() ) {
    cout << "ERROR: Sorry, couldn’t open out_{planet}.txt "
         << "-- It does not exisit in this location!" << endl ;
  }
  while ( a.good() ){
      if( a.eof() ) break ; 
   if (orbitCalculated) break ;
   a >> n_step >> n_time >> x >> y ;
   
   if ( line_counter == 1 ) previous_x = 5e15 ;
   if ((previous_x-x) < 0 ){
     cout << "time of orbit = " << n_step*2*dt << " days." << endl ;
     orbitCalculated = true ;
   }
   
   previous_x = x ;
   line_counter++ ;
  }
 
  line_counter = 1 ;        // reset line_counter
  orbitCalculated = false ; // reset orbit calculated flag
  a.close() ;               // close file

  }
  
  return 0;

}

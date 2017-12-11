#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
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
  const int days = 86400 ; // time in seconds
  const double G = 6.674e-11 ; 
  const int steps = total_time*days/(dt*days) ;
  cout << "steps = " << steps ;

  ifstream mydata;
  // Now open an existing input file...
  mydata.open("input.txt");
  // check that operation worked...
  if ( mydata.fail() ) {
    cout << "ERROR: Sorry, couldn’t open file input.txt -- It does not exisit in this location!" << endl;
    return 1;
  }

  /*
  //   count lines in file
  int lines = lineCounter(mydata);
  */
  
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

  double a = 0.0 ;
  double a_x = 0.0 ;
  double sum_a_x = 0.0 ;
  double a_y = 0.0 ; 
  double sum_a_y = 0.0 ; 
  double rsqrd = 0.0 ;
  double hypot = 0.0 ;

  // PRINT OUT
  /*
  for ( Planet& k : planets ){  
    cout << "Before evolution:" << endl ;
    cout << k.GetX0()  << " <- GetX0 for "  << k.GetName() << endl ; 
    cout << k.GetXV0() << " <- GetXV0 for " << k.GetName() << endl ; 
    cout << k.GetY0()  << " <- GetY0 for "  << k.GetName() << endl ; 
    cout << k.GetYV0() << " <- GetYV0 for " << k.GetName() << endl ; 
  }
  */
  cout << planets[5].GetName() << " is at coord:" << endl ;
  cout << "(" << planets[5].GetX0() << "," << planets[5].GetY0() << ")" << endl ; 
  for (int i = 1 ; i < steps ; i++){


  // compute accelerations and store in planet objects
  for (Planet& p : planets ) {
    //cout << "+++++ " << p.GetName() << " +++++" << endl ;

  sum_a_x = 0.0 ; // reset sum!
  sum_a_y = 0.0 ; // reset sum!

  for ( Planet& q : planets ){ 
    if ( &p == &q ) {
      //      cout << "<<<----- remove itself from sum." << endl;
      continue ;}
    //cout << "adding planet q = " << q.GetName() << endl ;
    //cout << "p.GetX0() = " << p.GetX0() << " q.GetX0() = " << q.GetX0() << endl ;
    //cout << "p.GetX0() - q.GetX0() = " << p.GetX0() - q.GetX0() << endl ;
    //cout << (p.GetX0() - q.GetX0() )*(p.GetX0() - q.GetX0() ) << endl ;
    //cout << "q.GetMass() = " << q.GetMass() << endl ;
    rsqrd = (p.GetX0() - q.GetX0() )*(p.GetX0() - q.GetX0() ) + (p.GetY0() - q.GetY0() )*(p.GetY0() - q.GetY0() ) ;
    //cout << "rsqrd = " << rsqrd << endl ;

    // Calculate acceleration of p due to q.   
    hypot = sqrt(rsqrd) ;
    //cout << "hypot = " << hypot << endl ;
    //cout << "G = " << G << endl ;
    //cout << "q.getMass = " << q.GetMass() << endl ;
    //cout << "rsqrd = " << rsqrd << endl ; 
    a = G*(q.GetMass()/rsqrd) ;
    //cout << "a = " << a << endl ;
    a_x = a*(p.GetX0() - q.GetX0() )/hypot ;
    //cout << "a_x = " << a_x << endl ; 
    a_y = a*(p.GetY0() - q.GetY0() )/hypot ;
    
    //cout << "  sum_a_x = " << sum_a_x << endl;
    sum_a_x = sum_a_x + a_x ;
    //cout << "  UPDATED: sum_a_x = " << sum_a_x << endl;

    //cout << "  sum_a_y = " << sum_a_y << endl;
    sum_a_y = sum_a_y + a_y ;
    //cout << "  UPDATED: sum_a_y = " << sum_a_y << endl;
      
}

  //cout << "++++++++++++++++++ ALL ADDED! FINAL RESULTS: ++++++++++++++++++++++" << endl ;
  //cout << "    tot sum_a_x = " << sum_a_x << endl ;
  //cout << "    tot sum_a_y = " << sum_a_y << endl ;
  p.SetXA0(sum_a_x);
  p.SetYA0(sum_a_y);
  //cout << "p.getXA0() = " << p.GetXA0() << endl ;
  //cout << "p.getYA0() = " << p.GetYA0() << endl ;
  //cout << p.GetName() << " DONE!!!!!!!!!!!!!!!!!!!" << endl << endl ;
  }

  // Evolve system.
  // Compute number of steps.

  for ( Planet& s : planets ){
    s.EvolveX(dt) ;
    s.EvolveY(dt) ;
  }
cout << "                             acc(" << planets[5].GetXA0() << "," << planets[5].GetYA0() << ")" << endl ; 
cout << "pos(" << planets[5].GetX0() << "," << planets[5].GetY0() << ")" << endl ; 
//  cout << "step: " << i ;
  }
  //______________________________________________
  // PRINT OUT
  cout << "AFTER evolution:" << endl ;
  for (Planet& t : planets){  
    //  cout << t.GetX0()  << " <- GetX0 for "  << t.GetName() << endl ; 
    //cout << t.GetXV0() << " <- GetXV0 for " << t.GetName() << endl ; 
    //cout << t.GetY0()  << " <- GetY0 for "  << t.GetName() << endl ; 
  }

  // ++++++++++++++ SORT BY ALPHABET +++++++++++++++++++
  /*
  sort( planets.begin(), planets.end(), SortByName );
  cout << "\n - Planets in alphabetical order:\n";   
  for ( int j = 0; j < lines ; j++){
    cout << "\t" << j+1 << ") " << planets[j].GetName() << endl ;
  }
  */

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

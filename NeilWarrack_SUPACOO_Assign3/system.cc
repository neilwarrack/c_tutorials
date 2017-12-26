#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include "planets.h"
#include "system.h"

using namespace std ;



System::System(const vector<Planet>& planets ){
  m_system = planets ;
  m_planet1 = m_system[0] ;
}


vector<Planet> System::GetPlanets() { return m_system ; }


void System::IndexSolarSystem(){
  // index planets according to :
  // 1 = EARTH ; 2 = MOON ; 3 = SUN ; 4 = MERCURY ; 5 = VENUS ; 6 = MARS ; 7 = JUPITER ; 8 = SATURN ; 9 = URANUS ; 0 = NEPTUNE 
 for (Planet& n : m_system ) {
   if (n.GetMass() == 5.9736e+24 ) {n.SetIndex(1) ;}// cout << "Earth indexed: "   << n.GetIndex() ;}
    if (n.GetMass() == 7.3477e+22 ) {n.SetIndex(2) ;}// cout << "Moon indexed: "    << n.GetIndex() ;}
    if (n.GetMass() == 1.9890e+30 ) {n.SetIndex(3) ;}// cout << "Sun indexed: "     << n.GetIndex() ;}
    if (n.GetMass() == 3.3022e+23 ) {n.SetIndex(4) ;}// cout << "Mercury indexed: " << n.GetIndex() ;}
    if (n.GetMass() == 4.8685e+24 ) {n.SetIndex(5) ;}// cout << "Venus indexed: "   << n.GetIndex() ;}
    if (n.GetMass() == 6.4185e+23 ) {n.SetIndex(6) ;}// cout << "Mars indexed: "    << n.GetIndex() ;}
    if (n.GetMass() == 1.8986e+27 ) {n.SetIndex(7) ;}// cout << "Jupiter indexed: " << n.GetIndex() ;}
    if (n.GetMass() == 5.6846e+26 ) {n.SetIndex(8) ;}// cout << "Saturn indexed: "  << n.GetIndex() ;}
    if (n.GetMass() == 8.6810e+25 ) {n.SetIndex(9) ;}// cout << "Uranus indexed: "  << n.GetIndex() ;}
    if (n.GetMass() == 1.0243e+26 ) {n.SetIndex(0) ;}// cout << "Neptune indexed: " << n.GetIndex() ;}
    //cout << "indexSolarSystem done!" << endl ;
 }
}


void System::EvolveSystem( double dt, int planetcode, int varcode ){
  const static int days = 86400 ;     // time in seconds
  const static double G = 6.674e-11 ; // Gravitational constant
  double a = 0.0 ;           // magnitudue of acceleration
  double a_x = 0.0 ;         // acceleration in x direction
  double sum_a_x = 0.0 ;
  double a_y = 0.0 ;         // acceleration in y direction
  double sum_a_y = 0.0 ;
  double rsqrd = 0.0 ;       // distance
  double hypot = 0.0 ;       // = sqrt(rsqrd)

    for (Planet& p : m_system ) {

      if ( sum_a_x != 0.0 ) sum_a_x = 0.0 ; // reset sum!
      if ( sum_a_y != 0.0 ) sum_a_y = 0.0 ; // reset sum!

      // Compute x and y accelleration on p due to all other bodies.    
      for (const Planet& q : m_system ){
        
        if ( &p == &q )  continue ; // don't compute planets force 'with itself'!

        rsqrd = (p.GetX0() - q.GetX0() )*(p.GetX0() - q.GetX0() ) 
          + (p.GetY0() - q.GetY0() )*(p.GetY0() - q.GetY0() ) ;
        hypot = sqrt(rsqrd) ;
        a = -G*(q.GetMass()/rsqrd) ;
        a_x = a*(p.GetX0() - q.GetX0() )/hypot ;
        a_y = a*(p.GetY0() - q.GetY0() )/hypot ;

        sum_a_x = sum_a_x + a_x ;
        sum_a_y = sum_a_y + a_y ;
      }

      p.SetXA0(sum_a_x);
      p.SetYA0(sum_a_y);
      /*
      if ( planetcode == p.GetIndex() ) {
        if (varcode == 1 ) cout << p.GetX0() << endl ;
        if (varcode == 2 ) cout << p.GetY0() << endl ;
        if (varcode == 3 ) cout << p.GetXV0() << endl ;
        if (varcode == 4 ) cout << p.GetYV0() << endl ;
        if (varcode == 5 ) cout << p.GetXA0() << endl ;
        if (varcode == 6 ) cout << p.GetYA0() << endl ;        
      }
      */
 
    } // loop: calculate next x & y acceleration for next planet and STORE
      //       in Planet object


    // ...once all accelerations are calculated...
    // Evolve system.
    for ( Planet& s : m_system ){
      s.EvolveX(dt*days) ;
      s.EvolveY(dt*days) ;     
    }
    
} // end EvolveSystem() function



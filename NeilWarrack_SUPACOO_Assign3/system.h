#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include "planets.h"

using namespace std ;

class System : public Planet 
{

 public:


  System() ;
  System( const vector<Planet>& planets ) ;
  vector<Planet> GetPlanets() ;
  void IndexSolarSystem() ; 
  void EvolveSystem( double dt) ;
 private:
  vector<Planet> m_system ;
  Planet m_planet1 ;
};
 
#endif

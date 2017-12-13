#ifndef SYSTEM_H
#define SYSTEM_H

#include "planets.h"

using namespace std ;

class System : public Planet {

public:

  System() ;
  System( vector<Planet> planets ) ;

  // Evolve function
  void EvolveSystem(float dt) ;

 private:
  vector<Planet> m_system ;
};
 
#endif

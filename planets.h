#ifndef PLANETS_H
#define PLANETS_H

using namespace std;

class Planet
{
 public: // can be accessed from outside the class

  // constructor invocation allocates memory for the object, initializes members and executed the body of the constructor 

  // constructor so an object can be instantiated by Planet myPlanet();
  Planet();
  // constructor so an object can be instantiated by Planet myPlanet(string n, double m, double d);
  Planet(string x, double m, double d);

  // getter/accessor function
  string getName();
  double getMass();
  double getDist();

  void setName(string n);
  void setMass(double m);
  void setDist(double d);

 private: // can only be accessed from inside the class definition
  // data members:
  string m_name; 
  double m_mass;
  double m_distance;

};

#endif

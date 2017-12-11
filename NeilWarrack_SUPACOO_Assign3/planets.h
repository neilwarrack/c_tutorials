#ifndef PLANETS_H
#define PLANETS_H

using namespace std;

class Planet
{
 public: // can be accessed from outside the class

  // constructors; invocation allocates memory for the object, initializes members and executed the body of the constructor 
  Planet() ;
  Planet(string x, double m, double x0, double y0, double xv0, double yv0) ;

  // getter/setter functions
  string GetName() ;
  double GetMass() ;
  double GetX0() ;
  double GetY0() ;
  double GetXV0() ;
  double GetYV0() ;
  void SetName(string n) ;
  void SetMass(double m) ;
  void SetX0(double x0) ;
  void SetY0(double y0) ;
  void SetXV0(double xv0) ;
  void SetYV0(double yv0) ;

  // Evolve functions
  void EvolveX(float dt, double a) ;
  void EvolveY(float dt, double a) ;


 private: // can only be accessed from inside the class definition
  // data members:
  string m_name ; 
  double m_mass ;
  double m_x0 ;
  double m_y0 ;
  double m_xv0 ;
  double m_yv0 ;

  double m_x1 ;
  double m_y1 ;
  double m_xv1 ;
  double m_yv1 ;
};

#endif

#ifndef PLANETS_H
#define PLANETS_H

using namespace std;

class Planet
{
 public: // can be accessed from outside the class

  // constructors; invocation allocates memory for the object, initializes members and executed the body of the constructor 
  Planet() ;
  //Planet(string x, double m, double x0, double y0, double xv0, double yv0) ;
  Planet(string x, double m, double x0, double y0, double xv0, double yv0, double xa0=0, double ya0=0) ;

  // getter/setter functions
  string GetName() const { return m_name; }// this will be inline (rather than defining in .cc file)

  double GetMass() const { return m_mass; }
  double GetX0() const { return m_x0; }
  double GetY0() const { return m_y0; }
  double GetXV0() const { return m_xv0; }
  double GetYV0() const { return m_yv0; }
  double GetXA0() const { return m_xa0; }
  double GetYA0() const { return m_ya0; }
  int GetIndex() const { return m_index; }

  void SetName(string n) ;
  void SetMass(double m) ;
  void SetX0(double x0) ;
  void SetY0(double y0) ;
  void SetXV0(double xv0) ;
  void SetYV0(double yv0) ;
  void SetXA0(double xa0) ;
  void SetYA0(double ya0) ;
  void SetIndex(int index) ;

  // Evolve functions
  void EvolveX(double dt) ;
  void EvolveY(double dt) ;


 private: // can only be accessed from inside the class definition
  // data members:
  string m_name ; 
  double m_mass ;
  double m_x0 ;
  double m_y0 ;
  double m_xv0 ;
  double m_yv0 ;
  double m_xa0 ;
  double m_ya0 ;
  int m_index ;
};

#endif

#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include "planets.h"

using namespace std;



Planet::Planet() 
  : Planet("unnamed", 0, 0, 0, 0, 0, 0, 0)
{    }


Planet::Planet(string n, double m, double x0, double y0, 
               double xv0, double yv0, double xa0, double ya0) {
  m_name = n ;
  m_mass = m ;
  m_x0 = x0 ;
  m_y0 = y0 ;
  m_xv0= xv0 ;
  m_yv0 = yv0 ;
  m_xa0 = xa0 ;
  m_ya0 = ya0 ;
  m_index = 0 ;
}

/*
// Define getter functions
string Planet::GetName() const  { return m_name ; }
double Planet::GetMass() const { return m_mass ; }
double Planet::GetX0() const { return m_x0 ; }
double Planet::GetY0() const { return m_y0 ; }
double Planet::GetXV0() const { return m_xv0 ; }
double Planet::GetYV0() const { return m_yv0 ; }
double Planet::GetXA0() const { return m_xa0 ; }
double Planet::GetYA0() const { return m_ya0 ; }
int Planet::GetIndex() const { return m_index ; }
*/

// Define setter functions
void Planet::SetName(string n) { m_name = n ; }
void Planet::SetMass(double m) { m_mass = m ; }
void Planet::SetX0(double x0) { m_x0 = x0 ; }
void Planet::SetY0(double y0) { m_y0 = y0 ; }
void Planet::SetXV0(double xv0) { m_xv0 = xv0 ; }
void Planet::SetYV0(double yv0) { m_yv0 = yv0 ; }
void Planet::SetXA0(double xa0) { m_xa0 = xa0 ; }
void Planet::SetYA0(double ya0) { m_ya0 = ya0 ; }
void Planet::SetIndex(int index) { m_index = index ; }


// Define evolotion functions
void Planet::EvolveX(double t) {
  //  cout << "prior: " << m_x0 << endl; 
  double x = 0 ;
  double xv = 0 ;

  x = m_x0 + m_xv0*t + (m_xa0*t*t)/2 ;
  xv = m_xv0 + m_xa0*t ;
  SetX0(x) ;
  SetXV0(xv) ;
  SetXA0(0) ;
  //cout << "after: " << m_x0 << endl; 
} 

void Planet::EvolveY(double t) {
  double y = 0 ;
  double yv = 0 ;

  y = m_y0 + m_yv0*t + (m_ya0*t*t)/2 ;
  yv = m_yv0 + m_ya0*t ;
  SetY0(y) ;
  SetYV0(yv) ;
  SetYA0(0) ;
} 


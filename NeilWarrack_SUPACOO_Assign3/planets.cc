#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include "planets.h"

using namespace std;

Planet::Planet() {
  m_name = "unnamed";
  m_mass = 0;
  m_x0 = 0;
  m_y0 = 0;
  m_xv0 = 0;
  m_yv0 = 0;
}

Planet::Planet(string n, double m, double x0, double y0, double xv0, double yv0){
  m_name = n;
  m_mass = m;
  m_x0 = x0;
  m_y0 = y0;
  m_xv0= xv0;
  m_yv0 = yv0;
}

// Define getter functions
string Planet::GetName() { return m_name ; }
double Planet::GetMass() { return m_mass ; }
double Planet::GetX0() { return m_x0 ; }
double Planet::GetY0() { return m_y0 ; }
double Planet::GetXV0() { return m_xv0 ; }
double Planet::GetYV0() { return m_yv0 ; }

// Define setter functions
void Planet::SetName(string n) { m_name = n ; }
void Planet::SetMass(double m) { m_mass = m ; }
void Planet::SetX0(double x0) { m_x0 = x0 ; }
void Planet::SetY0(double y0) { m_y0 = y0 ; }
void Planet::SetXV0(double xv0) { m_xv0 = xv0 ; }
void Planet::SetYV0(double yv0) { m_yv0 = yv0 ; }

// Define evolotion functions
void Planet::EvolveX(float dt, double a) {
  m_x1 = m_x0 + m_xv0*dt + 1/2*a*dt*dt ;
  m_xv1 = m_xv0 + a*dt ;
  m_x0 = m_x1 ;
  m_xv0 = m_xv1 ;
} 

void Planet::EvolveY(float dt, double a) {
  m_y1 = m_y0 + m_yv0*dt + 1/2*a*dt*dt ;
  m_yv1 = m_yv0 + a*dt ;
  m_y0 = m_y1 ;
  m_yv0 = m_yv1 ;
} 

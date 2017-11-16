#include <cmath>
#include <iostream>
#include <string>
#include "planets.h"

using namespace std;

Planet::Planet() {
  m_name = "unnamed";
  m_mass = 0;
  m_distance = 0; 
}

Planet::Planet(string n, double m, double d){
  m_name = n;
  m_mass = m;
  m_distance = d;
}

//defining getter functions
string Planet::getName() { return m_name; }
double Planet::getMass() { return m_mass; }
double Planet::getDist() { return m_distance; }

//define setter functions
void Planet::setName(string n) { m_name = n; }
void Planet::setMass(double m) { m_mass = m; }
void Planet::setDist(double d) { m_distance = d; }



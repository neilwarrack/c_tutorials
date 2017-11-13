#include <iostream>
#include <string>
#include "planets.h"
#include <vector>
#include <fstream>
using namespace std;

int main (){

  /*
  Planet x ("Earth", 25, 1);

  cout << "The planets name is: " << x.getName() << endl;
  cout << "The planets mass is: " << x.getMass() 
       << "kg" << endl;
  cout << "The planets distance, in AU, is: " 
       << x.getDist() << endl;
  */

  ifstream mydata;
  // Now open an existing input file...
  mydata.open("input.txt");
  // check that operation worked...
  if ( mydata.fail() ) {
    cout << "Sorry, couldn’t open file input.txt -- It does not exisit in this location!" << endl;
    return 1;
  }


  vector<Planet> planets;
  // read from file, compute magnitudes and write to file
  Planet x ;
  while ( !mydata.eof() ){
    mydata >> x.setName() >> x.setMass() >> x.setDist();
    planets.push_back(x);
   
 /*    if ( !mydata.eof() ) {
      line++;
      r = MagComputer(x,y);
      cout << "x=" << x << "; y=" << y
           << "; magnitude of position vector (x,y) is: " << r
           << endl;
      myfile << x << " " << y << " " << r << endl ;
    }
    */
  }

  cout << "v[1] = " << v[1] << endl;


  return 0;
}

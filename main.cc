#include <iostream>
#include <string>
#include <cstdlib>
#include "planets.h"
#include <vector>
#include <fstream>
#include "datafileprocess.h"
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

  //   count lines in file
  int lines = lineCounter(mydata);
  cout << "lines = " << lines << endl;
  
  vector<Planet> planets;
  // read from file, compute magnitudes and write to file
  Planet x ;
  string name;
  double mass;
  double distance;
  
  while ( !mydata.eof() ){
  mydata >> name >> mass >> distance ;
  x.setName(name);
  x.setMass(mass);
  x.setDist(distance);
  planets.push_back(x);
  }
   
 /*    if ( !mydata.eof() ) {
      line++;
      r = MagComputer(x,y);
      cout << "x=" << x << "; y=" << y
           << "; magnitude of position vector (x,y) is: " << r
           << endl;
      myfile << x << " " << y << " " << r << endl ;
    }
    */
    
 for (int i=0; i<lines; i++){
   cout << "planets[" << i << "].getName = " << planets[i].getName() << endl;
   cout << "planets[" << i << "].getMass = " << planets[i].getMass() << endl;
   cout << "planets[" << i << "].getDist = " << planets[i].getDist() << endl;
   }
  mydata.close();
  return 0;
}

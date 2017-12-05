/*
* N. Warrack
* Program to compute the magnitude of a 2D vector from a file containing 2 colums: "x y"
*/

#include <iostream>
#include <cmath>    
#include <cstdlib>
#include <fstream>
#include "magnitudes.h"
using namespace std;

/*

template<class myType>
myType MagComputer(myType i, myType j){
  myType mag ;
  mag = sqrt( pow(i,2.0) + pow(j,2.0) ) ;
  return mag;
}
*/

int main(){

ifstream mydata;
  // Now open an existing file...
  mydata.open("input2D_int.txt");
  // check that operation worked...
  if ( mydata.fail() ) {
    cout << "Sorry, couldn’t open file input2D_float.txt -- It does not exisit in this location!" << endl;
    return 1; 
  }


  int x, y;
  int line = 0;
  while ( !mydata.eof() ){
    mydata >> x >> y ;
    if ( !mydata.eof() ) {
      line++;

      cout << "x=" << x << "; y=" << y 
	   << "; magnitude of position vector (x,y) is: " << MagComputer<int>(x,y) 
	   << endl;
    }
  }
  cout << line << " lines read from file" << endl;

    mydata.close(); // close when finished

  return 0;

}



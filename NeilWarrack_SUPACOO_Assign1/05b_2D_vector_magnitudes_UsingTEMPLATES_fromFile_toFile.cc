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


int main(){

ifstream mydata;
  // Now open an existing file...
  mydata.open("input2D_int.txt");
  // check that operation worked...
  if ( mydata.fail() ) {
    cout << "Sorry, couldn’t open file input2D_float.txt -- It does not exisit in this location!" << endl;
    return 1; 
  }

  //open an output file
  ofstream output;
  output.open("output2D_int.txt");


  int x, y;
  while ( !mydata.eof() ){
    mydata >> x >> y ;
    if ( !mydata.eof() ) {
      //write to file
      output << x << " " << y << " " << MagComputer<int>(x,y) << endl ; 
    }
  }

  // close when finished
  mydata.close();
  output.close();
  
  return 0;
  
}



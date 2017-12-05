/*
* N. Warrack
* Program to compute the magnitude of a 2D vector from a file containing 2 colums: "x y"
*/

#include <iostream>
#include <cmath>    
#include <cstdlib>
#include <fstream>

using namespace std;

double MagComputer(double,double); //prototype


int main(){

  ifstream mydata;
  // Now open an existing input file...
  mydata.open("input2D_float.txt");
  // check that operation worked...
  if ( mydata.fail() ) {
    cout << "Sorry, couldn’t open file input2D_float.txt -- It does not exisit in this location!" << endl;
    return 1; 
  }

  // Now create an output file...
  ofstream myfile;
  myfile.open ("output2D_float.txt");

  // define constants and variables
  double x, y, r;
  int line = 0;

  // read from file, compute magnitudes and write to file
  while ( !mydata.eof() ){
    mydata >> x >> y ;
    if ( !mydata.eof() ) {
      line++;
      r = MagComputer(x,y);
      cout << "x=" << x << "; y=" << y 
	   << "; magnitude of position vector (x,y) is: " << r
	   << endl;
      myfile << x << " " << y << " " << r << endl ;
    }
  }

  cout << endl << line << " lines read from file\n" << endl;

  // close when finished
  mydata.close();
  myfile.close();

  return 0;

}


double MagComputer(double i, double j){
  
  double mag ;
  mag = sqrt( pow(i,2.0) + pow(j,2.0) ) ;
  return mag;
  
}

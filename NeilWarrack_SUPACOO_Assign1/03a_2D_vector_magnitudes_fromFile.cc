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
  // Now open an existing file...
  mydata.open("input2D_float.txt");
  // check that operation worked...
  if ( mydata.fail() ) {
    cout << "Sorry, couldn’t open file input2D_float.txt -- It does not exisit in this location!" << endl;
    return 1; 
  }


  double x, y;
  int line = 0;
  while ( !mydata.eof() ){
    mydata >> x >> y ;
    if ( !mydata.eof() ) {
      line++;
      cout << "x=" << x << "; y=" << y 
	   << "; magnitude of position vector (x,y) is: " << MagComputer(x,y) 
	   << endl;
    }
  }
  cout << line << " lines read from file" << endl;

    mydata.close(); // close when finished

    /*


 double x, y ;
  cout << "enter an x value x=" ;
  cin >> x ;

  cout << endl << "enter a y value y=" ;
  cin >> y ;

  //  cout << endl << "the magnitude is:" <<  MagComputer(x,y) << endl ;

  cout << "the magnitude of a vecotr with x coord x=" << x
       << " and y coord y=" << y << " is " << MagComputer(x,y) << endl;
    */
  return 0;

}

double MagComputer(double i, double j){
  
  double mag ;
  mag = sqrt( pow(i,2.0) + pow(j,2.0) ) ;
  return mag;
  
}

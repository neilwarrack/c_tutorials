/*
* N. Warrack
* Program to compute the magnitude of a 2D vector
*/

#include <iostream>
#include <cmath>    


using namespace std;

double MagComputer(double,double); //prototype


int main(){

 double x, y ;
 cout << endl << "enter an x value, and then press RETURN." << endl;
 cout << " x = " ;
 cin >> x ;

 cout << endl << "enter a y value, and then press RETURN." << endl;
 cout << "y = " ;
 cin >> y ;
 
  //  cout << endl << "the magnitude is:" <<  MagComputer(x,y) << endl ;

  cout << endl<< "the magnitude of a vecotor with x coord x=" << x
       << " and y coord y=" << y << " is " << MagComputer(x,y) 
       << endl << endl ;

  return 0;

}

double MagComputer(double i, double j){
  
  double mag ;
  mag = sqrt( pow(i,2.0) + pow(j,2.0) ) ;
  return mag;
  
}

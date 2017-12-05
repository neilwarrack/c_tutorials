/*                                                                            *
* N. Warrack                                                                  *
* Program to compute the magnitude r of a 3D vector from a file containing 3  *
* colums: "x y z" and print "x y z r" to a new line of a new file             *
* "output3D_float.txt".                                                       *
*                                                                             *
*   NB: This program has functionality to recognise the dimensionality of     *
*       the input file and therefor could be modified to accept 2D or 3D      *
*       input file as an argument from the command line.                      *
*/


#include <iostream>
#include <cmath>    
#include <cstdlib>
#include <fstream>
#include <sstream>


using namespace std;

double MagComputer(double,double);        //prototype
double MagComputer(double,double,double); //prototype
int dimensionCounter(ifstream&);          //prototype

int main(){

  ifstream mydata;
  // Now open an existing input file...
  mydata.open("input3D_float.txt");
  // check that operation worked...
  if ( mydata.fail() ) {
    cout << "Sorry, couldn’t open file input3D_float.txt -- "
	 << "It does not exisit in this location!\n" ;
    return 1; 
  }

  // count number of columns in input file
  int dim = dimensionCounter(mydata) ;
  cout << "dimensionality = " << dim << endl ;

  // Now create an output file...
  ofstream myfile;
  myfile.open ("output3D_float.txt");

  // define constants and variables
  double x, y, z, r;
  int lineCounter = 0;

  // read from file, compute magnitudes and write to file
      if (dim == 2) { // if 2D
  while ( !mydata.eof() ){
    mydata >> x >> y ;
    if ( !mydata.eof() ) {
      lineCounter++;

      r = MagComputer(x,y);

      cout << "x=" << x << "; y=" << y 
	   << "; magnitude of position vector (x,y) is: " << r
	   << endl;

      myfile << x << " " << y << " " << r << endl ;
    }
  }
      }
      else { // if 3D
	while ( !mydata.eof() ){
	  mydata >> x >> y >> z ;
	  if ( !mydata.eof() ) {
	    lineCounter++;
	    
	    r = MagComputer(x,y,z);
	    cout << "x=" << x << "; y=" << y << "; z=" << z 
		 << "; magnitude of position vector (x,y,z) is: " << r
		 << endl;
	    myfile << x << " " << y << " " << z << " " << r << endl ;
	  } 
	}
      }
      
      cout << endl << lineCounter << " lines read from file\n" << endl;
      
      // close when finished
      mydata.close();
      myfile.close();
      
      return 0;
      
}


// process to count dimensionality of input data file
int dimensionCounter(ifstream& dat){

  /// get the first line from the input file
  string line ; 
  getline( dat, line ) ;
  
  /// creat a string that treats space-seperated values as elements
  stringstream dataElements(line) ;
  double component ; // is not used directly!
  int dimCtr = 0 ;

  /// while the first line of the input file has components, increase a counter
  while (dataElements >> component) // IS THERE A BETTER/NEATER WAY TO DO THIS???
    dimCtr++ ;
  
  /// return ifstream to beginning of input file
  dat.seekg(0, ios::beg);
  
  return dimCtr ;
}


double MagComputer(double i, double j){
  
  double mag ;
  mag = sqrt( pow(i, 2.0) + pow(j, 2.0) ) ;
  return mag;
  
}


double MagComputer(double i, double j, double k){
  
  double mag ;
  mag = sqrt( pow(i, 2.0) + pow(j, 2.0) + pow(k, 2.0) ) ;
  return mag;

}


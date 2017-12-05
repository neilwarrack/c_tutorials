/*                                                                            *
* N. Warrack                                                                  *
* Program to compute the magnitude r of a 3D vector from a file containing 3  *
* colums: "x y z" and print "x y z r" to a new line of a new file             *
* "output3D_float.txt". Main takes number of rows to calculate as an argument.*
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
#include "vector.h"          // this includes namespace std
#include "datafileprocess.h" // must come after vector.h


int main(int argc , char *argv[]){

  // return error if no argument is passed or if >1 argument is passed
  if (argc < 2 || argc > 2) {
    cout << "ERROR: You must run this program with an intiger argument after the\n"
	 << "program's name. This integer specifies for how many lines of\n" 
	 << "the data file you would like to calculate the vector magnitude.\n\n"
	 << "For example:\n$ ./thisScript.sh 3\n"
	 << "will calculate the vector magnitude for three lines of the input\n"
	 << "file.\n" << endl ;
    return 1; }

  
  // convert used defined argument to an integer 
  int userDefArg = atoi(argv[1]) ;

  
  // return error if user defined argument is less than zero
  if ( userDefArg < 0 ){
    cout << "ERROR: User defined argument must be non-negative.\n";
    return 1; }
  

  ifstream mydata;
  // Now open an existing input file...
  mydata.open("input2D_float.txt");
  // check that operation worked...
  if ( mydata.fail() ) {
    cout << "Sorry, couldn’t open file input3D_float.txt -- "
	 << "It does not exisit in this location!\n" ;
    return 1; 
  }

  // count number of columns in input file
  int dim = dimensionCounter(mydata) ;

 
  // count the number of lines in the file
  int line_tot = 0 ;
  line_tot = lineCounter(mydata) ;

 
  // Now create an output file...
  ofstream myfile;
  myfile.open ("output3D_float.txt");


  //define constants and variables
  double x=0, y=0, z=0, r=0;
  
  mydata.clear();
  mydata.seekg(0, ios::beg);    


  int linectr = 0 ;  // initialise line counter 
                     // (for user output to screen at end of script)


  if (dim == 2) {  // if 2D
    for ( int l=1 ; (l <= userDefArg && l <= line_tot) ; l++) {
      

      linectr = l ;  //count line.
      mydata >> x >> y ;
      r = MagComputer(x,y);
      
      //write to file
      myfile << x << " " << y << " " << r << endl ;    
    }
  }
  else {  // if 3D
    for( int m=1 ; (m <= userDefArg && m <= line_tot) ; m++) {

      linectr = m ;  // count line
      mydata >> x >> y >> z ;
      r = MagComputer(x,y,z);

      //write to file
      myfile << x << " " << y << " " << z << " " << r << endl ;
   
    
    }
  }

  //  >>>>>>>>>>>>>>>>> PRINT TO SCREEN >>>>>>>>>>>>>>>>>>>>>>
  //return infor to user based on ther input and processes carried out.
  if ( linectr == userDefArg ){
    cout << "Process complete, " << userDefArg << " lines written "
	 << "to file.\n";
  }
  else{ 
    cout << "you have reached the end of the input file,\n"
	 << "there were only " << linectr << " lines but you requested "
	 << userDefArg << ".\n"
	 << "Process terminated. Output file created up to\n" 
	 << "line " << linectr << "." << endl ;
  }
  //  >>>>>>>>>>>>> END OF PRINT TO SCREEN >>>>>>>>>>>>>>>>>


 
  // close when finished
  mydata.close();
  myfile.close();
  

  return 0;
  
}



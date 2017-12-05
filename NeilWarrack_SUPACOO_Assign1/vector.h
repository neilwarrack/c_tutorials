#ifndef VECTORS_H
#define VECTORS_H

using namespace std;

template<class myType>
myType MagComputer(myType i, myType j){
  myType mag ;
  mag = sqrt( pow(i,2.0) + pow(j,2.0) ) ;
  return mag;
}

template<class myType>
myType MagComputer(myType i, myType j, myType k){
  myType mag ;
  mag = sqrt( pow(i,2.0) + pow(j,2.0) + pow(k, 2.0) ) ;
  return mag;
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

#endif

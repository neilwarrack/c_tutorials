#ifndef MAGCOMPUTER_H
#define MAGCOMPUTER_H

template<class myType>
myType MagComputer(myType i, myType j){
  myType mag ;
  mag = sqrt( pow(i,2.0) + pow(j,2.0) ) ;
  return mag;
}


#endif

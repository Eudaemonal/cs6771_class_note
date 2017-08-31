/* Copyright (c) 2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>

#include "test.hpp"

using namespace std;

/*
Lvalue reference: 
++i 

Rvalue reference:
i++


*************************

generally avoid bind


 */


class Line {
   public:
      void setLength( double len );
      double getLength( void );
      Line(double len);  // This is the constructor
      ~Line();
   private:
      double length;
};
 
// Member functions definitions including constructor
Line::Line( double len) {
   cout << "Object is being created, length = " << len << endl;
   length = len;
}

Line::~Line(void){
	cout  << "Object is being deleted"<<endl;
}
 
void Line::setLength( double len ) {
   length = len;
}
 
double Line::getLength( void ) {
   return length;
}



// Main function for the program
int main( ) {
   Line line(10.0);
 
   // get initially set length.
   cout << "Length of line : " << line.getLength() <<endl;
	
   // set line length again
   line.setLength(6.0); 
   cout << "Length of line : " << line.getLength() <<endl;
 
   return 0;
}

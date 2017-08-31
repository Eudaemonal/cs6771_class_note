/**
	Copyright (c) 2017 Eudaemon <eudaemonal@gmail.com> 
	test.cpp
	Purpose:

	@author: Eudaemon
	@version:  
*/
/**
	

	@param
	@return 
*/


#include <iostream>
#include "test.h"

class Foo{
public:
	  Foo( int x ) 
        {
                std::cout << "Foo's constructor " 
                          << "called with " 
                          << x 
                          << std::endl; 
        }
};

class Bar : public Foo{
public:
	Bar(): Foo(10) {std::cout << "Bar Constructor\n"; }
};

int main(int argc, char* argv[]){
	Bar bar;

	return 0;
}

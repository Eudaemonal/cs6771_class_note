/**	Copyright (c) 2017 Eudaemon <eudaemonal@gmail.com> 
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

int globalvar = 20;

int& foo() {
	return globalvar;
}


int main(int argc, char* argv[]){
	const int a = 5;
	

	foo() = 10;


	std::cout << foo() <<std::endl;
	return 0;
}

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

struct Sample{
	Sample(){
		std::cout << "Constructor\n";
	}
	~Sample(){
		std::cout << "Destructor\n";
	}
};


void deleter(Sample *x){
	std::cout << "Deleter Function\n";
	delete[] x;
}

int main(int argc, char* argv[]){
	std::shared_ptr<Sample> p3(new Sample[12], deleter);


	return 0;
}

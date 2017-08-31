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

struct Sample{
	Sample(){
		std::cout << "Constructor\n";
	}
	~Sample(){
		std::cout << "Destructor\n";
	}
};


class Deleter{
	public:
	void operator() (Sample *x){
		std::cout<< "Deleter function\n";
		delete[] x;
	}
};



int main(int argc, char* argv[]){
	std::shared_ptr<Sample> p3(new Sample[1], Deleter());

	std::shared_ptr<Sample> p4(new Sample[1], [](Sample *x){
		std::cout << "DELETER FUNCTION\n";
		delete[] x;
	});

	return 0;
}

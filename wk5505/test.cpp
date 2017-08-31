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

class Example {

public:
	Example(int x): total(x) {}
	Example(): Example(0) {}

	~Example() {}
		
	void accumulate(int x) {total+=x; }
	int getTotal(){return total;}
private:
	int total;

};


int main(int argc, char* argv[]){
	Example ex1(2);
	ex1.Example::accumulate(10);

	std::cout << ex1.Example::getTotal() <<std::endl;

	Example ex2;
	std::cout << ex2.Example::getTotal() <<std::endl;

	

	return 0;
}

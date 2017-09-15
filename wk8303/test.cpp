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
#include <memory>


int main(int argc, char* argv[]){
	int *p = new int(10);
	std::shared_ptr<int> a(p);

	if(a.get()==p)
		std::cout << "a and p point to the same location\n";
	std::cout << *a.get() << "\n";
	std::cout << *a << "\n";
	std::cout << *p << "\n";

	return 0;
}

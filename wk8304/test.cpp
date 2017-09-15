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
	std::shared_ptr<int> foo;
	std::shared_ptr<int> bar(new int);

	std::cout << std::boolalpha;// convert bool 0/1 to false/true
	std::cout << bar.unique() <<std::endl;
	std::cout << foo.unique() <<std::endl;

	foo = bar;

	std::cout << bar.unique() <<std::endl;
	std::cout << foo.unique() <<std::endl;
	

	return 0;
}

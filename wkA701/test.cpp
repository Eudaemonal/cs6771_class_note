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


int main(int argc, char* argv[]){
	std::pair <int, int> foo;
	std::pair <int, int> bar;

	foo = std::make_pair(10, 20);
	bar = std::make_pair(10.5, 'A');

	std::cout << "foo: " << foo.first <<", "<< foo.second << std::endl;
	std::cout << "bar: " << bar.first <<", "<< bar.second << std::endl;


	return 0;
}

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
#include <vector>
#include <list>
#include "test.h"


int main(int argc, char* argv[]){
	int size = 3;

	std::vector<int> v(size);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;

	for(int i = 0; i< size; ++i)
		std::cout << v[i] <<std::endl;


	return 0;
}

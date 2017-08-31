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


int main(int argc, char* argv[]){

	std::shared_ptr<int> p3(new int[12]);

	std::cout << p3.use_count() <<std::endl;
	
	return 0;
}

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


auto multiply(int x, int y)->int{
	return x * y;
}


int main(int argc, char* argv[]){
	int x = 10;
	int y = 20;
	std::cout << multiply(x, y) << std::endl;

	return 0;
}

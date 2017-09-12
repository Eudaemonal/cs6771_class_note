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
#include "test.h"


int main(int argc, char* argv[]){
	std::vector<int> a = {1,2,3};
	auto it = a.rbegin();
	std::cout << *it << "\n";

	return 0;
}

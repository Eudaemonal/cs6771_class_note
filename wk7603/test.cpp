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


template <typename Builder>
auto
makeAndProcessObject(const Builder& builder)->decltype(builder.makeObject){
	auto val = 
}




int main(int argc, char* argv[]){
	int x = 3;
	decltype(x) y = x;

	std::cout << y <<std::endl;	

	return 0;
}

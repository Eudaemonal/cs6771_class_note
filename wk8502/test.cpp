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



void foo(unsigned int i){
	std::cout << "unsigned " << i <<std::endl;
}

template <typename T>
void foo(const T& t){
	std::cout << "template "<< t <<std::endl;
}


int negate(int i){
	std::cout << "integer \n";
	return -i;
}

template <typename T>
typename T::value_type negate(const T& t){
	std::cout << "template \n";
	return -t;
}


int main(int argc, char* argv[]){
	foo(42);
	foo("hello");

	std::cout << negate(42) <<std::endl;

	return 0;
}

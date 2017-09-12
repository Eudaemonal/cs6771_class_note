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
#include <string>
#include "test.h"


template<int plus, typename T, int size>
T minplus(const T(&a)[size]){
	T min = a[0];
	for(int i = 1;i<size; i++)
		if(a[i]<min) min = a[i];
	min +=plus;
	std::cout << "answer is: " << min << std::endl;
	return min;
}


int main(int argc, char* argv[]){
	std::string x[] = {"a","b","c"};

	std::cout << minplus<5>(x) << std::endl;

	return 0;
}

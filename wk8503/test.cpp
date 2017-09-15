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
#include <vector>
#include <string>

template <typename T>
void printVector(std::vector<T> t){
	for( unsigned int i=0;i!=t.size();++i)
		std::cout << t[i] << ", ";
	std::cout << std::endl;
}



int main(int argc, char* argv[]){
	std::vector<int> v1(4,8);
	std::vector<std::string> v2(2, "ab");


	printVector(v1);
	printVector(v2);

	
	return 0;
}

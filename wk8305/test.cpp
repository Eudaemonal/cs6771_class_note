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
#include <algorithm>
#include <vector>

bool isOdd(int i){
	return ((i%2)==1);
}

int main(int argc, char* argv[]){
	std::vector<int> myvector;

	myvector.push_back(10);
	myvector.push_back(25);
	myvector.push_back(40);
	myvector.push_back(55);
	
	std::vector<int>::iterator it = std::find_if(myvector.begin(), myvector.end(), isOdd);
	std::cout <<"First odd value is : "<< *it <<std::endl;

	return 0;
}

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
#include <list>
#include "test.h"


int main(int argc, char* argv[]){
	int size = 3;
	std::list<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	for(int i = 0; i<size; ++i){
		std::cout << l.front() <<std::endl;
		l.pop_front();	
	}
	
	return 0;
}

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

template <typename T> 
void printVec(T begin, T end){
	for (auto it = begin;it!=end;++it)
		std::cout << *it<<"\n";

}


int main(int argc, char* argv[]){
	std::vector<int> v={1,2,3};
	printVec(v.begin(), v.end());

	std::list<double> l = {1.2, 3.4, 5.6};
	printVec(l.begin(), l.end());
	
	return 0;
}

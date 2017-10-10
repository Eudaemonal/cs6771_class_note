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
#include <vector>
#include "test.h"


int main(int argc, char* argv[]){
	std::vector<int> v= {10,20,30};

	auto it = v.emplace(v.begin()+1, 100);
	v.emplace(it, 200);
	v.emplace(v.end(), 300);
	
	std::cout << "myvector contains:";
	for (auto& x: v)
		std::cout << ' ' << x;
	std::cout << '\n';
	return 0;
}

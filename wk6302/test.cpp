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
#include "test.h"


int main(int argc, char* argv[]){
	std::shared_ptr<int> p1(new int());
	*p1 = 78;
	std::cout << *p1 <<std::endl;
	
	
	std::shared_ptr<int> p2(p1);
	std::cout << p2.use_count() <<std::endl;
	std::cout << p1.use_count() <<std::endl;

	if(p1==p2)
		std::cout << "p1 and p2 same\n";
	p1.reset();
	
	std::cout << p1.use_count() <<std::endl;

	p1.reset(new int(11));
	std::cout <<p1.use_count() <<std::endl;
	
	p1 = nullptr;
	std::cout <<p1.use_count() <<std::endl;
	
	

	return 0;
}

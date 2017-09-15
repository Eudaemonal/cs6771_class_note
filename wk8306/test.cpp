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
#include <memory>

int main(int argc, char* argv[]){
	std::shared_ptr<int> sp1, sp2;
	std::weak_ptr<int> wp;

	sp1 = std::make_shared<int> (20);
	wp = sp1;

	sp2 = wp.lock();


	return 0;
}

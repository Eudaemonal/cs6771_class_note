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

struct Sample{
	void Hahaha(){
		std::cout <<"Hahaha" <<std::endl;
	}
	void Hehehe(){
		std::cout << "Hehehe" <<std::endl;
	}
};

int main(int argc, char* argv[]){
	std::shared_ptr<Sample> ptr = std::make_shared<Sample>();
	ptr->Hahaha();
	ptr->Hehehe();
	(*ptr).Hahaha();

	std::cout << ptr.use_count() <<std::endl;


	std::shared_ptr<Sample> ptr2(ptr);

	if(ptr==ptr2)
		std::cout << "ptr1 and ptr2 are equal" <<std::endl;

	std::cout << ptr.use_count() <<std::endl;

	return 0;
}

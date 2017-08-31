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


std::string getName ()
{
    return "hehehe";
}


void printReference (const std::string& str)
{
	std::cout <<"First: ";
	std::cout << str << std::endl;
}
 
void printReference(std::string&& str)
{
	std::cout << "Second: ";	
	std::cout << str << std::endl;
}

int main(int argc, char* argv[]){
	std::string s = "hahaha";
	printReference(s);
	printReference(getName());

	return 0;
}

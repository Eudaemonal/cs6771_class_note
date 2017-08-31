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


class Example4 {
	std::string* ptr;
public:
	Example4() :ptr(new std::string) {}
	Example4 (const std::string& str): ptr(new std::string(str)) {}
	Example4 (const Example4& x): ptr(new std::string(x.content())) {} // copy constructor

	~Example4() {delete ptr;}
	const std::string& content() const {return *ptr;}
};




int main(int argc, char* argv[]){
	Example4 foo("Example");
	Example4 bar = foo;

	std::cout << foo.content() <<std::endl;

	return 0;
}

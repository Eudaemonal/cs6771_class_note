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

class Example3 {
private:
	std::string data;
public:
	Example3 (const std::string& str): data(str) {
		std::cout << "Constructor(1)\n";
	}
	Example3 () {
		std::cout << "Constructor()2\n";
	}
	~Example3() {
		std::cout << "Destructor\n";
	}
	const std::string& content() const {return data;}

};


int main(int argc, char* argv[]){
	Example3 foo;
	Example3 bar("Example");

	std::cout << bar.Example3::content() <<std::endl;
	std::cout << foo.Example3::content() <<std::endl;

	return 0;
}

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


class A {
public:
	void foo() const { std::cout <<"A::foo() const\n";}
	void foo() {std::cout << "A::foo()\n";}
};

A bar(){ return A(); }
const A cbar() {return A();}


int main(int argc, char* argv[]){
	bar().foo();
	cbar().foo();

	return 0;
}

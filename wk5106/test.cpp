/* Copyright (c) 2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>
#include "test.hpp"


int main(int argc, char* argv[]){
	int i1{1};
	int i2 = {2};
	int i3 = 3;
	int i4(4);
	int i5 = int{5};


	std::cout << i1 <<std::endl;
	std::cout << i2 <<std::endl;
	std::cout << i3 <<std::endl;
	std::cout << i4 <<std::endl;
	std::cout << i5 <<std::endl;

	return 0;
}

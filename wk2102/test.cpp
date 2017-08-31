/* Copyright (c) 2016-2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>
#include <string>
#include "test.hpp"

/*
Not work for blank name(heading space), get_line to get space

*/

using namespace std;

int main(int argc, char* argv[]){
	std::string name, greeting;

	std::cout << "Please enter your first name: ";
	while(std::cin >> name) {
		greeting = "Hello, " + name + "!";
		std::cout << greeting << std::endl << std::endl;
		std::cout << "Please enter your first name: ";
	}

    
    return 0;
}

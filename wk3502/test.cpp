/* Copyright (c) 2016-2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>
#include <string>
#include "test.hpp"

using namespace std;

class Sales_data {
public:
	Sales_data(const string &s): bookNo{s} { ++counter; }

	explicit Sales_data(const std::string &s): bookNo{s} { }

	
private:
	std::string bookNo;
	unsigned units_sold{0}; // in-class initialiser
	double revenue{0.0}; // in-class initialiser
	// Count how many objs are created by this constructor
	static int counter;
};



int main(int argc, char* argv[]){

    
	return 0;
}

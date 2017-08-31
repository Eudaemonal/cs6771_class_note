/* Copyright (c) 2016-2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>
#include <iomanip>
#include "test.hpp"


/*
namespace - local variable: priority to local variable


*/

using namespace std;

int main(int argc, char* argv[]){
	cout << 1331 << std::endl;
	cout << "In hex " << std::hex << 1331 << std::endl;
	cout << 1331.123456 << std::endl;
	cout.setf(std::ios::scientific, std::ios::floatfield);
	cout << 1331.123456 << std::endl;
	cout << std::setprecision(3) << 1331.123456 << std::endl;
	cout << std::dec << 1331 << std::endl;
	cout.fill('X');
	cout.width(8);
	cout << 1331 << std::endl;
	cout.setf(std::ios::left, std::ios::adjustfield);
	cout.width(8);
	cout << 1331 << std::endl;

    return 0;
}

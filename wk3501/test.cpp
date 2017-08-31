/* Copyright (c) 2016-2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>

#include "test.hpp"

using namespace std;

/*



*/

void f(double aDouble){
	int i{int{aDouble}};
	cout << i <<endl;
}

int main(int argc, char* argv[]){
	cerr << "Error" <<endl;
	f(2);
	return 0;
}

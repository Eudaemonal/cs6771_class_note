/* Copyright (c) 2016-2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>

#include "test.hpp"

using namespace std;

int main(int argc, char* argv[]){
	short a = 2000;
	int b;
	cout <<a<<endl;
	b = (int) a;
	cout << b <<endl;
	b = int (a);
	cout << b <<endl;

	return 0;
}

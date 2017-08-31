/* Copyright (c) 2016-2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>

#include "test.hpp"

using namespace std;

int main(int argc, char* argv[]){
	cout << "Enter two numbers:" <<endl;
	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;
	cout << "the sum of " << v1 << " and "<< v2 
		 << " is " << v1+v2 <<endl;
    
    return 0;
}

/* Copyright (c) 2016-2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>

#include "test.hpp"

using namespace std;

int main(int argc, char* argv[]){

	/*
	int i = 5;
	int j = 6;
    const int *const p = &i;
	*p =  6;
	p = &j;


	int i;
	long &r = i; // error
	*/

	//Mixing Pointers and References
	int i = 5;
	int *p;
	int *&r = p;


    return 0;
}

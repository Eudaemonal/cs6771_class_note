/* Copyright (c) 2016-2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>
#include <vector>
#include "test.hpp"


/*
Containers: deque, list, vector, map
Algorithms
Iterators

*/
using namespace std;

int main(int argc, char* argv[]){
	vector<int> v;
	v.reserve(10);
	int i;

	cout << "vector size = " << v.size() <<endl;

	for(i=0;i<5; i++){
		v.push_back(i*2);
	}
	cout << "extended vector size = " << v.size() <<endl;

	cout << v[0] << v[1] << v[3] <<endl;

	try{
		v.at(0) = 12;
	}
	catch(out_of_range o){
		cout<<o.what()<<endl;
	}
	cout << v[0] << v[1] << v[3] <<endl;    
	cout << "capacity " << v.capacity() << endl;
	cout << "size " << v.size() <<endl;

    return 0;
}

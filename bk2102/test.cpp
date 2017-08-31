/* Copyright (c) 2016-2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>
#include <deque>
#include "test.hpp"

using namespace std;

int main(int argc, char* argv[]){
	deque<double> dq(5,8.2);
	int i;
	cout << dq.size() <<endl;

	for(i=0;i<dq.size() ;i++)
		cout << dq.at(i) << " " ;
    cout << endl;

	dq.push_back(8.1);

	for(i=0;i<dq.size() ;i++)
		cout << dq.at(i) << " " ;
    cout << endl;

	dq.pop_back();
	dq.push_front(7.9);
	for(i=0;i<dq.size() ;i++)
		cout << dq.at(i) << " " ;
    cout << endl;

	dq.pop_front();
	for(i=0;i<dq.size() ;i++)
		cout << dq.at(i) << " " ;
    cout << endl;


    return 0;
}

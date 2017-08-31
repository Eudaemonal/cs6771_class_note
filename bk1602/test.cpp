/* Copyright (c) 2016-2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>

#include "test.hpp"

using namespace std;

// pg 50

int main(int argc, char* argv[]){
	int currVal = 0, val = 0;
	if(cin >> currVal) {
		int cnt = 1;
		while(cin >> val){
			if(val == currVal)
				++cnt;
			else{
				cout << currVal << " occurs " << cnt <<"times" << endl;
				currVal = val;
				cnt = 1;
			}
		}
		cout << currVal << " occurs " << cnt <<"times" << endl;
	}
    
    return 0;
}

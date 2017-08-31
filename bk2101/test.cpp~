/* Copyright (c) 2016-2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>
#include <vector>
#include "test.hpp"

using namespace std;


class X{
public:
	X():val_(0){}
	X(int val):val_(val){}
	int get(){return val_;}
	void set(int val){val_=val;}
private:
	int val_;
};

int main(int argc, char* argv[]){
	vector<X> ax;

	cout << "Vector Empty? "<<ax.empty() <<endl;

    ax.resize(10);             // resize the controlled sequence
	for(int i=0; i<10; ++i){
		ax[i].set(i);          // set each element's value
	}
	
	cout << ax[1].get() <<endl;
	cout << "Vector Empty? "<<ax.empty() <<endl;

	ax.push_back(X(6));
	cout << ax[10].get() << " size: "<<ax.size()<<endl;

	
	ax.pop_back();	
	cout << ax[10].get() << " size: "<<ax.size()<<endl;
	


    return 0;
}

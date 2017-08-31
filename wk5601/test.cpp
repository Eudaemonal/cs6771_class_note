/**
	Copyright (c) 2017 Eudaemon <eudaemonal@gmail.com> 
	test.cpp
	Purpose:

	@author: Eudaemon
	@version:  
*/
/**
	

	@param
	@return 
*/


#include <iostream>
#include "test.h"
#include <vector>
#include <list>


class Arr {
private:
	int size_;
	double *arr_;
public:
	Arr (const int n) : Arr(n,0) {}
	Arr (const int n, const double v): size_(n) {
		arr_ = new double[size_];
		for(int i= 0; i<size_;i++)
			arr_[i] = v;
	}
	
	Arr (std::vector<double>::iterator begin, std::vector<double>::iterator end): size_(end-begin){
		arr_ = new double[size_];
		for(std::vector<double>::iterator it= begin; it!=end;++it)
			arr_[it-begin] =  *it;
	}

	Arr(std::initializer_list<double> arr): size_(arr.end()-arr.begin()){
		arr_ = new double[size_];
		for(auto it= arr.begin(); it!=arr.end();++it)
			arr_[it-arr.begin()] = *it;
	}

	// copy constructor
	Arr(const Arr& arr): size_(arr.size_), arr_(arr.arr_) {}

	// move constructor
	Arr(const Arr&& arr): size_(std::move(arr.size_)), arr_(std::move(arr.arr_)) {}
	
	// destructor
	~Arr(){
		delete[] arr_;
	}

	/*  operators
	 *  
	 * */
	// copy operator
	Arr& operator=(const Arr& arr){
		if (this != &arr) {
			size_ 	= arr.size_;
			arr_ = arr.arr_;
		}
		return *this;
	}

	// move operator
	Arr& operator=(const Arr&& arr){
		if (this != &arr) {
			size_ 	= std::move(arr.size_);
			arr_ = std::move(arr.arr_);
		}
		return *this;
	}


	/*  test functions
	 *
	 * */
	const int size() const {return size_;}
	void info(){
		std::cout << "size: " << size_ <<std::endl;
		for(int i=0;i<size_; ++i)
			std::cout << "  " << arr_[i];
		std::cout << "\n\n";

	}
};



int main () {
	Arr a1 (2);
	Arr a2(3,5.0);
	
	a1.info();
	a2.info();

	std::vector<double> a{1.2,2.6,3.5};
	Arr a3{a.begin(), a.end()};
	a3.info();

	Arr a4 {1.2,2.2,3.2,4.2};
	a4.info();

	Arr a5(a4);
	a5.info();

	return 0;
}


/**	Copyright (c) 2017 Eudaemon <eudaemonal@gmail.com> 
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

template <typename T>
struct numeric_limits{
	static T max() {return T{};}
	static T min() {return T{};}
};

template <>
struct numeric_limits<int> {
	static int max() {return INT_MAX; }
	static int min() {return INT_MIN; }
};



template <typename T, typename U>
auto findmin(U begin, U end){
	//using T = decltype(*begin);
	auto min = std::numeric_limits<T>::max();
	for(;begin!=end; ++begin)
		min = std::min(*begin, min);
	return min;
}


int main(int argc, char* argv[]){
	std::cout <<std::numeric_limits<int>::min() << std::endl;
	std::cout <<std::numeric_limits<int>::max() << std::endl;

	std::vector<int> vi{5, 1, 2, 3, 7, 4};
	std::vector<int> vempty;
	std::vector<std::string> vs{"hello", "world"};


	std::cout << "min of vi is " << findmin<int>(vi.cbegin(), vi.cend()) <<std::endl;
	std::cout << "min of vempty is " << findmin<int>(vempty.cbegin(), vempty.cend())<<std::endl;
	
	std::cout << "min of vs is " << findmin<std::string>(vs.cbegin(), vs.cend()) << std::endl;

	

	return 0;
}

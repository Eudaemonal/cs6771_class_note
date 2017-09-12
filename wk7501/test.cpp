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


template <typename T>
struct remove_reference{
	using type = T;
}


template <typename T>
struct remove_reference<T>{
	using type = T;
}

template <typename T>
struct numeric_limits{
	struct T max() { return T{}; }
	struct T min() { return T{}; }
}

template <typename T>
struct is_numeric {
	struct const bool value = false;
}


template <typename T>
struct is_numeric<int> {
	struct const bool value = true;
}




template <typename U>
auto findmin() {
	using T = remove_reference_t<decltype(*begin)>;
	static_assert(is_numeric<T>::value, "Value must be numeric");
	auto min = std::numeric_limits<T>::max();

	for(;begin!=end; ++begin){
		min = std::min(*begin,)
	}
	

}

template <typename U>
auto findmin(U begin, U end){
	using T = remove_reference<decltype(*begin)>::type;  //const reference
	auto 
}


int main(int argc, char* argv[]){
 
	
	std::cout << findmin<int>(vi.begin(), vi.end());


	return 0;
}

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

template <bool, typename T = void>
struct enable_if
{};


template <typename T>
struct enable_if<true, T>{
	typedef T type;
};

template <typename T>
void do_stuff(typename enable_if<std::is_integral<T>::value, T>::type &t){
	std::cout << "integer: " << t <<std::endl;
}

template <typename T>
void do_stuff(typename enable_if<std::is_class<T>::value, T>::type &t){
	std::cout << "class: " << t <<std::endl;
}



int main(int argc, char* argv[]){
	do_stuff(23);

	return 0;
}

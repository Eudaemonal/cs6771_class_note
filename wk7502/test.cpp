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


///////////////////////////////////

template <unsigned n>
struct Fib{
	static const unsigned val = Fib<n-1>::val + Fib<n-2>::val;
};

template <unsigned n>
struct Fib<0>{
	static const unsigned val = 0;
};

template <unsigned n>
struct Fib<1>{
	static const unsigned val = 1;
};


/////////////////////////////////
struct factorial {
	static const unsigned val = n * factorial<n-1>::val;
}

template <unsigned n>
struct factorial<0>{
	static const unsigned val = 1;
}
/////////////////////////////////

constexpr unsigned factorial(n){
	if(n==0)
		return 1;
	factorial(n-1)
}


int main(int argc, char* argv[]){
	

	return 0;
}

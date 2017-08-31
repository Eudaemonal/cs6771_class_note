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


#include<memory>
typedef struct Sample {
	Sample() {
    	
    	std::cout<<"Constructor"<<std::endl;
	}
~Sample() {
    std::cout<<"Destructor"<<std::endl;
	}
}Sample;


int main()
{
    {
    Sample * rawPtr = new Sample();
    std::shared_ptr<Sample> ptr_1(rawPtr);
 
        {
        std::shared_ptr<Sample> ptr_2(rawPtr);
        }
// As ptr_2 dont know that the same raw pointer is used by another shared_ptr i.e. ptr_1, therefore
// here when ptr_2 goes out of scope and it deletes the raw pointer associated with it.
 
// Now ptr_1 is internally containing a dangling pointer. Therefore when we it
// will go out of scope it will again try to delete the already deleted raw pointer and application
// will crash.
    }
return 0;
}



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
#include <thread>
#include <mutex>
#include "test.h"


int main(int argc, char* argv[]){
	int i = 1;
	const long numIterations = 1000000;
	std::mutex iMutex;
	std::thread t1([&] {
		for (int j = 0; j < numIterations; ++j) {
			std::lock_guard<std::mutex> guard(iMutex);
			i++;
		}
	});

	std::thread t2([&] {
		for (int j = 0; j < numIterations; ++j) {
			std::lock_guard<std::mutex> guard(iMutex);
			i--;
		}
	});
	t1.join();
	t2.join();
	std::cout << i << std::endl;

	return 0;
}

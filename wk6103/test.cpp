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
#include <tuple>
#include <functional>

int main()
{
  auto first = std::make_tuple (10,'a');             // tuple < int, char >

  const int a = 0; int b[3];                         // decayed types:
  auto second = std::make_tuple (a,b);               // tuple < int, int* >

  auto third = std::make_tuple (std::ref(a),"abc");  // tuple < const int&, const char* >

  std::cout << "third contains: " << std::get<0>(third);
  std::cout << " and " << std::get<1>(third);
  std::cout << std::endl;

  return 0;
}


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


class Node {
private:
	int value;
public:
	std::shared_ptr<Node> leftPtr;
	std::shared_ptr<Node> rightPtr;
	Node(int val) : value(val){
		std::cout << "Constructor: " << value << "\n";
	}
	~Node(){
		std::cout << "Destructor\n";
	}

	int get(){
		return value;
	}
};

int main(int argc, char* argv[]){
	std::shared_ptr<Node> ptr = std::make_shared<Node>(4);
	ptr->leftPtr = std::make_shared<Node>(2);
	ptr->rightPtr = std::make_shared<Node>(5);
	
	std::cout << ptr->get() <<std::endl;
	std::cout << ptr->leftPtr->get() <<std::endl;

	return 0;
}

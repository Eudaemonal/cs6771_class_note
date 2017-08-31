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
#include <memory>
#include "test.h"

class Node {
private: 
	int value;
public:
	std::shared_ptr<Node> leftPtr;
	std::shared_ptr<Node> rightPtr;
	std::shared_ptr<Node> parentPtr;

	Node(int val) : value(val){
		std::cout << "Constructor: " << value << "\n"; 
	}
	~Node(){
		std::cout << "Desctuctor\n";
	}

};


int main(int argc, char* argv[]){
	std::shared_ptr<Node> ptr = std::make_shared<Node>(10);
	std::cout<<"ptr reference count = "<<ptr.use_count()<<std::endl;

	ptr->leftPtr = std::make_shared<Node>(2);
	ptr->leftPtr->parentPtr = ptr;
	ptr->rightPtr = std::make_shared<Node>(5);
	ptr->rightPtr->parentPtr = ptr;
	std::cout<<"ptr reference count = "<<ptr.use_count()<<std::endl;
	std::cout<<"ptr->leftPtr reference count = "<<ptr->leftPtr.use_count()<<std::endl;
	std::cout<<"ptr->rightPtr reference count = "<<ptr->rightPtr.use_count()<<std::endl;


	return 0;
}

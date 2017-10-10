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
#include "bst.h"

#define NUM 9


int main(int argc, char* argv[]){
	Node<int> list[NUM] = {45, 50, 1, 9, 44, 56, 98, 43, 32};

	Node<int> *root = NULL;

	for(int i=0;i<NUM; ++i){
		root = Node<int>::insertNode(root, (list + i));
	}

	Node<int>::walk(root);

	std::cout << *Node<int>::find(root, 43);

	
	std::cout << "Minimum: " << *Node<int>::minimum(root);
	std::cout << "Maximum: " << *Node<int>::maximum(root);

	Node<int> *nine = Node<int>::find(root, 9);
	std::cout << "9: " << *nine;
	std::cout << "Successor: " << *Node<int>::successor(nine);

	Node<int> *fortyFour = Node<int>::find(root, 44);
	std::cout << "44: " << *nine;
	std::cout << "Successor: " << *Node<int>::successor(fortyFour);

	root = Node<int>::deleteNode(root, root);
	Node<int>::walk(root);
	

	return 0;
}

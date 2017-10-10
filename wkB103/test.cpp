#include <algorithm>
#include <iostream>
#include <iterator>

#include "btree.h"


int main(void) {
	btree<char> b(4);

	b.insert('M');
	b.insert('P');
	b.insert('X');
	b.insert('G');

	b.insert('T');
	b.insert('B');
	b.insert('Z');
	b.insert('Y');
	b.insert('N');
	b.insert('R');
	b.insert('S');
	b.insert('W');

	b.insert('Q');
	b.insert('V');

	for(btree<char>::iterator iter = b.begin(); iter != b.end(); ++iter)
		std::cout << *iter <<", ";
	std::cout << std::endl;

	for(btree<char>::reverse_iterator iter = b.rbegin(); iter != b.rend(); ++iter)
		std::cout << *iter <<", ";
	std::cout << std::endl;


	btree<char> c=b;

	std::cout << "tree b\n";
	b.printNode();
	std::cout << "\n\ntree c\n";
	c.printNode();

	auto e = b.find('S');
	std::cout << *e <<std::endl;

	auto f = b.find('F');
	std::cout << *f <<std::endl;


	std::cout << "begin: "; 
	auto it1 = b.begin();
	std::cout << *it1 <<std::endl;

	std::cout << "end: "; 
	auto it2 = b.end();
	std::cout << *it2 <<std::endl;

	std::cout << "rbegin: "; 
	auto it3 = b.rbegin();
	std::cout << *it3 <<std::endl;

	
	std::cout << "rend: "; 
	auto it4 = b.rend();
	std::cout << *it4 <<std::endl;

	
	return 0;
}


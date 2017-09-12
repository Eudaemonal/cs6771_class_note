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
#include <string>
#include <memory>

namespace dgwg{
	/** Node
	*
	*/
	template<typename N, typename E>
	class Node {
	private:
		N value_;
		E weight_;
		std::shared_ptr<Node<N,E>> next_;

	public:
		Node(const N &value, const E weight) 
			: value_{value}, weight_{weight},next_{nullptr}
		{};

		Node(const N &value)
			: value_{value}, weight_{0}, next_{nullptr}
		{};
	};


}


int main(int argc, char* argv[]){
	dgwg::Node<std::string, int>("a", 2);

	return 0;
}

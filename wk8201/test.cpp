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
#include <vector>

namespace gdwg{
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

		N getv() { return value_; }
		E getw() { return weight_;}
	};

	
	/** Graph
	*
	*/
	template<typename N, typename E>
	class Graph{
	private:
		std::vector<std::shared_ptr<Node<N,E>>> node_;
		typename std::vector<std::shared_ptr<Node<N,E>>>::const_iterator iterator_;
	public:
		Graph()
		{};

		// copy constructor
		Graph(const Graph<N,E> &cpy)
		{
			for (unsigned int i = 0; i < cpy.node_.size(); ++i) {
  				auto iterator = cpy.node_[i]->getn();
				auto iterator_new = std::make_shared<Node<N, E>>(cpy.node_[i]->getv(), cpy.node_[i]->getw());
				node_.push_back(iterator_new);
				while (iterator != nullptr) {
					iterator_new->setn(std::make_shared<Node<N, E>>(iterator->getv(), iterator->getw()));
					iterator_new = iterator_new->getn();
					iterator = iterator->getn();
            			}
        		}
		}

		//move constructor
		Graph(Graph<N,E> &&cpy)
		{
			for (unsigned int i = 0; i < cpy.node_.size(); ++i)
				node_.push_back(cpy.node_[i]);
			cpy.node_.clear();
		}


		bool addNode(const N& val){

			auto insert = std::make_shared<Node<N, E>>(val);
			node_.push_back(insert);
			return true;
		
		}


		void printEdges(const N &val) const {
			if(isNode(val) == false) 
				throw std::runtime_error("can't find one of the node");
			auto node = findnode(val);
			if (node != nullptr) {
				std::cout << "Edges attached to Node " << node->getv() << "\n";
				node->printnode();
			}
		}
	};

}


int main(int argc, char* argv[]){
	// create 3 graphs
	gdwg::Graph<int,int> g;
	gdwg::Graph<std::string,double> g2{};
	gdwg::Graph<std::shared_ptr<int>,std::string> g3{};
	
	
	// add some nodes to each graph. 
	g.addNode(1);
	int i = 2;
	g.addNode(i);
	double d = 3.41;
	g.addNode(static_cast<int>(d));
	/*
	std::string s = "world";
	g2.addNode(s);
	g2.addNode("Hello");
	
	std::shared_ptr<int> sp = std::make_shared<int>(5);
	g3.addNode(sp);
	g3.addNode(std::make_shared<int>(6));
	
	// print the nodes from each graph. 
	std::cout << "Graph g nodes:" << std::endl;
	g.printNodes();
	std::cout << "Graph g2 nodes:" << std::endl;
	g2.printNodes();
	std::cout << "isNode test:" << std::endl;
	std::cout << std::boolalpha << g3.isNode(sp) << std::endl;
	*/
	return 0;
}

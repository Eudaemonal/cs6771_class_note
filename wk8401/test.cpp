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
#include <vector>
#include <tuple>
#include <string>
#include <memory>
#include <algorithm>

namespace gdwg{

	template<typename N, typename E>
	class Node{
	private:
		N data_;
		std::vector<std::tuple<E, std::shared_ptr<Node<N,E>>>> next_;

	public:
		Node()
		{};
		Node(const N &src)
			: data_(src)
		{};


		void setData(const N &src)
		{
			data_ = src;
		}


		/** Add edge to a node
			return true if edge is added to the node
			return false if edge with same weight, destination already exists
		@param 
		@return
		*/
		bool addEdge(const E &w, std::shared_ptr<Node<N,E>> d) const
		{
			for(unsigned int i=0; i!=next_.size();++i)
				if(getWeight(i) == w && getDst(i)==d)
					return false;
			next_.push_back(std::make_tuple(w, d));
			return true;
		}

		/** Delete edge from a node
			return true if edge is deleted from the node
			return false if edge with specified weight and destination not found
		@param 
		@return
		*/
		bool deleteEdge(const E &w, std::shared_ptr<Node<N,E>> d){
			for(unsigned int i=0; i!=next_.size();++i)
				if(getWeight(i) == w && getDst(i)==d){
					next_.erase(next_.begin()+i);
					return true;
				}
			return false;
		}

		N getData()
		{
			return data_;
		}

		unsigned int getNumEdge(){
			return next_.size();
		}
		
		E getWeight(const unsigned int idx){
			return std::get<0>(next_[idx]);
		}

		std::shared_ptr<Node<N,E>> getDst(const unsigned int idx){
			return std::get<1>(next_[idx]);
		}

	};

	template<typename N, typename E>
	class Graph{
	private:
		std::vector<std::shared_ptr<Node<N,E>>> arr_;

	public:
		Graph()
		{};

		
		//methods
		bool addNode(const N& val)
		{
			std::shared_ptr<Node<N,E>> n (new Node<N,E>);
			n->setData(val);
			if(isNode(val))
				return false;
			arr_.push_back(n);
			
			return true;
		}
		
		bool addEdge(const N &src, const N &dst, const E &w){
			std::shared_ptr<Node<N,E>> s (new Node<N,E>);
			std::shared_ptr<Node<N,E>> d (new Node<N,E>);

			if(!isNode(src)||!isNode(dst))
			       throw std::runtime_error("Error: One or two nodes not exist.");
			
			s = findNode(src);
			d = findNode(dst);

			return s->addEdge(w,d);
		}

		bool replace(const N& oldData, const N& newData){
			std::shared_ptr<Node<N,E>> n (new Node<N,E>);
			if(!isNode(oldData))
				throw std::runtime_error("Error: No node with oldData exist.");

			if(isNode(newData))
				return false;

			n = findNode(oldData);
			n->setData(newData);

			return true;
		}

		void mergeReplace(const N& oldData, const N& newData){
			if(!isNode(oldData)||!isNode(newData))
				throw std::runtime_error("Error: One or two nodes with specified data do not exist.");
			std::shared_ptr<Node<N,E>> old_node (new Node<N,E>);
			old_node = findNode(oldData);

			std::shared_ptr<Node<N,E>> new_node (new Node<N,E>);
			new_node = findNode(oldData);

			for(unsigned int i=0; i!=old_node->getNumEdge();++i)
				new_node->addEdge(old_node->getWeight(i), old_node->getDst(i));
			
			deleteNode(old_node);
		}

		void deleteNode(const N& val) noexcept{
			for(unsigned int i = 0; i<arr_.size(); ++i)
				if(arr_[i]->getData() == val)
					arr_.erase(arr_.begin()+i);
		}

		void deleteEdge(const N& src, const N& dst, const E& w) noexcept {
			if(!isNode(src))
				return;
			std::shared_ptr<Node<N,E>> s (new Node<N,E>);
			std::shared_ptr<Node<N,E>> d (new Node<N,E>);

			s = findNode(src);
			d = findNode(dst);

			s->deleteEdge(w,d);					
		}

		void clear() noexcept{
			arr_.clear();
		}


		bool isNode(const N &val) const{
			for(unsigned int i = 0; i<arr_.size(); ++i){
				if(arr_[i]->getData() == val)
					return true;
			}
			return false;	
		}

		bool isConnected(const N& val, const N& dst) const{
			if(!isNode(val)||!isNode(dst))
				throw std::runtime_error("Error: One or two nodes with specified data do not exist.");
			
			std::shared_ptr<Node<N,E>> s (new Node<N,E>);
			std::shared_ptr<Node<N,E>> d (new Node<N,E>);
			s = findNode(val);
			d = findNode(dst);

			for(unsigned int i=0;i!=s->getNumEdge(); ++i)
				if(s->getDst(i) == d)
					return true;
			return false;
		}

		std::shared_ptr<Node<N,E>> findNode(const N &src){
			for(unsigned int i = 0; i<arr_.size(); ++i){
				if(arr_[i]->getData() == src)
					return arr_[i];
			}
			return NULL;
		}

	

		void printNodes() const {
			for(unsigned int i = 0;i<arr_.size();++i){
				std::cout << arr_[i]->getData()<<std::endl;
			}
		}

		void printEdges(const N& val) const{
			
		}

		
		void printGraph() const{
			std::cout <<"size: " << arr_.size() << std::endl;
			for(unsigned int i = 0;i<arr_.size();++i){
				std::cout << "Adjacency list of vertex " << arr_[i]->getData()<<std::endl;
				for(unsigned int j=0;j<arr_[i]->getNumEdge();++j)
					std::cout << arr_[i]->getDst(j)->getData() << " -> ";
				std::cout <<std::endl;
				for(unsigned int j=0;j<arr_[i]->getNumEdge();++j)
					std::cout << arr_[i]->getWeight(j) << " -> ";
				std::cout <<std::endl;
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

	return 0;
}




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

namespace gdwg{

	template<typename N, typename E>
	class Node{
	private:
		N data_;
		std::vector<std::tuple<E, Node<N,E>*>> next_;


	public:
		Node()
		{};
		Node(const N &src)
			: data_(src)
		{};

		//methods
		void setData(const N &src)
		{
			data_ = src;
		}

		void addEdge(const E &w, Node<N,E> *d)
		{
			next_.push_back(std::make_tuple(w, d));
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

		Node<N,E>* getDst(const unsigned int idx){
			return std::get<1>(next_[idx]);
		}

	};

	template<typename N, typename E>
	class Graph{
	private:
		std::vector<Node<N,E>*> arr_;

	public:
		Graph()
		{};
		//methods
		bool addNode(const N &val)
		{
			Node<N,E> *n=new Node<N,E>;
			n->setData(val);
			if(isNode(val))
				return false;
			arr_.push_back(n);
			return true;
		}
		
		void addEdge(const N &src, const N &dst, const E &w){
			Node<N,E> *s=new Node<N,E>;
			Node<N,E> *d=new Node<N,E>;

			if(!isNode(src)) s->setData(src);
			else s = findNode(src);

			if(!isNode(dst)) d->setData(dst);
			else d = findNode(dst);

			s->addEdge(w,d);
			d->addEdge(w,s);

			if(!isNode(src)) arr_.push_back(s);
			if(!isNode(dst)) arr_.push_back(d);
		}

		bool isNode(const N &val) const{
			for(unsigned int i = 0; i<arr_.size(); ++i){
				if(arr_[i]->getData() == val)
					return true;
			}
			return false;	
		}


		Node<N,E>* findNode(const N &src){
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
		
		void printGraph(){
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



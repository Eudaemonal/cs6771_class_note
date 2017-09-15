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
		void addEdge(const N &src, const N &dst, const E &w){
			Node<N,E> *s=new Node<N,E>;
			Node<N,E> *d=new Node<N,E>;

			if(!existNode(src)) s->setData(src);
			else s = findNode(src);

			if(!existNode(dst)) d->setData(dst);
			else d = findNode(dst);

			s->addEdge(w,d);
			d->addEdge(w,s);

			if(!existNode(src)) arr_.push_back(s);
			if(!existNode(dst)) arr_.push_back(d);
		}

		bool existNode(const N &src){
			for(unsigned int i = 0; i<arr_.size(); ++i){
				if(arr_[i]->getData() == src)
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
	gdwg::Graph<int, int> g;

	g.addEdge(0,1,5);
	g.addEdge(0,2,4);
	g.addEdge(0,3,3);
	g.addEdge(1,3,1);
	g.addEdge(2,3,2);

	g.printGraph();	

	
	gdwg::Graph<std::string, int> g2;

	g2.addEdge("a", "b", 5);
	g2.addEdge("a", "c", 4);
	g2.addEdge("a", "d", 3);
	g2.addEdge("b", "d", 1);
	g2.addEdge("c", "d", 2);

	g2.printGraph();
	

	return 0;
}


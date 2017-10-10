#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <cstddef>
#include <utility>
#include <iterator>
#include <queue>
#include <vector>
#include <memory>

#include "btree_iterator.h"

const size_t DEFAULT_MAX_NODE_ELEMS = 40;



template <typename T> std::ostream& operator<<(std::ostream& os, const btree<T>& tree);

template <typename T> 
class btree {
public:
	friend class btree_iterator<T>;
	friend class const_btree_iterator<T>;

	typedef btree_iterator<T> iterator;
	typedef const_btree_iterator<T> const_iterator;


	/** Constructor
	*/
	btree() = default;
	btree(size_t t) 
		: maxNodeElems(t)
	{};
	~btree() = default;


	/** Iterator
	*/	
	iterator begin() const {
		if (root == nullptr || root->isEmpty())
			return iterator(end());
		auto curr = root.get();
		while(curr->hasChildAt(0)){
			curr = curr->getLeftChild();
		}
		return iterator(curr);
	}

	iterator end() const {
		return iterator(maxElement());
	}





	/** Methods
	*/
	std::pair<iterator, bool> insert(const T& elem){
		// empty tree
		if(root == nullptr || root->isEmpty()) {
			root = std::make_unique<Node>(0,nullptr, elem, maxNodeElems);
			return std::make_pair(iterator(root.get(), 0), true);
		}
		// full tree
		auto curr = root.get();
		unsigned int i = 0;




		
		// insert elem in sorted position
		auto arr = curr->elems;
		while (i < arr.size()) {
			if (elem == arr[i])
				return std::make_pair(iterator(curr, i), false); 
			else if (elem < arr[i])
				break;
			else
				++i;
    		}
		curr->emplaceElementBefore(i, elem);
		return std::make_pair(iterator(curr, i), true);
	}


	friend std::ostream& operator<< <T>(std::ostream& out, const btree<T>& b){
		if(b.root == nullptr){
			auto q = std::queue<typename btree<T>::Node*>{};
			q.push(b.root.get());
			while(!q.empty){
				auto curr = q.front();
				q.pop();
				for(unsigned int i = 0; i<curr->elems.size();++i){
					if(i>0 || curr != b.root.get())
						out << ' ';
					out << curr ->elems[i];
					if(curr->hasChildAt(i))
						q.push(curr->getLeftChildAt(i));
				}
				if(curr->hasRightChild())
					q.push(curr->getRightChild());
			}
		}
		return out;
	}


	
	// test
	void printNode(){
		root->printNode();
	}


private:
	iterator maxElement() const {
		auto curr = root.get();
		while (curr->hasRightChild())
			curr = curr->getRightChild();
		return iterator(curr, curr->elems.size()-1, false);
	}
	
	/** Node
	*/
	struct Node {
		// Constructor
		Node() 
		{
			clearChildren();
		}
		Node(unsigned int posP, Node* p, const size_t m) 
			: posInParent(posP), parent(p), maxNodeElems(m)
		{
			clearChildren();
		}
		Node(unsigned int posP, Node* p, const T& val, const size_t m)
			: posInParent(posP), parent(p), maxNodeElems(m)
		{
			clearChildren();
			elems.emplace(elems.cbegin(), val);
		}
		~Node() = default;
		// Methods
		void printNode(int level = 0) const {
			std::cout <<"Node at level "<< level << " size: " << elems.size() << "\n";
			for(unsigned int i=0; i< elems.size(); ++i)
				std::cout << elems[i] << ", ";
			std::cout << "\n";
			/*
			for(unsigned int i=0; i< leftChildren.size();++i){
				if(leftChildren[i]!=nullptr)
					leftChildren[i]->printNode(level+1);
				if(rightChild!=nullptr)
					rightChild->printNode(level+1);
			}
			*/
		}
		void clearChildren(){
			leftChildren.clear();
			for(auto i=0U; i<maxNodeElems;i++)
				leftChildren.push_back(nullptr);
			rightChild = nullptr;
		}
        	void createLeftChildAt(unsigned int i) {
        		leftChildren[i] = std::make_unique<Node>(i,this,maxNodeElems);
       		}
        	void createRightChild(){
        		rightChild = std::make_unique<Node>(elems.size()-1,this,maxNodeElems);
        	}
        	Node* getLeftChildAt(unsigned int i) const{
        		return leftChildren[i].get();
        	}
        	Node* getRightChild() const{
        		return rightChild.get();
        	}
        	Node* getLeftChild() const{
        		return getLeftChildAt(0);
        	}
        	bool hasChildAt(unsigned int i) const {
        		return getLeftChildAt(i)!=nullptr;
        	}
        	bool hasParent() const {
        		return parent!=nullptr;
        	}
        	bool hasRightChild() const {
        		return rightChild!=nullptr;
        	}
        	bool containsElement(const T& v) const {
        		return std::find(elems.cbegin(), elems.cend(), v);
        	}
        	bool isFull() const {
        		return elems.size() == maxNodeElems;
        	}
        	bool isEmpty() const {
        		return elems.empty();
        	}
        	void emplaceElementBefore(unsigned int index, const T& elem){
        		if(!isFull())
        			elems.emplace(elems.cbegin()+index, elem);
		}
		// Node elements
		unsigned int posInParent {0U};
		Node* parent {nullptr};
		std::vector<T> elems {};
		std::vector<std::unique_ptr<Node>> leftChildren {};
		std::unique_ptr<Node> rightChild {nullptr};
		size_t maxNodeElems {DEFAULT_MAX_NODE_ELEMS};
	};
	size_t maxNodeElems {DEFAULT_MAX_NODE_ELEMS};
	std::unique_ptr<Node> root {nullptr};
};

#endif

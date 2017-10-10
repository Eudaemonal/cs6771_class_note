#ifndef BST_H
#define BST_H

#include <iostream>
#include <cassert>
#include <new>


template <typename T> class Node {
public:
	Node <T> *parent_;
	Node <T> *left_;
	Node <T> *right_;
	T data_;


	Node()
		: parent_(nullptr), left_(nullptr), right_(nullptr)
	{}

	Node(T data)
		: parent_(nullptr), left_(nullptr), right_(nullptr), data_(data)
	{}
	
	static void walk(const Node<T> *tree) {
		if(tree==NULL) return;
		walk(tree->left_);
		std::cout << tree->data_ <<std::endl;
		walk(tree->right_);
	}

	static Node<T> *transplant(Node<T> *tree, Node<T> *u, Node<T> *v) {
		if(!u->parent_) tree = v;
		else if (u->parent_->left_ == u) u->left_ = v;
		else if (u->parent_->right_ == u) u->right_ = v;
		if(v) v->parent_ = u->parent_;
		return tree;
	}

	static Node<T> *find(Node<T> *tree, T value) {
		if(!tree || tree->data_ == value) return tree;
		if(value < tree->data_) return find(tree->left_, value);
		else return find(tree->right_, value);
	}

	static Node<T> *minimum(Node<T> *tree) {
		if(!tree) return NULL;
		while(tree->left_)
			tree = tree->left_;
		return tree;
	}

	static Node<T> *maximum(Node<T> *tree) {
		if(!tree) return NULL;
		while(tree->right_)
			tree = tree->right_;
		return tree;
	}
	static Node<T> *successor(Node<T> *node) {
		if(!node) return NULL;
		if(node->right_)
			return minimum(node->right_);
		else{
			Node<T> *parent = node->parent_;
			while(parent && node!=parent->left_){
				node = parent;
				parent = node->parent_;
			}
			return parent;
		}
	}



	// insert node
	static Node<T> *insertNode(Node<T> *tree, Node<T> *node){
		if(!tree){
			tree = node;
			node->parent_ = NULL;
		}
		else {
			Node<T> *parent, *search = tree;
			bool left = false;
			while(search != NULL){
				parent = search;
				if(node -> data_ <= search-> data_){
					search = search->left_;
					left = true;
				}
				else{
					search = search->right_;
					left = false;
				}
			}
			node -> parent_ = parent;
			if(left) parent->left_ = node;
			else     parent->right_ = node;
		}
		return tree;
	}

	// delete node
	static Node<T> *deleteNode(Node<T> *tree, Node<T> *node) {
		if(!node->left_)
			tree = transplant(tree, node, node->right_);
		else if (!node->right_)
			tree = transplant(tree, node, node->left_);
		else{
			Node<int> *successor = minimum(node->right_);
			assert(successor->left_ == NULL);
			if (successor != node->right_){
				tree = transplant(tree, successor, successor->right_);
				successor->right_ = node->right_;
				successor->right_->parent_ = successor;
			}
			tree = transplant(tree, node, successor);
			successor->left_ = node->left_;
			successor->left_ ->parent_ = successor;
		}
		return tree;
	}


	
	friend std::ostream &operator<<(std::ostream &output, Node<T> node){
		output << "Value: " << node.data_;
		if (node.parent_) output << " Parent: " << node.parent_ -> data_;
		if (node.left_) output << " Left: " << node.left_ -> data_;
		if (node.right_) output << " Right: " << node.right_ -> data_;
		output << "\n";
		return output;
	}



};

#endif

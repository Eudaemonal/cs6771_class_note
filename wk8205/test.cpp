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

struct Node{
	int data;
	std::vector<Node*> next;
};


struct Graph{
	std::vector<Node*> arr;
};


Node *newNode(int);
Graph *newGraph();
void addEdge(Graph*, int, int);
void printGraph(Graph*);
bool existNode(Graph*, int);
Node* findNode(Graph*, int);




int main(int argc, char* argv[]){
	Graph *g = newGraph();

	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,0,3);
	addEdge(g,1,3);
	addEdge(g,2,3);
	
	printGraph(g);	


	return 0;
}



//Implementation

Node *newNode(int data){
	Node *n = new Node;
	n->data = data;
	return n;
}


Graph *newGraph(){
	Graph *g = new Graph;
	return g;
}


// Add undirect edge
void addEdge(Graph *g, int src, int dst){
	Node *s;
	Node *d;

	if(!existNode(g, src)) s = newNode(src);
	else s = findNode(g, src);
	
	if(!existNode(g, dst)) d = newNode(dst);
	else d = findNode(g, dst);

	s->next.push_back(d);
	d->next.push_back(s);

	if(!existNode(g, src)) g->arr.push_back(s);
	if(!existNode(g, dst)) g->arr.push_back(d);
}



bool existNode(Graph *g, int src){
	for(unsigned int i = 0; i<g->arr.size(); ++i){
		if(g->arr[i]->data == src)
			return true;
	}
	return false;	
}


Node* findNode(Graph *g, int src){
	for(unsigned int i = 0; i<g->arr.size(); ++i){
		if(g->arr[i]->data == src)
			return g->arr[i];
	}
	return NULL;
}

void printGraph(Graph* g){
	std::cout << g->arr.size() <<std::endl;
	
	for(int i = 0; i<g->arr.size(); ++i){
		std::cout << "Adjacency list of vectex " << g->arr[i]->data <<std::endl;
		for(int j=0;j<g->arr[i]->next.size();++j){
			std::cout << g->arr[i]->next[j]->data << " -> ";
		}
		std::cout <<std::endl;
	}
}

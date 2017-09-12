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


struct Node{
	int data;
	Node *next;
};

struct List{
	Node *head;
};

struct Graph{
	int nV;
	List *arr;
};


Node *newNode(int);
Graph *newGraph(int);
void addEdge(Graph*, int, int);
void printGraph(Graph*);



int main(int argc, char* argv[]){
	int totalVertices = 4;
	Graph *g = newGraph(totalVertices);

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
	n->next = NULL;
	return n;
}


Graph *newGraph(int size){
	Graph *g = new Graph;
	g->nV = size;

	//Create header array
	g->arr = new List[size];
	for(int i=0;i<size;++i)
		g->arr[i].head = NULL;
	return g;
}

// Add undirect edge
void addEdge(Graph *g, int src, int dst){
	// from src to dst
	Node *n = newNode(dst);
	n->next = g->arr[src].head;
	g->arr[src].head=n;
	//from dst to src
	n = newNode(src);
	n->next = g->arr[dst].head;
	g->arr[dst].head = n;
}


void printGraph(Graph* g){
	std::cout << "size: " << g->nV <<std::endl;
	for(int i = 0; i < g->nV; ++i){
		Node *root = g->arr[i].head;
		std::cout << "Adjacency list of vertex "<< i <<std::endl;
		while(root!=NULL){
			std::cout << root->data << " -> ";
			root = root->next;
		}
		std::cout <<std::endl;
	}
}

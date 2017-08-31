/**
	Copyright (c) 2017 Eudaemon <eudaemonal@gmail.com> 
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
#include <string>
#include "test.h"

class stringPtr{
public:
	stringPtr(std::string *p): ptr(p) {}
	~stringPtr() {delete ptr;}
	stringPtr(const stringPtr&) = delete;
	stringPtr operator=(const stringPtr& ) = delete;
	stringPtr(stringPtr& other): ptr(other, ptr){
		ptr=nullptr;
	}

	stringPtr& operator=(stringPtr& other){
		stringPtr std::move(this);
		std::swap(other.ptr, ptr)
		return *this;
	}

	std::string operator*() {return *ptr;}
	std::string operator->() {return &**this;}

privte:
	std::string* ptr;
};

stringPtr makeStringPtr(const char* c){
	return stringPtr(new std::string(c))
}

/**
	Class shared pointer

*/
class SP{
public:
	SP(std::string* s): ptr(new Rep(s)){
		SP(const SP& other):ptr(other ptr);
		++ptr->rc;
	}
	~SP(){
		if(!--ptr->rc){
			delete  ptr;
		}
	}

	
private:	
	struct Rep{			 		// struct and class: everything is public in struct
		Rep(std::string* s): rc(1), s(s) {}
		~Rep(){
			delete s;
		}
		unsigned rc; // reference counter
		std::string* s;
	};
	Rep* ptr;
};

struct MyType{
	int k;
	std::unique_ptr<MyType> next;
};


int main(int argc, char* argv[]){
	//stringPtr x(new std::string("Hello"));
	
	auto x = makeStringPtr("Hello");// Safer solotion, use smart pointer
					// shared pointer use reference count, not simply copy
					// ownership

	stringPtr y(x);


	SP sa(new std::string("world")); //owner: sa
	{
		SP sb(sa);		//owner: both
		std::cout << "a";
	}
	{
		SP sb(std::move(sa));	//owner: sb, move pass ownship
		std::cout <<"b";
	}
	std::cout <<"c";

	// ownership cycle 
	// easy to happen in Graph 
	// raw pointer: without ownership
	// weak pointer: temperar ownship, or breaking cycle ownership if happens
	auto p = std::make_unique<MyType>();
	p->next = std::move(p);

	auto s = std::make_shared<MyType>();
	s->next->prev = s;
	auto p = s->next;
	if(auto prev = p.prev.lock()){
		std::cout << "I have a reference";
	}else{
		std::cout << "No reference";
	}

	return 0;
}

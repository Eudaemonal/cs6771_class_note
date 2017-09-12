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

class Intvec{
public:
	explicit Intvec(size_t num = 0)
		:m_size(num), m_data(new int[m_size])
	{
		log("constructor");
	}
	~Intvec()
	{
		log("destructor");
		delete[] m_data;
		m_data = 0;
	}
	
	Intvec(const Intvec& other)
		:m_size(other.m_size), m_data(new int[m_size])
	{
		log("copy constructor");
		for(size_t i = 0; i < m_size; ++i)
			m_data[i] = other.m_data[i];
	}

	Intvec& operator=(const Intvec& other)
	{
		log("copy assignment operator");
		Intvec tmp(other);
		std::swap(m_size, tmp.m_size);
		std::swap(m_data, tmp.m_data);
		return *this;
	}

	Intvec& operator=(Intvec&& other)
	{
		log("move assignment operator");
		std::swap(m_size, other.m_size);
		std::swap(m_data, other.m_data);
		return *this;
	}

	size_t get_size(){
		return m_size;
	}

private:
	void log(const char* msg)
	{
		std::cout << "[" << this << "]" <<msg << std::endl;
	}

	size_t m_size;
	int *m_data;

};


int main(int argc, char* argv[]){
	Intvec v1(20);
	Intvec v2;

	std::cout << "assigning lvalue...\n";
	v2 = v1;
	std::cout << "ended assigning lvalue...\n";
	
	std::cout << v1.get_size() << std::endl;
	std::cout << v2.get_size() << std::endl;

	std::cout << "assigning rvalue...\n";
	v2 = Intvec(33);
	std::cout << "ended assigning rvalue...\n";

	std::cout << v2.get_size() << std::endl;

	return 0;
}

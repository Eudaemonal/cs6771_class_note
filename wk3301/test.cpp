/* Copyright (c) 2016-2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>
#include <string>
#include <vector>
#include "test.hpp"

using namespace std;

int main(int argc, char* argv[]){
	std::vector<std::string> v = {"one", "two", "three"};
	

	std::array<int, 3> arr = {1,2,3};
	std::sort(arr.cbegin(), arr.cend());

	

	std::list<int> list;
	std::back_insert_iterator<std::list<int>> back(list);
	for(auto it=arr.cbegin(); it!=arr.cend; ++it){
		*back = *it;	
	}
	for(auto it=arr.cbegin(); it!=arr.cend; ++it){
		std::cout << *it <<std::endl;
	}


	std::sort(list.cbegin(), list.cend()) // list have different type of iterator
	//	bidirectional_iterator, forward_iterator
	//	vector random
	//	standard quick sort need random access for iterator, cannot act on list
	//	algorithm need specific iterators
	//	cannot sort queue

	list.sort(); 

	std::map<string, int> map;
	for(auto it=vec.cbegin(); it!=vec.cend(); ++it){
		map[*it] = it - vec.cbegin();
	}

	map["one"] = 1;
	map.insert(["one", 1])

	for(auto i = 0; i<vec.size();i++) // not int i; vec.size() is uint

	// iterate through map use auto
	
	
	

    return 0;
}

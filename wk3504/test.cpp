/* Copyright (c) 2016-2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <list>
#include <map>
#include "test.hpp"

using namespace std;


int main(int argc, char* argv[]){
	//**************************** vector
	vector<string> v = {"one", "two", "three"};

	cout << "vector: " ;
	for(auto it = v.cbegin();it!=v.cend();++it)
		cout << *it << " ";
	cout <<endl;
	
	sort(v.begin(), v.end());

	cout << "vector: " ;
	for(auto it = v.cbegin();it!=v.cend();++it)
		cout << *it << " ";
	cout <<endl;

	//**************************** array
	array<int,3> arr = {{3,2,1}};
	sort(arr.begin() , arr.end());
	
	for(auto it = arr.cbegin();it!=arr.cend();++it)
		cout << *it << " ";
	cout <<endl;

	//**************************** list
	list<int> l;
	back_insert_iterator<list<int>> Itr(l);

		for (auto itr = arr.begin(); itr < arr.end(); itr++) {
		*Itr = *itr * -1;
	}

	for(auto it = l.cbegin();it!=l.cend();++it)
		cout << *it << " ";
	cout <<endl;

	//sort(l.begin(), l.end());
	l.sort();
	
	for(auto it = l.cbegin();it!=l.cend();++it)
		cout << *it << " ";
	cout <<endl;

	l.reverse();

	for(auto it = l.cbegin();it!=l.cend();++it)
		cout << *it << " ";
	cout <<endl;

	

	//**************************** map
	cout << "map:" <<endl;
	map<string, int> m;

	int i = 0;
	for (auto j = l.begin(); j != l.end(); j++) {
		m.insert(std::pair<std::string,int>(v[i],(*j)));
		i++;
	}
	
	for (auto p : m) {
		std::cout << p.first << " " << p.second << std::endl;
	}	
		
    
	return 0;
}

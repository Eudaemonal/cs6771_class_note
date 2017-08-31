/* Copyright (c) 2016-2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>

#include "test.hpp"

using namespace std;

void swap(int &x, int &y) {
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

int main() {
	int i = 1, j = 2;
	std::cout << i << " " << j << std::endl;
	swap(i, j);
	std::cout << i << " " << j << std::endl;
}

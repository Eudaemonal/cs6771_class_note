#include <algorithm>
#include <iostream>
#include <iterator>

#include "btree.h"


int main(void) {
  btree<int> b;

  b.insert(1);
  b.insert(10);
  b.insert(3);
  b.insert(4);

  for(btree<int>::iterator iter = b.begin(); iter != b.end(); ++iter)
    std::cout << *iter << std::endl;

  
  return 0;
}


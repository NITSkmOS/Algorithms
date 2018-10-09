#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main() {
  LinkedList<int> intList;

  intList.insertTail(2);
  intList.insertTail(4);
  intList.insertHead(1);
  intList.insertAfter(2, 3);

  // Print out each element sequentially using an iterator
  int size = intList.size();
  if (size == 0) {
      cout << "Empty";
  } else {
      for (auto iter = intList.begin(); iter != intList.end(); ++iter) {
          cout << *iter << " ";
      }
  }

  cout << endl;

  return 0;
}

#include <iostream>

#include "tree.h"

using std::cin;
using std::cout;

int main() {
   Tree t;
   t.ReadTree(cin);
   cout << "the Tree is ";
   cout << ((t.IsSuperBalanced()) ? "" : "not ");
   cout << "superbalanced.\n";
   return 0;
}

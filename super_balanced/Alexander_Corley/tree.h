#ifndef TREE_H
#define TREE_H

#include <iostream>

using std::istream;

class Tree {
   public:
      Tree();
      ~Tree();
      void ReadTree(istream& in);
      bool IsSuperBalanced();

   private:
      class Node {
         public:
            Node(char value);
            ~Node();
            char* m_value;
            Node* m_left;
            Node* m_right;
      };

      Node* m_head;
      int m_maxDepth;
      int m_minDepth;
      void insert(char pValue, char cValue, Node* cur);
      void GetMinDepth();
      int GetMinDepth(Node* cur);
      void GetMaxDepth();
      int GetMaxDepth(Node* cur); 

};

#endif

#include <iostream>

#include "tree.h"

using std::istream;
using std::cout;

/**
 * @brief   basic tree constructor
**/
Tree::Tree() {
   m_head = nullptr;
   m_maxDepth = 0;
   m_minDepth = 0;
}

/**
 * @brief   basic tree destructor
**/
Tree::~Tree() {
   if (m_head)
      delete m_head;
}

/**
 * @brief   basic Tree::Node constructor
**/
Tree::Node::Node(char value) {
   m_value = new char(value);
   m_left = nullptr;
   m_right = nullptr;
}

/**
 * @brief   basic Tree::Node destructor, recursively deletes child nodes
**/
Tree::Node::~Node() {
   delete m_value;
   if (m_left)
      delete m_left;
   if (m_right)
      delete m_right;
}

/**
 * @brief   reads in a tree from the std::istream in the form:
 *          head child child, parent child child, parent child child'\n'
**/
void Tree::ReadTree(istream& in) {
   char parent = ' ';
   while (in.peek() != '\n') {
      if (!m_head) {
         parent = in.get();
         m_head = new Node(parent);
      }
      if (in.peek() == ',') {
         in.ignore();
         in.ignore();
         parent = in.get();
      } else if (in.peek() == ' ') {
         in.ignore();
         insert(parent, in.get(), m_head);
      }
   }
}

/**
 * @brief   recursively insert a new Tree::Node with a parent value
 *          of pValue and a value of cValue.
**/
void Tree::insert(char pValue, char cValue, Node* cur) {
   if (!cur) return;
   if (*cur->m_value == pValue) {
      if (!cur->m_left) {
          cur->m_left = new Node(cValue);
      } else if (!cur->m_right) {
         cur->m_right = new Node(cValue);
      }
   } else {
      insert(pValue, cValue, cur->m_left);
      insert(pValue, cValue, cur->m_right);
   }
}

/**
 * @brief   check to see whether the tree is superbalanced
 * @return  true if the tree is superbalanced, else false
**/
bool Tree::IsSuperBalanced() {
   GetMinDepth(); GetMaxDepth();
   return ((m_maxDepth-m_minDepth) <= 1);
}

/**
 * @brief   update the value of m_minDepth
**/
void Tree::GetMinDepth() {
   m_minDepth = GetMinDepth(m_head);
}

/**
 * @brief   recursive helper function for GetMinDepth
 * @return  the length of the shortest path to a null leaf from the current Node
 *          including the current Node
**/
int Tree::GetMinDepth(Node* cur) {
   if (!cur) return 0;
   int left = GetMinDepth(cur->m_left);
   int right = GetMinDepth(cur->m_right);
   return (left > right) ? right + 1 : left + 1;
}

/**
 * @brief   update the value of m_maxDepth
**/
void Tree::GetMaxDepth() {
   m_maxDepth = GetMaxDepth(m_head);
}

/**
 * @brief   recursive helper function for GetMinDepth
 * @return  the length of the longest path to a null leaf from the current Node
 *          including the current Node
**/
int Tree::GetMaxDepth(Node* cur) {
   if (!cur) return 0;
   int left = GetMaxDepth(cur->m_left);
   int right = GetMaxDepth(cur->m_right);
   return (left > right) ? left + 1 : right + 1;
}



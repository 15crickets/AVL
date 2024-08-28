#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std;


class Node{
 public:
  Node();
  ~Node();
  //initializing variables
  Node* parent;
  Node* left;
  Node* right;
  int longestSubtree;
  int data;
  //function prototypes
  void setRight(Node* newRight);
  void setLeft(Node* newLeft);
  void setLongestSubtree(int newLongest);
  Node* getRight();
  Node* getLeft();
  Node* getOnlyChild();
  int getLongestSubtree();
  void setParent(Node* newparent);
  Node* getParent();
  Node* getSibling();
  void setInformation(int value);
  int getInformation();
 
};


#endif
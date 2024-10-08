#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

//constructor
Node:: Node(){
  left = NULL;
  right = NULL;
  parent = NULL;
  longestSubtree = 0;
}

//destructor
Node :: ~Node(){
  parent = NULL;
}

void Node :: setLongestSubtree(int newLongest){
  longestSubtree = newLongest;
}

//sets the current node's right node.
void Node :: setRight(Node* newRight){
  right = newRight;

}
//sets the current node's left node.
void Node :: setLeft(Node* newLeft){
  left = newLeft;

}

//sets the current node's next.
void Node :: setParent(Node* newparent){
  parent = newparent;
}


//returns the current node's next
Node* Node:: getParent(){
  return parent;
}

Node* Node::getSibling(){
    if(this->getParent()->getLeft() == this){
        return this->getParent()->getRight();
    }
    else{
        return this->getParent()->getLeft();
    }
}

//returns the current node's right node.
Node* Node :: getRight(){
  return right;
}

//returns the current node's left node.
Node* Node :: getLeft(){
  return left;
}

Node* Node::getOnlyChild(){
  cout << this->getInformation() << endl;
  if(this->getLeft() == NULL){
    return this->getRight();
  }
  else if(this->getRight() == NULL){
    return this->getLeft();
  }
  return NULL;
}

int Node::getLongestSubtree(){
  return longestSubtree;
}


//sets the char stored by the node.
void Node :: setInformation(int value){
  data = value;
}

//returns the char stored by the node.
int Node :: getInformation(){
  return data;

}
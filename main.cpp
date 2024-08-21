/*
Author: Vikram Vasudevan
Date: 8/13/2024
Description: This program creates an AVL tree data structure
*/

#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

void add(Node* &root, Node* current, Node* newNode);
void fixTree(Node* &root, Node* current);
void leftRotation(Node* &root, Node* current);
void rightRotation(Node* &root, Node* current);
void print(Node* current, int count);
//print
//search
//remove

int main(){
    Node* root = NULL;
    bool stillRunning = true;

    while(stillRunning == true){
        cout << "What would you like to do? ADD, REMOVE, PRINT, SEARCH, or QUIT" << endl;

        char choice[50];
        cin.get(choice, 50);
        cin.get();
        if(strcmp(choice, "ADD") == 0){
            cout << "How many numbers will you be entering? " << endl;
            int numNums;
            cin >> numNums;
            cin.get();
            cout << "Enter your string of numbers: " << endl;
            for(int i = 0; i < numNums; i++){
                int tempInt;
                cout << "INSIDE?" << endl;
                cin >> tempInt;
                cout << tempInt << endl;
                cin.get();
                Node* newNode = new Node();
                newNode->setInformation(tempInt);
                add(root, root, newNode);
            }
        }
        else if(strcmp(choice, "REMOVE") == 0){
            int value;
            cout << "What number would you like to remove? " << endl;
            cin >> value;
            cin.get();
            //remove
        }
        else if(strcmp(choice, "SEARCH") == 0){

        }
        else if(strcmp(choice, "PRINT") == 0){
            print(root, 0);
        }
        else if(strcmp(choice, "QUIT") == 0){
            stillRunning = false;
        }

    }
}

void fixTree(Node* &root, Node* current){
    cout << "In here" << endl;
    if(current->getSibling() == NULL){
        cout << "First step" << endl;
        if(current->getParent() != root && current->getParent()->getSibling() == NULL){
            cout << "Second step" << endl;
            if(current->getParent()->getParent()->getInformation() > current->getParent()->getInformation()){
                cout << "YEP" << endl;
                if(current->getParent()->getInformation() > current->getInformation()){
                    cout << "1" << endl;
                    rightRotation(root, current->getParent());
                }
                else{
                    cout << "2" << endl;
                    leftRotation(root, current);
                    rightRotation(root, current);
                }
            }
            else{
                cout << "NOPE" << endl;
                if(current->getParent()->getInformation() < current->getInformation()){
                    cout << "3" << endl;
                    leftRotation(root, current->getParent());
                }
                else{
                    cout << "4" << endl;
                    rightRotation(root, current);
                    leftRotation(root, current);
                }
            }
        
        }
        return;
    }
    return;
}

void leftRotation(Node* &root, Node* current){
  Node* tempGrandparent = current->getParent()->getParent();
  Node* tempParent = current->getParent();
  Node* tempLeft = current->getLeft();
  if(current->getParent() == root){
    root = current;
    current->setParent(NULL);
  }
  else{
    current->setParent(tempGrandparent);
    if(tempGrandparent->getInformation() > current->getInformation()){
      tempGrandparent->setLeft(current);
    }
    else{
      tempGrandparent->setRight(current);
    }
  }
  current->setLeft(tempParent);
  tempParent->setParent(current);
  tempParent->setRight(tempLeft);
  if(tempLeft != NULL){
    tempLeft->setParent(tempParent);
  }
}

void rightRotation(Node* &root, Node* current){
  Node* tempParent = current->getParent();
  Node* tempGrandparent = current->getParent()->getParent();
  Node* tempRight = current->getRight();

  if(current->getParent() == root){
    root = current;
    current->setParent(NULL);
  }
  else{
    current->setParent(tempGrandparent);
    if(tempGrandparent->getInformation() > current->getInformation()){
      tempGrandparent->setLeft(current);
    }
    else{
      tempGrandparent->setRight(current);
    }
  }
  current->setRight(tempParent);
  tempParent->setParent(current);
  tempParent->setLeft(tempRight);
  if(tempRight != NULL){
    tempRight->setParent(tempParent);
  }
}

void add(Node* &root, Node* current, Node* newNode){
    if(root == NULL){
        root = newNode;
    }
    else if(current->getInformation() >= newNode->getInformation()){
        if(current->getLeft() == NULL){
            current->setLeft(newNode);
            newNode->setParent(current);
        }
        else{
            add(root, current->getLeft(), newNode);
        }
        fixTree(root, newNode);
    }
    else if(current->getInformation() < newNode->getInformation()){
        if(current->getRight() == NULL){
            current->setRight(newNode);
            newNode->setParent(current);
        }
        else{
            add(root, current->getRight(), newNode);
        }
        fixTree(root, newNode);
    }
    

    
}

void print(Node* current, int count){
    if(current->getLeft() != NULL){
        print(current->getLeft(), count + 1);
    }
    for(int i = 0; i < count; i++){
        cout << '\t';
    }
    cout << current->getInformation() << endl;
    if(current->getRight() != NULL){
        print(current->getRight(), count + 1);
    }

}
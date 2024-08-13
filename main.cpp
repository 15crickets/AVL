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
                //add(root, root, newNode);
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

        }
        else if(strcmp(choice, "QUIT") == 0){
            stillRunning = false;
        }

    }
}

void fixTree(Node* &root, Node* current){
    if(current->getSibling() == NULL){
        if(current->getParent() != root && current->getParent()->getSibling() == NULL){

        }
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
    }
    else if(current->getInformation() < newNode->getInformation()){
        if(current->getRight() == NULL){
            current->setRight(newNode);
            newNode->setParent(current);
        }
        else{
            add(root, current->getRight(), newNode);
        }
    }
    fixTree(root, newNode);

    
}
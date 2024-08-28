/*
Author: Vikram Vasudevan
Date: 8/13/2024
Description: This program creates an AVL tree data structure
*/


/*
    current problem, inability to properly rotate if node that is being rotated around has 2 children
    eg. 9 5 2 15 19 then 25
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
    cout << "HELLO: " << current->getInformation() << endl;
    current->setLongestSubtree(current->getLongestSubtree() + 1);
    if(current == root){
        cout << "First up" << endl;
        return;
    }
    if(current->getLongestSubtree() == 1){
        cout << "2nd time + 3rd" << endl;
        fixTree(root, current->getParent());
        cout << "WE'VE ARRIVED FROM THE MESS" << endl;
        return;
    }
    else{
        cout << "Third time" << endl;
        if(current->getSibling() == NULL || current->getLongestSubtree() > (current->getSibling()->getLongestSubtree() + 1)){
            cout << "Made it here" << endl;
            if(current->getInformation() < current->getParent()->getInformation()){
                cout << "here v1.0" << endl;
                if(current->getOnlyChild()->getInformation() > current->getInformation()){
                    cout << "HERE" << endl;
                    leftRotation(root, current->getOnlyChild());
                    rightRotation(root, current->getParent());
                    return;
                }
                else{
                    cout << "Here v2.0" << endl;
                    rightRotation(root, current);
                    return;
                }
            }
            else{
                if(current->getOnlyChild()->getInformation() < current->getInformation()){
                    rightRotation(root, current->getOnlyChild());
                    leftRotation(root, current->getParent());
                    return;
                }
                else{
                    leftRotation(root, current);
                    return;
                }
            }

        }
        else{
            fixTree(root, current->getParent());
        }
    }
}


/*
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
*/

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
    tempParent->setLongestSubtree(tempParent->getLongestSubtree() - 1);
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
    tempParent->setLongestSubtree(tempParent->getLongestSubtree() - 1);
}

void add(Node* &root, Node* current, Node* newNode){
    cout << "Entered add" << endl;
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
            return;
        }
        cout << "I'm bl" << endl;
        fixTree(root, newNode);
        cout << "UE" << endl;
    }
    else if(current->getInformation() < newNode->getInformation()){
        if(current->getRight() == NULL){
            current->setRight(newNode);
            newNode->setParent(current);
        }
        else{
            add(root, current->getRight(), newNode);
            return;
        }
        cout << "I'm GRE" << endl;
        fixTree(root, newNode);
        cout << "EN" << endl;
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
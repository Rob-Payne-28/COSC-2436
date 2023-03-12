/*********************
Name: Robert Payne
Coding 06
Purpose: Assignment 06 - Doubly Linked List that is part of COSC-2436.
**********************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define EMPTY_STRING ""
#define ZERO 0
#define MIN_NODE_COUNT 1
#define ERROR_VALUE -1

#include "data.h"
#include "iostream"

class LinkedList {

public:
    LinkedList();
    ~LinkedList();
    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int);

private:

    // Private helper functions
    Node* createNewNode(int, string*);
    void insertAsHead(Node*);
    void insertAfter(Node*, Node*);
    Node* findTailNode(int*);
    Node* findTargetNode(int);

    // head is the only attribute allowed
    Node *head;

};

#endif //LINKED_LIST_H

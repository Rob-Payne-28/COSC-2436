/*********************
Name: Robert Payne
Coding 06
Purpose: Assignment 06 - Doubly Linked List that is part of COSC-2436.
**********************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "data.h"

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

    Node *head;

};

#endif //LINKED_LIST_H

/*********************
Name: Robert Payne
Coding 07
Purpose: Assignment 07 - Binary Search Tree that is part of COSC-2436.
**********************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include "data.h"
#include <iostream>
#include <algorithm> // max function

#define EMPTY_STRING ""
#define EMPTY_INT -1
#define ZERO 0

class BinTree {

public:
    BinTree();
    ~BinTree();
    bool isEmpty();
    int getCount();
    bool getRootData(Data*);
    void displayTree();

    void clear();
    bool addNode(int, const string*);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);
    int getHeight();
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();

private:

    DataNode *root;
    int count;

    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);

    DataNode* minValueNode(DataNode*);
};


#endif /* BINTREE_BINTREE_H */


/*********************
Name: Robert Payne
Coding 07
Purpose: Assignment 07 - Binary Search Tree that is part of COSC-2436.
**********************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

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

};


#endif /* BINTREE_BINTREE_H */


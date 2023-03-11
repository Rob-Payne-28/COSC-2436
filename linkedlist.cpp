/*********************
Name: Robert Payne
Coding 06
Purpose: Assignment 06 - Doubly Linked List that is part of COSC-2436.
**********************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    // ToDo: Initialize head
}

LinkedList::~LinkedList(){
    // ToDo: Call clearList() and destroy LinkedList
}

bool LinkedList::addNode(int id, string* newNodeData){
    // ToDo: pass int Id by reference. Return bool indicating success.
    // The id must be unique and a positive number greater than 0.
    // Nodes added must be stored in ascending order of id.
    // Memory for the node must be allocated inside the linked list object.
    // This method must do proper error checking.
    // DO NOT use your own exists() method to look for non-unique ids, and do not duplicate the
    // exists() functionality to look for non-unique ids. If you do that, that will increase the processing
    // time of your method by a factor of 2x. You want to first only verify your id is a positive int, and
    // the string is non-empty, then search for the place to add the new node, and during the search
    // look for duplicates, then after you determine there is no duplicate, then allocate your memory
    // and insert the node. This is the algorithm you must follow to ensure efficiency and no memory
    // leaks. If you deviate from that algorithm, your code will not be correct, even if it “works.”
    return false;
};

bool LinkedList::deleteNode(int id){
    // ToDo: Pass in an id, look for it and delete it in one loop. Return bool for success.
    return false;
};

bool LinkedList::getNode(int id, Data* data){
    // ToDo: Pass in an id and an empty struct Data by ref. Return bool to indicate success.
    // If not found, return -1 and empty string.
    // Remember to not pass the pointer from inside the linked list :)
    // Do not use exists method
    return false;
};

void printList(bool backward){
    // ToDo: Print entire list either forwards (default) or backwards (if backward == true).
};

int LinkedList::getCount(){
    // ToDo: Calculate the count of nodes in the list.
    return -1;
};

bool LinkedList::clearList(){
    // ToDo: Delete all allocated memory and set head to NULL.
    return false;
};

bool LinkedList::exists(int id){
    // ToDo: Start at the beginning and go until until searched id is larger than id OR we hit the id we're looking for.
    return false;
};

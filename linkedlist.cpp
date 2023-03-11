/*********************
Name: Robert Payne
Coding 06
Purpose: Assignment 06 - Doubly Linked List that is part of COSC-2436.
**********************/

#include "linkedlist.h"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    clearList();
    delete head;
}


// ToDo: Clean up the comments used for walking through the logic
bool LinkedList::addNode(int newId, string *newNodeData) {
    bool isSuccessful = false;

    // parameter check for pos number, non-nullptr data, and non-empty strings
    if (newId > 0 && newNodeData != nullptr && !(newNodeData->empty())) {

        // create node to store values of where we are in the list
        Node *currentNode = head;
        Node *previous = nullptr;

        // while not the tail node and less than current, move to the next
        while (currentNode != nullptr && currentNode->data.id < newId) {
            previous = currentNode;
            currentNode = currentNode->next;
        }

        // we only get here if the current node is null (the end of the list/empty)
        // or the id of the currentNode is larger than or equal to the target
        // Since we've found the insertion point, we can create our new node
        Node *newNode = new Node;
        newNode->data.id = newId;
        newNode->data.data = *newNodeData;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (currentNode == nullptr) {
            head = newNode;
            isSuccessful = true;
        } else if (currentNode->data.id != newId) {
            // if previous is a null pointer, we need to assign the head to here
            // because we're at a node that's larger than the target
            if (previous == nullptr) {
                // beginning of the list
                head = newNode;
                isSuccessful = true;
            } else {
                // middle or at the end of the list
                previous->next = newNode;
                newNode->prev = previous;
                isSuccessful = true;
            }
            newNode->next = currentNode;
            currentNode->prev = newNode;
        }
    }
    return isSuccessful;
};

bool LinkedList::deleteNode(int id) {
    // ToDo: Pass in an id, look for it and delete it in one loop. Return bool for success.
    return false;
};

bool LinkedList::getNode(int id, Data *data) {
    // ToDo: Pass in an id and an empty struct Data by ref. Return bool to indicate success.
    // If not found, return -1 and empty string.
    // Remember to not pass the pointer from inside the linked list :)
    // Do not use exists method
    return false;
};

void printList(bool backward) {
    // ToDo: Print entire list either forwards (default) or backwards (if backward == true).
};

int LinkedList::getCount() {
    // ToDo: Calculate the count of nodes in the list.
    return -1;
};

bool LinkedList::clearList() {
    // ToDo: Delete all allocated memory and set head to NULL.
    return false;
};

bool LinkedList::exists(int id) {
    // ToDo: Start at the beginning and go until until searched id is larger than id OR we hit the id we're looking for.
    return false;
};

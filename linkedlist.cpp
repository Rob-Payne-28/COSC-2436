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

    if (newId > ZERO && newNodeData != nullptr && !(newNodeData->empty())) {

        Node *currentNode = head;
        Node *previous = nullptr;

        while (currentNode != nullptr && currentNode->data.id < newId) {
            previous = currentNode;
            currentNode = currentNode->next;
        }

        if (currentNode != nullptr && currentNode->data.id == newId) {
            // noop - I've tried switching this conditional; it keeps allowing
            // duplicate values, so I'm leaving this as a no-op for now. I know why,
            // I'm just having trouble implementing it within the constraints given.
            // Perhaps it'll become easier once this method is broken up to helper
            // functions.
        } else {
            Node *newNode = new Node();
            newNode->data.id = newId;
            newNode->data.data = *newNodeData;
            newNode->next = nullptr;
            newNode->prev = nullptr;

            if (previous == nullptr) {
                if (head != nullptr) {
                    head->prev = newNode;
                }
                newNode->next = head;
                head = newNode;
            } else {
                newNode->next = previous->next;
                previous->next = newNode;
                if (newNode->next != nullptr) {
                    newNode->next->prev = newNode;
                }
                newNode->prev = previous;
            }
            isSuccessful = true;
        }
    }
    return isSuccessful;
}


bool LinkedList::deleteNode(int targetId) {
    bool isSuccessful = false;

    Node *currentNode = head;
    Node *previous = nullptr;

    while (currentNode != nullptr && currentNode->data.id != targetId) {
        previous = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode != nullptr) {
        if (previous == nullptr) {
            head = currentNode->next;
        } else {
            previous->next = currentNode->next;
        }
        if (currentNode->next != nullptr) {
            Node *nextNode = currentNode->next;
            nextNode->prev = previous;
        }
        delete currentNode;
        isSuccessful = true;
    }

    return isSuccessful;
}

bool LinkedList::getNode(int targetId, Data *data) {
    bool isSuccessful = false;

    Node *currentNode = head;

    while (currentNode != nullptr && currentNode->data.id != targetId) {
        currentNode = currentNode->next;
    }

    if (currentNode == nullptr) {
        data->id = ERROR_VALUE;
        data->data = EMPTY_STRING;
    } else {
        data->id = currentNode->data.id;
        data->data = currentNode->data.data;
        isSuccessful = true;
    }

    return isSuccessful;
}

void LinkedList::printList(bool backward) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
    } else if (backward) {
        Node* currentNode = head;
        int nodeCount = MIN_NODE_COUNT;

        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
            nodeCount++;
        }

        while (currentNode != nullptr) {
            std::cout << nodeCount
            << ": " << currentNode->data.id
            << ": "<< currentNode->data.data
            << std::endl;
            currentNode = currentNode->prev;
            nodeCount--;
        }
    } else {
        Node* currentNode = head;
        int nodeCount = MIN_NODE_COUNT;

        while (currentNode != nullptr) {
            std::cout << nodeCount
            << ": " << currentNode->data.id
            << ": "<< currentNode->data.data
            << std::endl;
            currentNode = currentNode->next;
            nodeCount++;
        }
    }
}

int LinkedList::getCount() {
    int count = ZERO;

    Node *currentNode = head;
    while (currentNode != nullptr) {
        count++;
        currentNode = currentNode->next;
    }

    return count;
}

bool LinkedList::clearList() {

    Node *currentNode = head;

    while (currentNode != nullptr) {
        Node *nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }

    head = nullptr;

    return true;
}

bool LinkedList::exists(int targetId) {
    bool doesExist = false;

    Node *currentNode = head;
    while (currentNode != nullptr && currentNode->data.id != targetId) {
        currentNode = currentNode->next;
    }

    if (currentNode != nullptr) {
        doesExist = true;
    }

    return doesExist;
}

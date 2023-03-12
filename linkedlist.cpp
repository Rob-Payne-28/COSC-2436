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
}

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
            // noop
        } else {
            Node *newNode = createNewNode(newId, newNodeData);
            previous == nullptr ? insertAsHead(newNode) : insertAfter(previous, newNode);
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
        previous == nullptr ? head = currentNode->next : previous->next = currentNode->next;

        if (currentNode->next != nullptr) {
            currentNode->next->prev = previous;
        }

        delete currentNode;
        isSuccessful = true;
    }

    return isSuccessful;
}

bool LinkedList::getNode(int targetId, Data *data) {
    bool isSuccessful = false;

    Node* currentNode = findTargetNode(targetId);

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
    } else {
        int nodeCount = MIN_NODE_COUNT;
        Node *currentNode = backward ? findTailNode(&nodeCount) : head;

        while (currentNode != nullptr) {
            std::cout << nodeCount << ": " << currentNode->data.id << ": " << currentNode->data.data << std::endl;
            if (backward) {
                currentNode = currentNode->prev;
                nodeCount--;
            } else {
                currentNode = currentNode->next;
                nodeCount++;
            }
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

    Node* currentNode = findTargetNode( targetId);

    if (currentNode != nullptr) {
        doesExist = true;
    }

    return doesExist;
}

//
// Private helper methods
//

Node *LinkedList::createNewNode(int newId, string *newNodeData) {
    Node *newNode = new Node();
    newNode->data.id = newId;
    newNode->data.data = *newNodeData;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void LinkedList::insertAsHead(Node *newNode) {
    if (head != nullptr) {
        head->prev = newNode;
    }
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAfter(Node *previous, Node *newNode) {
    newNode->next = previous->next;
    previous->next = newNode;
    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    }
    newNode->prev = previous;
}

Node* LinkedList::findTailNode(int *nodeCount) {
    Node* currentNode = head;

    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
        (*nodeCount)++;
    }

    return currentNode;
}

Node* LinkedList::findTargetNode(int targetId) {
    Node* currentNode = head;
    while (currentNode != nullptr && currentNode->data.id != targetId) {
        currentNode = currentNode->next;
    }
    return currentNode;
}
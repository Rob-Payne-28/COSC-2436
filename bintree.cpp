/*********************
Name: Robert Payne
Coding 07
Purpose: Assignment 07 - Binary Search Tree that is part of COSC-2436.
**********************/

#include "bintree.h"

BinTree::BinTree() {
    root = nullptr;
    count = 0;
}

BinTree::~BinTree() {
    clear();
}

bool BinTree::isEmpty() {
    return (count == 0);
}

int BinTree::getCount() {
    return count;
}

bool BinTree::getRootData(Data* data) {
    return false;
    // ToDo: take empty struct and fill it with root's data if the tree is not empty. If empty fill with, -1 and "".
    // Return T/F to indicate success
}

void BinTree::displayTree() {
    std::cout << "DISPLAY TREE" << std::endl;
    std::cout << "==============================================" << std::endl;

    if(isEmpty()) {
        std::cout << "Tree is empty" << std::endl;
    } else {
        std::cout << "Tree is NOT empty" << std::endl;
    }

    std::cout << "Height "<< getHeight() << std::endl;
    std::cout << "Node count: " << getCount() << std::endl;
    std::cout << std::endl;

    std::cout << "Pre-Order Traversal" << std::endl;
    displayPreOrder();
    std::cout << std::endl;

    std::cout << "In-Order Traversal" << std::endl;
    displayInOrder();
    std::cout << std::endl;

    std::cout << "Post-Order Traversal" << std::endl;
    displayPostOrder();

    std::cout << "==============================================" << std::endl;
    std::cout << std::endl;

    // ToDo: display all stats for the tree as shown, and call all display order methods
}


void BinTree::clear() {
    // ToDo: deallocate the tree and set it back to empty
}

void BinTree::clear(DataNode* dataNode) {
    // ToDo: deallocate the tree and set it back to empty, should call itself recursively
}

bool BinTree::addNode(int id, const string* value) {

    DataNode* tempNode = new DataNode;
    tempNode->data.id = id;
    tempNode->data.information = *value;
    tempNode->left = nullptr;
    tempNode->right = nullptr;

    bool success = addNode(tempNode, &root);

    if(success) {
        count += 1;
    }

    return success;
}

bool BinTree::addNode(DataNode* nodeToAdd, DataNode** rootNode) {
    bool success = false;

    // Add root
    if(*rootNode == nullptr) {
        *rootNode = nodeToAdd;
        success = true;
    } else if(nodeToAdd->data.id <= (*rootNode)->data.id) {
    // Add left
       success = addNode(nodeToAdd, &(*rootNode)->left);
    } else if(nodeToAdd->data.id > (*rootNode)->data.id) {
    // Add right
       success = addNode(nodeToAdd, &(*rootNode)->right);
    }

    return success;
}

bool BinTree::removeNode(int id) {
    return false;
    // ToDo: pass in and return T/F
}

DataNode* BinTree::removeNode(int id, DataNode* dataNode) {
    DataNode *node = new DataNode();
    return node;
    // ToDo: pass in and return T/F
}

int BinTree::getHeight() {
    return 0;
    // ToDo: dynamically calculate the height of the tree
}

int BinTree::getHeight(DataNode* dataNode) {
    return 0;
    // ToDo: dynamically calculate the height of the tree

}

bool BinTree::getNode(Data* data, int id) {
    return false;
    // ToDo: pass in and return as normal. Must use binary search
}

bool BinTree::getNode(Data* data, int id, DataNode* dataNode) {
    return false;
    // ToDo: pass in and return as normal. Must use binary search
}

bool BinTree::contains(int id) {
    return false;
    // ToDo: pass in and return T/F
}

bool BinTree::contains(int id, DataNode* dataNode) {
    return false;
    // ToDo: pass in and return T/F
}


void BinTree::displayPreOrder() {
    // ToDo: Pre-order traversal, printing as you go
    // Print right
    // Print left
    // Print node
}

void BinTree::displayPreOrder(DataNode* dataNode) {
    // ToDo: Pre-order traversal, printing as you go
    // Print right
    // Print left
    // Print node
}

void BinTree::displayPostOrder() {
    // ToDo: Post-order traversal, printing as you go
    // Print left
    // Print right
    // Print node
}

void BinTree::displayPostOrder(DataNode* dataNode) {
    // ToDo: Post-order traversal, printing as you go
    // Print left
    // Print right
    // Print node
}

void BinTree::displayInOrder() {

    // ToDo: IJN-order traversal, printing as you go
    // Print node
    // Print left
    // Print right
}

void BinTree::displayInOrder(DataNode* dataNode) {
    // ToDo: IJN-order traversal, printing as you go
    // Print node
    // Print left
    // Print right
}

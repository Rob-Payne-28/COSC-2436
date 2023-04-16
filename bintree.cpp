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
    bool success = false;

    if(root == nullptr) {
        data->id = EMPTY_INT;
        data->information = EMPTY_STRING;
    } else {
        data->id = root->data.id;
        data->information = root->data.information;
        success = true;
    }

    return success;
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
}


void BinTree::clear() {
    clear(root);
    root = nullptr;
    count = 0;
}

void BinTree::clear(DataNode* tempNode) {
    if(tempNode != nullptr) {
        clear(tempNode->left);
        clear(tempNode->right);
        delete tempNode;
    }
}

bool BinTree::addNode(int id, const string* value) {
    bool success = false;
    if(id > 0 && value != nullptr && !(value->empty())) {
        DataNode *tempNode = new DataNode;
        tempNode->data.id = id;
        tempNode->data.information = *value;
        tempNode->left = nullptr;
        tempNode->right = nullptr;

        success = addNode(tempNode, &root);

        if (success) {
            count += 1;
        }
    }
    return success;
}

bool BinTree::addNode(DataNode* nodeToAdd, DataNode** rootNode) {
    bool success = false;

    if(*rootNode == nullptr) {
        *rootNode = nodeToAdd;
        success = true;
    } else if(nodeToAdd->data.id <= (*rootNode)->data.id) {
       success = addNode(nodeToAdd, &(*rootNode)->left);
    } else if(nodeToAdd->data.id > (*rootNode)->data.id) {
       success = addNode(nodeToAdd, &(*rootNode)->right);
    }

    return success;
}

bool BinTree::removeNode(int id) {
    int oldCount = count;

    if(id > 0) {
        root = removeNode(id, root);
    }

    return oldCount > count;
}

DataNode* BinTree::removeNode(int id, DataNode* dataNode) {
    if(dataNode != nullptr){

        if(id < dataNode->data.id){
            dataNode->left = removeNode(id, dataNode->left);
        } else if (id > dataNode->data.id){
            dataNode->right = removeNode(id, dataNode->right);
        } else {

            DataNode* tempNode = nullptr;
            if(dataNode->left == nullptr && dataNode->right == nullptr){
                delete dataNode;
                dataNode = nullptr;
                count -= 1;
            } else if(dataNode->left != nullptr && dataNode->right == nullptr){
                tempNode = dataNode->left;
                delete dataNode;
                dataNode = tempNode;
                count -= 1;
            } else if(dataNode->left == nullptr && dataNode->right != nullptr){
                tempNode = dataNode->right;
                delete dataNode;
                dataNode = tempNode;
                count -= 1;
            } else {
                DataNode* minNode = minValueNode(dataNode->right);
                dataNode->data.id = minNode->data.id;
                dataNode->data.information = minNode->data.information;
                dataNode->right = removeNode(minNode->data.id, dataNode->right);
                count -= 1;
            }
        }
    }
    return dataNode;
}

int BinTree::getHeight() {
    return getHeight(root);
}

int BinTree::getHeight(DataNode* dataNode) {
    int maxValue = 0;
    if(dataNode != nullptr){
        int left = getHeight(dataNode->left);
        int right = getHeight(dataNode->right);

        maxValue = std::max(left, right);

        maxValue += 1;
    }
    return maxValue;
}

bool BinTree::getNode(Data* data, int id) {
    bool success = false;

    if(id > 0){
        success = getNode(data, id, root);
    }

    return success;
}

bool BinTree::getNode(Data* data, int id, DataNode* dataNode) {
    bool success = false;

    if(dataNode != nullptr){

        if(id < dataNode->data.id){
            success = getNode(data, id, dataNode->left);
        } else if(id > dataNode->data.id){
            success = getNode(data, id, dataNode->right);
        } else {
            data->id = dataNode->data.id;
            data->information = dataNode->data.information;
            success = true;
        }
    }

    return success;
}

bool BinTree::contains(int id) {
    bool success = false;

    if(id > 0){
        success = contains(id, root);
    }

    return success;
}

bool BinTree::contains(int id, DataNode* dataNode) {
    bool success = false;

    if(dataNode != nullptr){

        if(id < dataNode->data.id){
            success = contains(id, dataNode->left);
        } else if(id > dataNode->data.id){
            success = contains(id, dataNode->right);
        } else {
            success = true;
        }
    }

    return success;
}

void BinTree::displayPreOrder() {
    displayPreOrder(root);
}

void BinTree::displayPreOrder(DataNode* dataNode) {
    if(dataNode != nullptr){
        std::cout << dataNode->data.id << " "  << dataNode->data.information << std::endl;
        displayPreOrder(dataNode->left);
        displayPreOrder(dataNode->right);
    }
}

void BinTree::displayPostOrder() {
    displayPostOrder(root);
}

void BinTree::displayPostOrder(DataNode* dataNode) {
    if(dataNode != nullptr){
        displayPostOrder(dataNode->left);
        displayPostOrder(dataNode->right);
        std::cout << dataNode->data.id << " "  << dataNode->data.information << std::endl;
    }
}

void BinTree::displayInOrder() {
    displayInOrder(root);
}

void BinTree::displayInOrder(DataNode* dataNode) {
    if(dataNode != nullptr){
        displayInOrder(dataNode->left);
        std::cout << dataNode->data.id << " " << dataNode->data.information << std::endl;
        displayInOrder(dataNode->right);
    }
}

DataNode* BinTree::minValueNode(DataNode* node) {
    DataNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
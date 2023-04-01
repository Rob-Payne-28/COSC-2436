/*********************
Name: Robert Payne
Coding 07
Purpose: Assignment 07 - Hash Table backed by Doubly Linked List that is part of COSC-2436.
**********************/

#include "hashtable.h"

HashTable::HashTable() {
    count = 0;
    hashTable = new LinkedList[HASHTABLESIZE];
}

HashTable::~HashTable() {
    delete[] hashtable;
}

bool HashTable::insertEntry(int id, string* inputData) {
    bool success = false;
    int hashedId = hash(id);

    if(id > 0 && *inputData != EMPTY_STRING) {
        if(!hashtable[hashedId].exists(id)) {
            success = hashtable[hashedId].addNode(id, inputData);
        }
    }

    if(success) {
        count++;
    }
    return success;
}

string HashTable::getData(int id) {
    int hashedId = hash(id);
    Data data;

    if(!hashtable[hashedId].getNode(id, &data)){
        data.value = "";
    }

    return data.value;
}

bool HashTable::removeEntry(int id) {
    bool success = false;
    int hashedId = hash(id);

    if(hashtable[hashedId].deleteNode(id)){
        count--;
        success = true;
    }

    return success;
}

int HashTable::getCount() {
    return count;
}

void HashTable::printTable() {
    std::cout << "Printing Table..." << std::endl;
    for(int i = 0; i < HASHTABLESIZE; i++){
        std::cout << " Entry " << (i+1) << ": " << std::endl;
        hashtable[i].printList();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int HashTable::hash(int id) {
    return id % HASHTABLESIZE;
}
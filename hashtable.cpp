/*********************
Name: Robert Payne
Coding 07
Purpose: Assignment 07 - Hash Table backed by Doubly Linked List that is part of COSC-2436.
**********************/

#include "hashtable.h"

HashTable::HashTable() {
    count = ZERO;
    hashTable = new LinkedList[HASH_TABLE_SIZE];
}

HashTable::~HashTable() {
    delete[] hashTable;
}

bool HashTable::insertEntry(int id, string* inputData) {
    bool success = false;
    int hashedId = hash(id);

    if(id > ZERO && *inputData != EMPTY_STRING) {
        if(!hashTable[hashedId].exists(id)) {
            success = hashTable[hashedId].addNode(id, inputData);
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

    if(id <= ZERO || !hashTable[hashedId].getNode(id, &data)){
        data.data = EMPTY_STRING;
    }

    return data.data;
}

bool HashTable::removeEntry(int id) {
    bool success = false;
    int hashedId = hash(id);

    if(id > ZERO && hashTable[hashedId].deleteNode(id)){
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
    for(int i = ZERO; i < HASH_TABLE_SIZE; i++){
        std::cout << " Entry " << (i+1) << ": ";
        hashTable[i].printList();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int HashTable::hash(int id) {
    return id % HASH_TABLE_SIZE;
}
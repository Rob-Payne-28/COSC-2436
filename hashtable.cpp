/*********************
Name: Robert Payne
Coding 07
Purpose: Assignment 07 - Hash Table backed by Doubly Linked List that is part of COSC-2436.
**********************/

#include "hashtable.h"

HashTable::HashTable() {
    count = 0;

    for (int i = 0; i < HASHTABLESIZE; i++){
        hashTable = new LinkedList[HASHTABLESIZE];
    }
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
    // ToDo: Return total number of entries in the hash table by returning the value in the count attribute
}

void HashTable::printTable() {
    // ToDo: Traverse table and print entries
    /* Output should conform to:
     * Entry 1: EMPTY
     * Entry 2: 3 -->14 -->5
     * Entry 3: EMPTY
     * Entry 4: 10
     * Entry 5: 4 --> 2
    */
}

int HashTable::hash(int id) {
    return id % HASHTABLESIZE;
}
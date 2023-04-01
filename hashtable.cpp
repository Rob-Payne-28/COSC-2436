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
    // ToDo: Look up id in linked list and return data string associated with that id
    // ToDo: Return empty string if the id doesn't exist
}

bool HashTable::removeEntry(int id) {
    // ToDo: Delegate to deleteNode method
    // ToDo: Return true or false to indicate success
    // ToDo: Decrement count attribute on hash table implementation
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
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
    // ToDo: Check that input is greater than zero and a string that is not empty
    // ToDo: Find appropriate linked list object
    // ToDo: Check for unique id by calling exists on the linked list
    // ToDo: Delegate to linked list for insertion
    // ToDo: Increment count attribute on hash table implementation
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
/*********************
Name: Robert Payne
Coding 07
Purpose: Assignment 07 - Hash Table backed by Doubly Linked List that is part of COSC-2436.
**********************/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define HASHTABLESIZE 15
#define EMPTY_STRING ""

#include "data.h"

class HashTable {

public:
    HashTable();
    ~HashTable();
    bool insertEntry(int, string*);
    string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();

private:
    int count;
    LinkedList *hashtable;

    int hash(int);
};

#endif //HASH_TABLE_H
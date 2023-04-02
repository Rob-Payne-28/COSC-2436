/*********************
Name: Robert Payne
Coding 07
Purpose: Assignment 07 - Hash Table backed by Doubly Linked List that is part of COSC-2436.
**********************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    HashTable hashTable;

    std::cout << "Executing method tests..." << std::endl;
    std::cout << std::endl;

    // show it is empty by calling getCount and printTable
    std::cout << "=====================================================" << std::endl;
    std::cout << "                    Getting count..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    std::cout << "Number of entries: " << hashTable.getCount() << std::endl;
    std::cout << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "                    Printing table..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    hashTable.printTable();

    std::cout << "=====================================================" << std::endl;
    std::cout << "                    Filling table..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;

    for (int i = ZERO; i < testdatasize; i++) {
        bool success = hashTable.insertEntry(ids[i], &strs[i]);
        if (success) {
            std::cout << " Inserted entry with id " << ids[i] << " and data \'" << strs[i] << "\'" << std::endl;
        } else {
            std::cout << " Failed to insert entry with id " << ids[i] << " and data \'" << strs[i] << "\'" << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "                    Getting count..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    std::cout << "Number of entries: " << hashTable.getCount() << std::endl;
    std::cout << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "                    Printing table..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    hashTable.printTable();

    std::cout << "=====================================================" << std::endl;
    std::cout << "                    Emptying table..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;

    for (int i = ZERO; i < testdatasize; i++) {
        bool success = hashTable.removeEntry(ids[i]);
        if (success) {
            std::cout << " Removed the entry with id " << ids[i] << std::endl;
        } else {
            std::cout << " Failed to remove the entry with id " << ids[i] << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "                    Getting empty count..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;

    std::cout << "Number of entries: " << hashTable.getCount() << std::endl;
    std::cout << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "                    Printing empty table..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    hashTable.printTable();




    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.


    
    
    
    return 0;
}

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
    
    HashTable hashTable;

    // These tests will exercise the methods as they're intended to be used
    std::cout << "=====================================================" << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "Executing method tests..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "            Getting count..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    std::cout << " Number of entries: " << hashTable.getCount() << std::endl;
    std::cout << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "            Printing table..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    hashTable.printTable();

    std::cout << "=====================================================" << std::endl;
    std::cout << "            Filling table..." << std::endl;
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
    std::cout << "            Getting count..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    std::cout << " Number of entries: " << hashTable.getCount() << std::endl;
    std::cout << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "            Printing table..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    hashTable.printTable();

    std::cout << "=====================================================" << std::endl;
    std::cout << "            Getting data on full table..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;

    for (int i = ZERO; i < testdatasize; i++) {
        std::string data = hashTable.getData(ids[i]);
        if (!data.empty()) {
            std::cout << " Retrieved data for id " << ids[i] << ": \'" << data << "\'" << std::endl;
        } else {
            std::cout << " No data found for id " << ids[i] << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "            Emptying table..." << std::endl;
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
    std::cout << "            Getting empty count..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;

    std::cout << " Number of entries: " << hashTable.getCount() << std::endl;
    std::cout << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "            Printing empty table..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    hashTable.printTable();


    /*
     * These tests will exercise methods in ways in which we wouldn't expect them to
     * be used, such as attempting duplicate entries, getting data from an empty table,
     * or removing from an empty table.
    */
    std::cout << "=====================================================" << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << " Executing edge-case tests..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "            Removing from empty table..." << std::endl;
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
    std::cout << "            Getting data on empty table..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;

    for (int i = ZERO; i < testdatasize; i++) {
        std::string data = hashTable.getData(ids[i]);
        if (!data.empty()) {
            std::cout << " Retrieved data for id " << ids[i] << ": \'" << data << "\'" << std::endl;
        } else {
            std::cout << " No data found for id " << ids[i] << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "            Filling table for full tests..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;

    for (int i = ZERO; i < testdatasize; i++) {
        hashTable.insertEntry(ids[i], &strs[i]);
    }
    std::cout << " Table filled with test data for full edge case tests" << std::endl;
    std::cout << std::endl;
    std::cout << " Number of entries: " << hashTable.getCount() << std::endl;
    std::cout << std::endl;
    hashTable.printTable();

    std::cout << "=====================================================" << std::endl;
    std::cout << "            Attempting to add duplicates..." << std::endl;
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
    std::cout << "            Attempting to add invalid numbers..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;

    for (int i = ZERO; i > -HASH_TABLE_SIZE; i--) {
        Data data;
        data.id = i;
        data.data = strs[-i];
        bool success = hashTable.insertEntry(i, &data.data);
        if (success) {
            std::cout << " Inserted entry with id " << i << " and data \'" << data.data << "\'" << std::endl;
        } else {
            std::cout << " Failed to insert entry with id " << i << " and data \'" << data.data << "\'" << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "            Attempting to add empty strings..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;

    for (int i = ZERO; i < testdatasize; i++) {
        Data data;
        data.id = ids[i];
        data.data = EMPTY_STRING;
        bool success = hashTable.insertEntry(data.id, &data.data);
        if (success) {
            std::cout << " Inserted entry with id " << data.id << " and data \'" << data.data << "\'" << std::endl;
        } else {
            std::cout << " Failed to insert entry with id " << data.id << " and data \'" << data.data << "\'" << std::endl;
        }
    }
    std::cout << std::endl;

    return 0;
}

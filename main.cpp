/*********************
Name: Robert Payne
Coding 10
Purpose: Assignment 10 - Graph Abstract Data Type that is the final project for COSC-2436.
**********************/

#include "main.h"

int main() {

    /*
     *  Test data generation
     *  Generates test data with numbers between 1-100 and random strings
     */

    srand(time(NULL));

    vector<int> ids(testDataSize);
    vector<string> strs(testDataSize);

    set<int> unique_ids;

    for (int i = 0; i < testDataSize; ++i) {
        int unique_id = rand() % 100 + 1;

        while (unique_ids.find(unique_id) != unique_ids.end()) {
            unique_id = rand() % 100 + 1;
        }
        unique_ids.insert(unique_id);
        ids[i] = unique_id;

        string str;
        int length = rand() % 6 + 3;
        for (int j = 0; j < length; ++j) {
            str += 'a' + rand() % 26;
        }
        strs[i] = str;
    }

    /*
     *  End of test data generation
     */

    // ToDo - Add method testing
    cout << "=====================================================" << endl;
    cout << "            Generating graph..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    Graph myGraph;

    cout << "=====================================================" << endl;
    cout << "            Adding vertices..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    for (int i = 0; i < testDataSize; ++i) {
        bool success = myGraph.addVertex(ids[i], &strs[i]);
        if (success) {
            cout << " Added vertex with id " << ids[i] << " and info \'" << strs[i] << "\'." << endl;
        } else {
            cout << " Failed to add vertex with id " << ids[i] << " and info \'" << strs[i] << "\'." << endl;
        }
    }
    cout << endl;

    // ToDo - Add edge-case testing

    // ToDo - Add random testing

    return 0;
}
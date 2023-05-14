/*********************
Name: Robert Payne
Coding 10
Purpose: Assignment 10 - Graph Abstract Data Type that is the final project for COSC-2436.
**********************/

#include "main.h"

int main() {

    Graph myGraph;

    // ToDo - Add test data generation (make this more robust)
    int testdatasize = 5;
    vector<int> ids{1, 2, 3, 4, 5};
    vector<string> strs{"First", "Second", "Third", "Fourth", "Fifth"};

    // ToDo - Add method testing
    cout << "=====================================================" << endl;
    cout << "            Adding vertices..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    for (int i = 0; i < testdatasize; i++) {
        bool success = myGraph.addVertex(ids[i], &strs[i]);
        if (success) {
            cout << " Added vertex with id " << ids[i] << " and information \'" << strs[i] << "\'" << endl;
        } else {
            cout << " Failed to add vertex with id " << ids[i] << " and information \'" << strs[i] << "\'" << endl;
        }
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "            Adding edges..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    for (int i = 0; i < testdatasize - 1; i++) {
        bool success = myGraph.addEdge(ids[i], ids[i+1]);
        if (success) {
            cout << " Added edge between vertices " << ids[i] << " and " << ids[i+1] << endl;
        } else {
            cout << " Failed to add edge between vertices " << ids[i] << " and " << ids[i+1] << endl;
        }
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "            Printing adjacency list..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    myGraph.printAdjacencyList();

    // ToDo - Add edge-case testing

    // ToDo - Add random testing

    return 0;
}
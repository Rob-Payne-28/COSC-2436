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

    cout << "=====================================================" << endl;
    cout << "            Adding edges..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    for (int i = 0; i < testDataSize - 1; ++i) {
        bool success = myGraph.addEdge(ids[i], ids[i+1]);
        if (success) {
            cout << " Added edge between " << ids[i] << " and " << ids[i+1] << "." << endl;
        } else {
            cout << " Failed to add edge between " << ids[i] << " and " << ids[i+1] << "." << endl;
        }
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "            Getting vertices..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    vector<Vertex> vertices;
    if (myGraph.getVertices(vertices)) {
        cout << " Retrieved vertices:" << endl;
        for (int i = 0; i < vertices.size(); ++i) {
            cout << " Vertex with id " << vertices[i].id << " and information '" << vertices[i].information << "'" << endl;
        }
    } else {
        cout << " Failed to retrieve vertices." << endl;
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "            Getting edges..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    vector<Edge> edges;
    if (myGraph.getEdges(edges)) {
        cout << " Retrieved edges:" << endl;
        for (int i = 0; i < edges.size(); ++i) {
            cout << " Edge between " << edges[i].vertex1 << " and " << edges[i].vertex2 << endl;
        }
    } else {
        cout << " Failed to retrieve edges." << endl;
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "            Getting adjacent vertices..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    for (int i = 0; i < testDataSize; ++i) {
        vector<Vertex> adjacentVertices;
        if (myGraph.getAdjacent(ids[i], adjacentVertices)) {
            cout << " Retrieved adjacent vertices for vertex " << ids[i] << ":" << endl;
            for (int j = 0; j < adjacentVertices.size(); ++j) {
                cout << " Vertex with id " << adjacentVertices[j].id << " and information '" << adjacentVertices[j].information << "'" << endl;
            }
        } else {
            cout << " Failed to retrieve adjacent vertices for vertex " << ids[i] << "." << endl;
        }
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "            Removing edges..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    for (int i = 0; i < testDataSize - 1; ++i) {
        bool success = myGraph.removeEdge(ids[i], ids[i+1]);
        if (success) {
            cout << " Removed edge between " << ids[i] << " and " << ids[i+1] << "." << endl;
        } else {
            cout << " Failed to remove edge between " << ids[i] << " and " << ids[i+1] << "." << endl;
        }
    }
    cout << endl;


    // ToDo - Add edge-case testing

    // ToDo - Add random testing

    return 0;
}
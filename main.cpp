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

    vector<int> ids(TEST_DATA_SIZE);
    vector<string> strs(TEST_DATA_SIZE);

    set<int> unique_ids;

    for (int i = ZERO; i < TEST_DATA_SIZE; ++i) {
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

    cout << "=====================================================" << endl;
    cout << "            Generating graph..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    Graph myGraph;
    cout << "Complete!" << endl;
    cout << endl;

    /*
     *  Start Method Testing
     */

    cout << "=====================================================" << endl;
    cout << "            Adding vertices..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    for (int i = ZERO; i < TEST_DATA_SIZE; ++i) {
        bool success = myGraph.addVertex(ids[i], &strs[i]);
        if (success) {
            cout << " Added vertex with id " << ids[i] << " and info \'" << strs[i] << "\'" << endl;
        } else {
            cout << " Failed to add vertex with id " << ids[i] << " and info \'" << strs[i] << "\'" << endl;
        }
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "            Adding edges..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    for (int i = ZERO; i < TEST_DATA_SIZE - 1; ++i) {
        bool success = myGraph.addEdge(ids[i], ids[i+1]);
        if (success) {
            cout << " Added edge between " << ids[i] << " and " << ids[i+1] << endl;
        } else {
            cout << " Failed to add edge between " << ids[i] << " and " << ids[i+1] << endl;
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
        for (int i = ZERO; i < vertices.size(); ++i) {
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
        for (int i = ZERO; i < edges.size(); ++i) {
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

    for (int i = ZERO; i < TEST_DATA_SIZE; ++i) {
        vector<Vertex> adjacentVertices;
        if (myGraph.getAdjacent(ids[i], adjacentVertices)) {
            cout << " Retrieved adjacent vertices for vertex " << ids[i] << ":" << endl;
            for (int j = ZERO; j < adjacentVertices.size(); ++j) {
                cout << "  Vertex with id " << adjacentVertices[j].id << " and information '" << adjacentVertices[j].information << "'" << endl;
            }
        } else {
            cout << "  Failed to retrieve adjacent vertices for vertex " << ids[i] << endl;
        }
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "            Printing adjacency matrix..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    myGraph.printAdjacencyMatrix();
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "            Printing adjacency list..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    myGraph.printAdjacencyList();
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "            Breadth first search..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    for (int i = ZERO; i < TEST_DATA_SIZE; ++i) {
        vector<Vertex> bfsTraversal;
        myGraph.breadthFirstSearch(ids[i], bfsTraversal);

        cout << " Starting with " << ids[i] << ": ";
        for (int j = ZERO; j < bfsTraversal.size(); ++j) {
            cout << bfsTraversal[j].id;
            if (j != bfsTraversal.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "            Depth first search..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    for (int i = ZERO; i < TEST_DATA_SIZE; ++i) {
        vector<Vertex> dfsTraversal;
        myGraph.depthFirstSearch(ids[i], dfsTraversal);

        cout << " Starting with " << ids[i] << ": ";
        for (int j = ZERO; j < dfsTraversal.size(); ++j) {
            cout << dfsTraversal[j].id;
            if (j != dfsTraversal.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "            Removing edges..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    for (int i = ZERO; i < TEST_DATA_SIZE - 1; ++i) {
        bool success = myGraph.removeEdge(ids[i], ids[i+1]);
        if (success) {
            cout << " Removed edge between " << ids[i] << " and " << ids[i+1] << endl;
        } else {
            cout << " Failed to remove edge between " << ids[i] << " and " << ids[i+1] << endl;
        }
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "            Removing vertices..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    for (int i = ZERO; i < TEST_DATA_SIZE; ++i) {
        bool success = myGraph.removeVertex(ids[i]);
        if (success) {
            cout << " Removed vertex with id " << ids[i] << endl;
        } else {
            cout << " Failed to remove vertex with id " << ids[i] << endl;
        }
    }
    cout << endl;

    /*
     *  Start Edge Case testing
     */
    // ToDo - Add edge-case testing

    cout << "=====================================================" << endl;
    cout << "            Testing edge case: Adding an already existing vertex..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    myGraph.addVertex(ids[0], &strs[0]);
    bool success = myGraph.addVertex(ids[0], &strs[0]);
    if (success) {
        cout << " Added vertex with id " << ids[0] << " and information \'" << strs[0] << "\'" << endl;
    } else {
        cout << " Failed to add vertex with id " << ids[0] << " and information \'" << strs[0] << "\'" << endl;
    }
    cout << endl;


    // ToDo - Add random testing

    return 0;
}
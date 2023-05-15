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

    for (int i = ZERO; i < TEST_DATA_SIZE - ONE; ++i) {
        bool success = myGraph.addEdge(ids[i], ids[i+1]);
        if (success) {
            cout << " Added edge between " << ids[i] << " and " << ids[i+ONE] << endl;
        } else {
            cout << " Failed to add edge between " << ids[i] << " and " << ids[i+ONE] << endl;
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
            if (j != bfsTraversal.size() - ONE) {
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
            if (j != dfsTraversal.size() - ONE) {
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

    for (int i = ZERO; i < TEST_DATA_SIZE - ONE; ++i) {
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

    cout << "=====================================================" << endl;
    cout << "Testing edge case: Adding an already existing vertex..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    myGraph.addVertex(ids[ZERO], &strs[ZERO]); // Add vertex before test
    bool success = myGraph.addVertex(ids[ZERO], &strs[ZERO]);
    if (success) {
        cout << " Added vertex with id " << ids[ZERO] << " and information \'" << strs[ZERO] << "\'" << endl;
    } else {
        cout << " Failed to add vertex with id " << ids[ZERO] << " and information \'" << strs[ZERO] << "\'" << endl;
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "Testing edge case: Adding an already existing edge..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    myGraph.addEdge(ids[ZERO], ids[ONE]); // Add edge before test
    success = myGraph.addEdge(ids[ZERO], ids[ONE]);
    if (success) {
        cout << " Added edge between vertices " << ids[ZERO] << " and " << ids[ONE] << endl;
    } else {
        cout << " Failed to add edge between vertices " << ids[ZERO] << " and " << ids[ONE] << endl;
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "Testing edge case: Removing a non-existent vertex..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    success = myGraph.removeVertex(FIRST_BAD_ID);
    if (success) {
        cout << " Removed vertex 101" << endl;
    } else {
        cout << " Failed to remove vertex 101" << endl;
    }
    cout << endl;


    cout << "=====================================================" << endl;
    cout << "Testing edge case: Removing a non-existent edge..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    success = myGraph.removeEdge(FIRST_BAD_ID, SECOND_BAD_ID);
    if (success) {
        cout << " Removed edge between vertices 101 and 102" << endl;
    } else {
        cout << " Failed to remove edge between vertices 101 and 102" << endl;
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "Testing edge case: Checking for the existence of a non-existent vertex..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    bool exists = myGraph.hasVertex(FIRST_BAD_ID);
    if (exists) {
        cout << " Vertex 101 exists" << endl;
    } else {
        cout << " Vertex 101 does not exist" << endl;
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "Testing edge case: Checking for the existence of a non-existent edge..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    exists = myGraph.hasEdge(FIRST_BAD_ID, SECOND_BAD_ID);
    if (exists) {
        cout << " Edge between vertices 101 and 102 exists" << endl;
    } else {
        cout << " Edge between vertices 101 and 102 does not exist" << endl;
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "Testing edge case: Adding an edge between non-existent vertices..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    success = myGraph.addEdge(FIRST_BAD_ID, SECOND_BAD_ID);
    if (success) {
        cout << " Added edge between vertices 101 and 102" << endl;
    } else {
        cout << " Failed to add edge between vertices 101 and 102" << endl;
    }
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "Testing edge case: Performing BFS from a non-existent vertex..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    vector<Vertex> bfsTraversal;
    myGraph.breadthFirstSearch(FIRST_BAD_ID, bfsTraversal);

    cout << " BFS starting with 101: ";
    if (bfsTraversal.empty()) {
        cout << "No such vertex found.";
    } else {
        for (int j = ZERO; j < bfsTraversal.size(); ++j) {
            cout << bfsTraversal[j].id;
            if (j != bfsTraversal.size() - ONE) {
                cout << " -> ";
            }
        }
    }
    cout << endl;
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "Testing edge case: Performing DFS from a non-existent vertex..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    vector<Vertex> dfsTraversal;
    myGraph.depthFirstSearch(FIRST_BAD_ID, dfsTraversal);

    cout << " DFS starting with 101: ";
    if (dfsTraversal.empty()) {
        cout << "No such vertex found.";
    } else {
        for (int j = ZERO; j < dfsTraversal.size(); ++j) {
            cout << dfsTraversal[j].id;
            if (j != dfsTraversal.size() - ONE) {
                cout << " -> ";
            }
        }
    }
    cout << endl;
    cout << endl;

    /*
     *  Start random testing
     */

    cout << "=====================================================" << endl;
    cout << "=====================================================" << endl;
    cout << "            Executing random tests..." << endl;
    cout << "=====================================================" << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "            Filling graph for testing..." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    for (int i = ZERO; i < TEST_DATA_SIZE / 2; i++) {
        myGraph.addVertex(ids[i], &strs[i]);
    }

    for (int i = ZERO; i < TEST_DATA_SIZE / 2 - ONE; i++) {
        myGraph.addEdge(ids[i], ids[i + ONE]);
    }

    cout << " Graph filled with test data for full random tests" << endl;
    cout << endl;

    myGraph.printAdjacencyList();
    cout << endl;
    myGraph.printAdjacencyMatrix();
    cout << endl;

    int randNum = rand();
    int selection = std::abs(randNum) % POSSIBLE_SELECTIONS + ONE;
    int randId = rand() % MAX_VERTEX_ID;
    bool successful;
    for (int i = ZERO; i < MAX_VERTEX_ID * TEST_MULTIPLIER; i++) {
        Vertex vertex;
        vector<Vertex> vertices;
        vector<Edge> edges;
        vector<Vertex> adjacentVertices;
        int size;
        vector<Vertex> bfsVertices;
        switch (selection) {

            case 1:
                cout << " Add vertex..." << endl;
                vertex.id = randId;
                vertex.information = "vertex_" + std::to_string(randId);
                successful = myGraph.addVertex(randId, &vertex.information);
                if (successful) {
                    cout << " Added vertex with id " << randId << endl;
                } else {
                    cout << " Failed to add vertex with id " << randId << endl;
                }
                cout << endl;
                break;

            case 2:
                cout << " Remove vertex..." << endl;
                successful = myGraph.removeVertex(randId);
                if (successful) {
                    cout << " Removed vertex with id " << randId << endl;
                } else {
                    cout << " Failed to remove vertex with id " << randId << endl;
                }
                cout << endl;
                break;

            case 3:
                cout << " Add edge..." << endl;
                successful = myGraph.addEdge(randId, (randId + ONE) % MAX_VERTEX_ID);
                if (successful) {
                    cout << " Added edge between vertices " << randId << " and " << (randId + ONE) % MAX_VERTEX_ID << endl;
                } else {
                    cout << " Failed to add edge between vertices " << randId << " and " << (randId + ONE) % MAX_VERTEX_ID << endl;
                }
                cout << endl;
                break;

            case 4:
                cout << " Remove edge..." << endl;
                successful = myGraph.removeEdge(randId, (randId + ONE) % MAX_VERTEX_ID);
                if (successful) {
                    cout << " Removed edge between vertices " << randId << " and " << (randId + ONE) % MAX_VERTEX_ID << endl;
                } else {
                    cout << " Failed to remove edge between vertices " << randId << " and " << (randId + ONE) % MAX_VERTEX_ID << endl;
                }
                cout << endl;
                break;

            case 5:
                cout << " Get vertices..." << endl;
                successful = myGraph.getVertices(vertices);
                if (successful) {
                    cout << " Retrieved vertices:" << endl;
                    for (int i = ZERO; i < vertices.size(); ++i) {
                        cout << "  Vertex ID: " << vertices[i].id << ", Information: " << vertices[i].information << endl;
                    }
                } else {
                    cout << " Failed to retrieve vertices" << endl;
                }
                cout << endl;
                break;

            case 6:
                cout << " Get edges..." << endl;
                successful = myGraph.getEdges(edges);
                if (successful) {
                    cout << " Retrieved edges:" << endl;
                    for (int i = ZERO; i < edges.size(); ++i) {
                        cout << "  Edge between vertices " << edges[i].vertex1 << " and " << edges[i].vertex2 << endl;
                    }
                } else {
                    cout << " Failed to retrieve edges" << endl;
                }
                cout << endl;
                break;

            case 7:
                cout << " Get adjacent vertices..." << endl;
                successful = myGraph.getAdjacent(randId, adjacentVertices);
                if (successful) {
                    cout << " Retrieved adjacent vertices for vertex " << randId << ":" << endl;
                    for (int i = ZERO; i < adjacentVertices.size(); ++i) {
                        cout << "  Vertex ID: " << adjacentVertices[i].id << ", Information: " << adjacentVertices[i].information << endl;
                    }
                } else {
                    cout << " Failed to retrieve adjacent vertices for vertex " << randId << endl;
                }
                cout << endl;
                break;

            case 8:
                cout << " Check if vertex exists..." << endl;
                successful = myGraph.hasVertex(randId);
                if (successful) {
                    cout << " Vertex with id " << randId << " exists in the graph." << endl;
                } else {
                    cout << " Vertex with id " << randId << " does not exist in the graph." << endl;
                }
                cout << endl;
                break;

            case 9:
                cout << " Check if edge exists..." << endl;
                successful = myGraph.hasEdge(randId, (randId + ONE) % MAX_VERTEX_ID);
                if (successful) {
                    cout << " Edge between vertices " << randId << " and " << (randId + ONE) % MAX_VERTEX_ID << " exists in the graph." << endl;
                } else {
                    cout << " Edge between vertices " << randId << " and " << (randId + ONE) % MAX_VERTEX_ID << " does not exist in the graph." << endl;
                }
                cout << endl;
                break;

            case 10:
                cout << " Get graph size..." << endl;
                size = myGraph.size();
                cout << " The size of the graph is: " << size << endl;
                cout << endl;
                break;

            case 11:
                cout << " Perform breadth-first search..." << endl;
                myGraph.breadthFirstSearch(randId, bfsVertices);
                if (!bfsVertices.empty()) {
                    cout << " Breadth-first search starting from vertex " << randId << ": " << endl;
                    for (int i = ZERO; i < bfsVertices.size(); ++i) {
                        cout << "  Vertex ID: " << bfsVertices[i].id << ", Information: " << bfsVertices[i].information << endl;
                    }
                } else {
                    cout << " Failed to perform breadth-first search from vertex " << randId << endl;
                }
                cout << endl;
                break;

        }
        randNum = rand();
        selection = std::abs(randNum) % POSSIBLE_SELECTIONS + ONE;
        randId = rand() % MAX_VERTEX_ID;
    }

    return 0;
}
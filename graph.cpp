/*********************
Name: Robert Payne
Coding 10
Purpose: Assignment 10 - Graph Abstract Data Type that is the final project for COSC-2436.
**********************/

#include "graph.h"

// ToDo - Constructor
Graph::Graph() {}
// ToDo - Deconstructor
Graph::~Graph() {}

// Methods to build and remove nodes/edges
bool Graph::addVertex(int id, string information) {
    // define return variable
    bool success = false;

    // check to see if this node is already in the graph
    if(vertices.find(id) != vertices.end()) {
        // if not, create a new one and add the attributes
        Vertex newVertex;
        newVertex.id = id;
        newVertex.information = information;

        // add it to the map
        vertices[id] = newVertex;
        success = true;
    }

    return success;
}

bool Graph::removeVertex(int) {
    return false; // ToDo - removeVertex
}

bool Graph::addEdge(int, int) {
    return false; // ToDo - addEdge
}

bool Graph::removeEdge(int, int) {
    return false; // ToDo - removeEdge
}

// Methods to find things
bool Graph::getVertices(vector <Vertex> &) {
    return false; // ToDo - getVertices
}

bool Graph::getEdges(vector <Edge> &) {
    return false; // ToDo - getEdges
}

bool Graph::getAdjacent(int, vector <Vertex> &) {
    return false; // ToDo - getAdjacent
}

// Helper methods (called by other methods to reduce complexity)
bool Graph::hasVertex(int) {
    return false; // ToDo - hasVertex
}

bool Graph::hasEdge(int, int) {
    return false; // ToDo - hasEdge
}

int Graph::size() {
    return 0;// ToDo - size
}

// Not sure if we're going to need these, but they'd be nice to add if we have time
bool Graph::breadthFirstSearch(int, vector <Vertex> &) {
    return false; // ToDo - BFS
}

bool Graph::depthFirstSearch(int, vector <Vertex> &) {
    return false; // ToDo - DFS
}

void Graph::printAdjacencyMatrix() {
    // ToDo - printAdjacencyMatrix
}

void Graph::printAdjacencyList() {
    // ToDo - printAdjacencyList
}

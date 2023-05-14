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
bool Graph::addVertex(int, std::string) {
    return false; // ToDo - addVertex
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

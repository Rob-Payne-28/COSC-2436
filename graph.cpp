/*********************
Name: Robert Payne
Coding 10
Purpose: Assignment 10 - Graph Abstract Data Type that is the final project for COSC-2436.
**********************/

#include "graph.h"

Graph::Graph() {
    // ToDo - Constructor
}

Graph::~Graph() {
    // ToDo - Deconstructor
}

// Methods to build and remove nodes/edges
bool Graph::addVertex(int id, string* information) {
    bool success = false;

    if(id > 0 && information && *information != "") {
        // check to see if this node is already in the graph
        if(vertices.find(id) == vertices.end()) {

            Vertex newVertex;
            newVertex.id = id;
            newVertex.information = *information;

            vertices[id] = newVertex;
            success = true;
        }
    }

    return success;
}

bool Graph::removeVertex(int) {
    return false; // ToDo - removeVertex
}

bool Graph::addEdge(int vertex1, int vertex2) {
    bool success = false;

    // ToDo - clean this up

    // check incoming data
    if(vertex1 > 0 || vertex2 > 0) {
        // check that vertices exist in graph
        if(vertices.find(vertex1) != vertices.end() && vertices.find(vertex2) != vertices.end()) {

            // check that edge doesn't already exist
            std::vector<int>& vertex1Edges = adjacencyList[vertex1];
            for (int i = 0; i < vertex1Edges.size(); ++i) {
                if(vertex1Edges[i] != vertex2) {
                    // push data to both vertices
                    adjacencyList[vertex1].push_back(vertex2);
                    adjacencyList[vertex2].push_back(vertex1);
                    success = true;
                }
            }
        }
    }

    return success;
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

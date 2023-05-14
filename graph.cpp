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

bool Graph::removeVertex(int id) {
    bool success = false;

    // validate input
    // make sure vertex exists
    if(id > 0 && vertices.find(id) != vertices.end()) {
        // remove from map
        vertices.erase(id);

        // ToDo - remove edges using remove edge method

        adjacencyList.erase(id);
        success = true;
    }

    return success;
}

bool Graph::addEdge(int vertex1, int vertex2) {
    bool success = false;

    if(vertex1 > 0 && vertex2 > 0) {
        if(vertices.find(vertex1) != vertices.end() && vertices.find(vertex2) != vertices.end()) {

            std::vector<int>& vertex1Edges = adjacencyList[vertex1];
            bool edgeExists = false;

            for (int i = 0; i < vertex1Edges.size(); ++i) {
                if(vertex1Edges[i] == vertex2) {
                    edgeExists = true;
                    break;
                }
            }

            if (!edgeExists) {
                adjacencyList[vertex1].push_back(vertex2);
                adjacencyList[vertex2].push_back(vertex1);
                success = true;
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
    int mapSize = adjacencyList.size();

    // C++ has type inference!! https://www.geeksforgeeks.org/type-inference-in-c-auto-and-decltype/
    auto iterator = adjacencyList.begin();

    for(int i = 0; i < mapSize; ++i, ++iterator) {
        int vertexID = iterator->first;
        const vector<int>& edges = iterator->second;

        std::cout << "Vertex " << vertexID << " is connected to: ";

        for(int j = 0; j < edges.size(); ++j) {
            std::cout << edges[j] << " ";
        }

        std::cout << std::endl;
    }
}

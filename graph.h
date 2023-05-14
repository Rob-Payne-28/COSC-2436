/*********************
Name: Robert Payne
Coding 10
Purpose: Assignment 10 - Graph Abstract Data Type that is the final project for COSC-2436.
**********************/

#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <vector>
#include "vertex.h"

class Graph {

public:
    Graph();
    ~Graph();

    // Methods to build and remove nodes/edges
    bool addVertex(int, std::string);
    bool removeVertex(int);
    bool addEdge(int, int);
    bool removeEdge(int, int);

    // Methods to find things
    bool getVertices(std::vector<Vertex>&);
    bool getEdges(); // ToDo - figure out how I'm going to do this from the adjacency list
    bool getAdjacent(int, std::vector<Vertex>&);

    // Helper methods (called by other methods to reduce complexity)
    bool hasVertex(int);
    bool hasEdge(int, int);
    int size();

    // Not sure if we're going to need these, but they'd be nice to add if we have time
    bool breadthFirstSearch(); // ToDo - figure out what to pass in. Start id and a vector to return values?
    bool depthFirstSearch(); // ToDo - figure out what to pass in. Start id and a vector to return values?
    void printAdjacencyMatrix(); // ToDo - printAdjacencyMatrix
    void printAdjacencyList(); // ToDo - printAdjacencyList

private:
    // Member variables
    std::map<int, Vertex> vertices;
    std::map<int, std::vector<int>> adjacencyList;

    // Private methods (May move helper methods here)

};

#endif //GRAPH_H

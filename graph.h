/*********************
Name: Robert Payne
Coding 10
Purpose: Assignment 10 - Graph Abstract Data Type that is the final project for COSC-2436.
**********************/

#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "vertex.h"
#include "edge.h"

using std::vector;
using std::map;
using std::string;
using std::find;

class Graph {

public:
    Graph();
    ~Graph();

    // Methods to build and remove nodes/edges
    bool addVertex(int, string*);
    bool removeVertex(int);
    bool addEdge(int, int);
    bool removeEdge(int, int);

    // Methods to find things
    bool getVertices(vector<Vertex>&);
    bool getEdges(vector<Edge>&);
    bool getAdjacent(int, vector<Vertex>&);

    // Helper methods (called by other methods to reduce complexity)
    bool hasVertex(int);
    bool hasEdge(int, int);
    int size();

    // Not sure if we're going to need these, but they'd be nice to add if we have time
    bool breadthFirstSearch(int, vector<Vertex>&);
    bool depthFirstSearch(int, vector<Vertex>&);
    void printAdjacencyMatrix();
    void printAdjacencyList();

private:
    // Member variables
    map<int, Vertex> vertices;
    map<int, vector<int>> adjacencyList;

};

#endif //GRAPH_H

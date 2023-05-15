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
#include <algorithm>
#include <queue> // For BFS
#include <iomanip> // For matrix formatting
#include "vertex.h"
#include "edge.h"

using std::vector;
using std::map;
using std::string;
using std::find;
using std::cout;
using std::endl;
using std::queue;
using std::setw;

class Graph {

public:
    Graph();
    ~Graph();

    bool addVertex(int, string*);
    bool removeVertex(int);
    bool addEdge(int, int);
    bool removeEdge(int, int);

    bool getVertices(vector<Vertex>&);
    bool getEdges(vector<Edge>&);
    bool getAdjacent(int, vector<Vertex>&);

    bool hasVertex(int);
    bool hasEdge(int, int);
    int size();

    void breadthFirstSearch(int, vector<Vertex>&);
    void depthFirstSearch(int, vector<Vertex>&);
    void printAdjacencyMatrix();
    void printAdjacencyList();

private:
    map<int, Vertex> vertices;
    map<int, vector<int>> adjacencyList;

    // helper method for DFS
    void DFSVisit(int, map<int, bool>&, vector<Vertex>&);
};

#endif //GRAPH_H

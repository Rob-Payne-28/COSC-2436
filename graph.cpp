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

        // find all the edges associated with the vertex
        auto& edges = adjacencyList[id];
        // remove them in reverse order so we don't mess up the vector (they shift)
        for (int i = edges.size() - 1; i >= 0; --i) {
            removeEdge(id, edges[i]);
        }

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

bool Graph::removeEdge(int vertexOneId, int vertexTwoId) {
    bool success = false;

    // if both vertices are in our vertices map
    if(vertices.find(vertexOneId) != vertices.end() && vertices.find(vertexTwoId) != vertices.end()) {

        // get the adjacency list for each vertex
        auto& edges1 = adjacencyList[vertexOneId];
        auto& edges2 = adjacencyList[vertexTwoId];

        // find the edge connecting the two vertices in each of the vectors
        auto iterator1 = find(edges1.begin(), edges1.end(), vertexTwoId);
        auto iterator2 = find(edges2.begin(), edges2.end(), vertexOneId);

        // if the iterators find each of the edges, delete them and set succes to true
        if(iterator1 != edges1.end() && iterator2 != edges2.end()) {
            edges1.erase(iterator1);
            edges2.erase(iterator2);
            success = true;
        }
    }

    return success;
}

// Methods to find things
bool Graph::getVertices(vector <Vertex> &verticesToReturn) {
    bool success = false;

    if (!vertices.empty()) {
        for (auto& vertex : vertices) {
            verticesToReturn.push_back(vertex.second);
        }
        success = true;
    }

    return success;
}

bool Graph::getEdges(vector <Edge> &edgesToReturn) {
    bool success = false;

    if (!adjacencyList.empty()) {
        // ToDo - swap standard for loops for these "enhanced" loops
        for (auto& vertex : adjacencyList) {
            int vertexId = vertex.first;
            for (int neighbor : vertex.second) {
                if (vertexId < neighbor) {
                    Edge edge;
                    edge.vertex1 = vertexId;
                    edge.vertex2 = neighbor;
                    edgesToReturn.push_back(edge);
                }
            }
        }
        success = true;
    }
    return success;
}

bool Graph::getAdjacent(int id, vector <Vertex> &adjacent) {
    bool success = false;

    if (vertices.find(id) != vertices.end()) {
        vector<int>& adjacencies = adjacencyList[id];
        for (int adjacentId : adjacencies) {
            if (vertices.find(adjacentId) != vertices.end()) {
                adjacent.push_back(vertices[adjacentId]);
            }
        }
        // ToDo - What happens if there are no adjacencies?
        success = true;
    }

    return success;
}

// Helper methods (called by other methods to reduce complexity)
bool Graph::hasVertex(int id) {
    // ToDo - replace these checks with a call to this method
    return vertices.find(id) != vertices.end();
}

bool Graph::hasEdge(int vertexOneId, int vertexTwoId) {
    bool success = false;

    if (vertices.find(vertexOneId) != vertices.end() && vertices.find(vertexTwoId) != vertices.end()) {
        auto& edges = adjacencyList[vertexOneId];

        success = find(edges.begin(), edges.end(), vertexTwoId) != edges.end();
    }

    return success;
}

int Graph::size() {
    return vertices.size();
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
        vector<int>& edges = iterator->second;

        std::cout << "Vertex " << vertexID << " is connected to: ";

        for(int j = 0; j < edges.size(); ++j) {
            std::cout << edges[j] << " ";
        }

        std::cout << std::endl;
    }
}

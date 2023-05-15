/*********************
Name: Robert Payne
Coding 10
Purpose: Assignment 10 - Graph Abstract Data Type that is the final project for COSC-2436.
**********************/

#include "graph.h"

Graph::Graph() {
}

Graph::~Graph() {
}

bool Graph::addVertex(int id, string* information) {
    bool success = false;

    if(id > 0 && information && *information != "") {
        if(!hasVertex(id)) {
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

    if(id > 0 && hasVertex(id)) {
        vertices.erase(id);

        auto& edges = adjacencyList[id];
        for (auto& edge : edges) {
            removeEdge(id, edge);
        }

        adjacencyList.erase(id);
        success = true;
    }

    return success;
}

bool Graph::addEdge(int vertex1, int vertex2) {
    bool success = false;

    if(vertex1 > 0 && vertex2 > 0 && hasVertex(vertex1) && hasVertex(vertex2)) {
        auto& vertex1Edges = adjacencyList[vertex1];

        if (!hasEdge(vertex1, vertex2)) {
            adjacencyList[vertex1].push_back(vertex2);
            adjacencyList[vertex2].push_back(vertex1);
            success = true;
        }
    }

    return success;
}

bool Graph::removeEdge(int vertexOneId, int vertexTwoId) {
    bool success = false;

    if(hasVertex(vertexOneId) && hasVertex(vertexTwoId)) {
        auto& edges1 = adjacencyList[vertexOneId];
        auto& edges2 = adjacencyList[vertexTwoId];

        auto iterator1 = find(edges1.begin(), edges1.end(), vertexTwoId);
        auto iterator2 = find(edges2.begin(), edges2.end(), vertexOneId);

        if(iterator1 != edges1.end() && iterator2 != edges2.end()) {
            edges1.erase(iterator1);
            edges2.erase(iterator2);
            success = true;
        }
    }

    return success;
}

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

    if (hasVertex(id)) {
        vector<int>& adjacencies = adjacencyList[id];
        for (int adjacentId : adjacencies) {
            if (hasVertex(adjacentId)) {
                adjacent.push_back(vertices[adjacentId]);
            }
        }
        success = !adjacent.empty();
    }

    return success;
}

bool Graph::hasVertex(int id) {
    return vertices.find(id) != vertices.end();
}

bool Graph::hasEdge(int vertexOneId, int vertexTwoId) {
    bool success = false;

    if (hasVertex(vertexOneId) && hasVertex(vertexTwoId)) {
        auto& edges = adjacencyList[vertexOneId];

        success = find(edges.begin(), edges.end(), vertexTwoId) != edges.end();
    }

    return success;
}

int Graph::size() {
    return vertices.size();
}

void Graph::breadthFirstSearch(int startId, vector <Vertex> &visitedOrder) {
    if (hasVertex(startId)) {
        map<int, bool> visited;
        queue<int> toVisit;

        for (auto &vertex : vertices) {
            visited[vertex.first] = false;
        }

        visited[startId] = true;
        toVisit.push(startId);

        while (!toVisit.empty()) {
            int currentId = toVisit.front();
            toVisit.pop();
            visitedOrder.push_back(vertices[currentId]);

            for (auto i = adjacencyList[currentId].begin(); i != adjacencyList[currentId].end(); ++i) {
                if (!visited[*i]) {
                    toVisit.push(*i);
                    visited[*i] = true;
                }
            }
        }
    }
}

void Graph::depthFirstSearch(int startId, vector<Vertex> &visitedOrder) {
    map<int, bool> visited;

    for (auto &vertex : vertices) {
        visited[vertex.first] = false;
    }

    DFSVisit(startId, visited, visitedOrder);
}


void Graph::DFSVisit(int startId, map<int, bool> &visited, vector<Vertex> &visitedOrder) {
    if (hasVertex(startId)) {
        visited[startId] = true;
        visitedOrder.push_back(vertices[startId]);

        for (auto i = adjacencyList[startId].begin(); i != adjacencyList[startId].end(); ++i) {
            if (!visited[*i]) {
                DFSVisit(*i, visited, visitedOrder);
            }
        }
    }
}


void Graph::printAdjacencyMatrix() {
    // Map vertex ids to indices and vice versa
    std::map<int, int> vertexIdToIndex;
    std::vector<int> indexToVertexId;
    int index = 1;
    for (auto& vertex : vertices) {
        vertexIdToIndex[vertex.first] = index;
        indexToVertexId.push_back(vertex.first);
        ++index;
    }

    int size = vertices.size();

    vector<vector<int>> matrix(size+1, vector<int>(size+1, 0));

    for (auto& vertex : vertices) {
        int i = vertexIdToIndex[vertex.first];
        for (int vertexId : adjacencyList[vertex.first]) {
            int j = vertexIdToIndex[vertexId];

            // Set the corresponding cells to 1
            matrix[i][j] = 1;
            matrix[j][i] = 1;
        }
    }

    cout << setw(3) << " ";
    for (int i = 1; i <= size; ++i) {
        cout << setw(3) << indexToVertexId[i-1];
    }
    cout << endl;

    for (int i = 1; i <= size; ++i) {
        cout << setw(3) << indexToVertexId[i-1];
        for (int j = 1; j <= size; ++j) {
            cout << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

void Graph::printAdjacencyList() {
    int mapSize = adjacencyList.size();

    // C++ has type inference!! https://www.geeksforgeeks.org/type-inference-in-c-auto-and-decltype/
    auto iterator = adjacencyList.begin();

    for(int i = 0; i < mapSize; ++i, ++iterator) {
        int vertexID = iterator->first;
        vector<int>& edges = iterator->second;

        cout << "Vertex " << vertexID << " is connected to: ";

        for(int j = 0; j < edges.size(); ++j) {
            cout << edges[j] << " ";
        }

        cout << endl;
    }
}

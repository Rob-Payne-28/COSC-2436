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

bool Graph::addVertex(int id, string* data) {
    bool success = false;

    if(id > ZERO && data && *data != EMPTY_STRING) {
        if(!hasVertex(id)) {
            Vertex newVertex;
            newVertex.id = id;
            newVertex.data = *data;

            vertices[id] = newVertex;
            success = true;
        }
    }

    return success;
}

bool Graph::removeVertex(int id) {
    bool success = false;

    if(id > ZERO && hasVertex(id)) {
        vector<int> edges = adjacencyList[id];
        for (auto& edge : edges) {
            removeEdge(id, edge);
        }

        vertices.erase(id);
        adjacencyList.erase(id);

        success = true;
    }

    return success;
}

bool Graph::addEdge(int vertex1, int vertex2) {
    bool success = false;

    if(vertex1 > ZERO && vertex2 > ZERO && hasVertex(vertex1) && hasVertex(vertex2)) {
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

            for (auto &neighbor : adjacencyList[currentId]) {
                if (!visited[neighbor]) {
                    toVisit.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
}

void Graph::depthFirstSearch(int startId, vector<Vertex> &visitedOrder) {
    if (hasVertex(startId)) {
        map<int, bool> visited;

        for (auto &vertex : vertices) {
            visited[vertex.first] = false;
        }

        DFSVisit(startId, visited, visitedOrder);
    }
}


void Graph::DFSVisit(int startId, map<int, bool> &visited, vector<Vertex> &visitedOrder) {
    visited[startId] = true;
    visitedOrder.push_back(vertices[startId]);

    for (auto &neighbor : adjacencyList[startId]) {
        if (!visited[neighbor]) {
            DFSVisit(neighbor, visited, visitedOrder);
        }
    }
}


void Graph::printAdjacencyMatrix() {
    std::map<int, int> vertexIdToIndex;
    std::vector<int> indexToVertexId;
    int index = ONE;
    for (auto& vertex : vertices) {
        vertexIdToIndex[vertex.first] = index;
        indexToVertexId.push_back(vertex.first);
        ++index;
    }

    int size = vertices.size();

    vector<vector<int>> matrix(size + ONE, vector<int>(size + ONE, ZERO));

    for (auto& vertex : vertices) {
        int i = vertexIdToIndex[vertex.first];
        for (int vertexId : adjacencyList[vertex.first]) {
            int j = vertexIdToIndex[vertexId];

            matrix[i][j] = ONE;
            matrix[j][i] = ONE;
        }
    }

    cout << setw(GRAPH_COLUMN_WIDTH) << GRAPH_SPACE;
    for (int i = ONE; i <= size; ++i) {
        cout << setw(GRAPH_COLUMN_WIDTH) << indexToVertexId[i-ONE];
    }
    cout << endl;

    for (int i = ONE; i <= size; ++i) {
        cout << setw(GRAPH_COLUMN_WIDTH) << indexToVertexId[i-ONE];
        for (int j = ONE; j <= size; ++j) {
            cout << setw(GRAPH_COLUMN_WIDTH) << matrix[i][j];
        }
        cout << endl;
    }
}

void Graph::printAdjacencyList() {
    int mapSize = adjacencyList.size();

    auto iterator = adjacencyList.begin();

    for(int i = ZERO; i < mapSize; ++i, ++iterator) {
        int vertexID = iterator->first;
        vector<int>& edges = iterator->second;

        cout << " Vertex " << vertexID << " is connected to: ";

        for(int j = ZERO; j < edges.size(); ++j) {
            cout << edges[j] << GRAPH_SPACE;
        }

        cout << endl;
    }
}

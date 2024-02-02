//
//  Graph.cpp
//  Algorithms
//
//  Created by Manish Patidar on 27/01/24.
//

#include "Graph.hpp"

#include <vector>
#include <queue>
#include <array>
#include <stack>
#include <algorithm>

// Function to print the adjacency list
void Graph::printAdjList() {
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << " has neighbors: ";
        for (const auto& neighbor : adjList[i]) {
            cout << neighbor.first << " ";
        }
        cout << endl;
    }
}

void Graph::addEdge(int u, int v) {
    adjList.at(u).emplace_back(pair<int, int>(v, 0));
    if (type == Graph::Undirected) {
        adjList.at(v).emplace_back(pair<int, int>(u, 0));
    }
}

void Graph::addCostEdge(int u, int v, int cost) {
    adjList.at(u).emplace_back(pair<int, int>(v, cost));
    if (type == Graph::Undirected) {
        adjList.at(v).emplace_back(pair<int, int>(u, cost));
    }
}

vector<int> Graph::BFS(int start) {
    vector<int> bfs;
    vector<bool> visited(adjList.size(), false);
    queue<int> q;
    
    // Start BFS from the given node
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        bfs.emplace_back(front);
        
        for (const auto &neighbor : adjList[front]) {
            if (!visited[neighbor.first]) {
                q.push(neighbor.first);
                visited[neighbor.first] = true;
            }
        }
    }
    return bfs;
}

//Uses Stack...to remember
vector<int> Graph::DFS(int startVertex) {
    vector<bool> visited(V, false);
    vector<int> dfs;
    stack<int> s;
    
    // Push the starting vertex onto the stack
    s.push(startVertex);
    
    while (!s.empty()) {
        // Pop a vertex from the stack
        int currentVertex = s.top();
        s.pop();
        
        // Process the current vertex if not visited
        if (!visited[currentVertex]) {
            visited[currentVertex] = true;
            dfs.emplace_back(currentVertex);
        }
        
        // Push unvisited adjacent vertices onto the stack
        for (const auto &neighbor : adjList[currentVertex]) {
            if (!visited[neighbor.first]) {
                s.push(neighbor.first);
            }
        }
    }
    return dfs;
}

vector<int> Graph::_DFS(int start) {
    vector<bool> visited(V, false);
    vector<int> dfs;
    _DFSHelper(start, visited, dfs);
    return dfs;
}

void Graph::_DFSHelper(int node, vector<bool>& visited, vector<int>& dfs) {
    visited[node] = true;
    dfs.emplace_back(node);

    for (const auto &v : adjList.at(node)) {
        if (!visited.at(v.first)) {
            _DFSHelper(v.first, visited, dfs);
        }
    }
}

//Prims-Algorithm--Greedy
pair<vector<int>, int> Graph::MST(int start) {
    vector<int> vertexTrace;
    vector<bool> visited(V, false);
    
    int cost = 0;
    visited[start] = true;
    vertexTrace.push_back(start);
    
    while (vertexTrace.size() < V) {
        int minCost = INT_MAX; // Initialize to a large value
        int nextVertex = -1;
        
        // Iterate through the vertices in the current trace
        for (int i : vertexTrace) {
            for (auto v : adjList[i]) {
                if (!visited[v.first] && v.second < minCost) {
                    // Update minimum cost and next vertex to visit
                    minCost = v.second;
                    nextVertex = v.first;
                }
            }
        }
        
        if (nextVertex != -1) {
            visited[nextVertex] = true;
            vertexTrace.push_back(nextVertex);
            cost += minCost;
        } else {
            // Handle the case where the graph is not connected
            break;
        }
    }
    return {vertexTrace, cost};
}

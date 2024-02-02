//
//  Graph.hpp
//  Algorithms
//
//  Created by Manish Patidar on 27/01/24.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <iostream>
#include <stack>

using namespace std;

class Graph {
    enum GraphType {
        Directed,
        Undirected
    };
    
    int V; // Number of vertices
    //Pair<vertex, cost>
    vector<vector<pair<int, int>>> adjList; // Adjacency list
    GraphType type = Undirected;
    
public:
    // Constructor
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }
    
    Graph(int vertices, GraphType graphType) : V(vertices), type(graphType) {
        adjList.resize(V);
    }
    
    // Function to add an edge to the graph
    void addEdge(int u, int v);
    
    void addCostEdge(int u, int v, int cost);
    
    // Function to print the adjacency list
    void printAdjList();
    
    //BFS
    vector<int> BFS(int start);
    
    //DFS-Iterative
    vector<int> DFS(int start);
    
    // DFS-Recursive
    vector<int> _DFS(int start);
    
    void _DFSHelper(int node, vector<bool>& visited, vector<int>& dfs);
    
    pair<vector<int>, int> MST(int start);
};

#endif /* Graph_hpp */

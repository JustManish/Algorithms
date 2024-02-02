//
//  main.cpp
//  Algorithms
//
//  Created by Manish Patidar on 21/01/24.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <array>
#include "sortings.hpp"
#include "queue"
#include "stack"

#include "Tree.hpp"
#include "Graph.hpp"

using namespace std;

int main()
{
    //Trees:------------------------>
    /**
     BinaryTree bt;
     bt.insertNode();
     bt.insertNode();
     bt.insertNode();
     bt.insertNode();
     bt.insertNode();
     TreeNode* tree = bt.insertNode();
     
     bt.traverse();
     cout<<endl;
     //bt.inorderTraversal(tree);
     bt.iterativeInorderTraversal();
     cout<<endl;
     bt.iterativePreorderTraversal();
     cout<<endl;
     bt.iterativePostorderTraversal();
     cout<<endl;
     int height = bt.height(tree);
     cout<<"Height of tree is: "<<height<<endl;
     cout<<"Is Tree Balanced: "<<bt.isBalanced(tree)<<endl;
     return 0;
     **/
    
    // Create a graph with 5 vertices
    Graph g(7);
    
    // Add edges
    g.addCostEdge(0, 1, 28);
    g.addCostEdge(0, 5, 10);
    g.addCostEdge(1, 2, 16);
    g.addCostEdge(1, 6, 14);
    g.addCostEdge(2, 3, 12);
    g.addCostEdge(3, 6, 18);
    g.addCostEdge(3, 4, 22);
    g.addCostEdge(4, 6, 24);
    g.addCostEdge(4, 5, 25);
    
    g.printAdjList();
    
    cout<<endl<<"BFS: ";
    
    for (const auto &v : g.BFS(0)) {
        cout<<" "<<v<<" ";
    }
    
    cout<<endl<<"DFS: ";
    
    for (const auto &v : g.DFS(0)) {
        cout<<" "<<v<<" ";
    }
    
    cout<<endl<<"DFS Recursive: ";
    
    for (const auto &v : g._DFS(0)) {
        cout<<" "<<v<<" ";
    }
    
    cout<<endl<<"MST: ";
    
    for (const auto &v : g.MST(0).first) {
        cout<<" "<<v<<" ";
    }
    cout<<endl<<g.MST(0).second<<endl;
}

//
//  Tree.cpp
//  Algorithms
//
//  Created by Manish Patidar on 27/01/24.
//

#include "Tree.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <array>
#include "sortings.hpp"
#include "queue"
#include "stack"

using namespace std;

//TODO: Make it more efficient...
bool BinaryTree::isBalanced(TreeNode *root) {
    if (root == nullptr) return false;
    return abs(height(root->leftChild) - height(root->rightChild)) <= 1;
}

int BinaryTree::search(int key) {
    return -1;
}

bool BinaryTree::isBST() {
    return false;
}

TreeNode* BinaryTree::constructFromInAndPreorder(int inorder[], int preorder[]) {
    return  NULL;
}

int BinaryTree::height(TreeNode* root) {
    if (root == nullptr) return 0;
    
    int lstHeight = height(root->leftChild);
    int rstHeight = height(root->rightChild);
    
    return 1 + max(lstHeight, rstHeight);
}

TreeNode* BinaryTree::convertToBST() {
    return nullptr;
}

void BinaryTree::iterativePostorderTraversal() {
    stack<TreeNode*> stack1, stack2;
    stack1.push(rootNode);
    
    while (!stack1.empty()) {
        TreeNode* top = stack1.top();
        stack1.pop();
        stack2.push(top);
        if (top->leftChild != nullptr) {
            stack1.push(top->leftChild);
        }
        
        if (top->rightChild != nullptr) {
            stack1.push(top->rightChild);
        }
    }
    
    while (!stack2.empty()) {
        cout<<" "<<stack2.top()->data<<" ";
        stack2.pop();
    }
}

void BinaryTree::iterativePreorderTraversal() {
    stack<TreeNode*> stack;
    stack.push(rootNode);
    
    while (!stack.empty()) {
        TreeNode* top = stack.top();
        stack.pop();
        
        cout<<" "<<top->data<<" ";
        
        if (top->rightChild != nullptr) {
            stack.push(top->rightChild);
        }
        
        if (top->leftChild != nullptr) {
            stack.push(top->leftChild);
        }
    }
}

void BinaryTree::iterativeInorderTraversal() {
    stack<TreeNode*> stack;
    stack.push(rootNode);
    
    while (!stack.empty()) {
        TreeNode* topNode = stack.top();
        while (topNode != nullptr) {
            stack.push(topNode->leftChild);
            topNode = topNode->leftChild;
        }
        
        stack.pop();
        
        if (!stack.empty()) {
            topNode = stack.top();
            cout << " " << topNode->data;
            stack.pop(); // remove the current left subtree node
            stack.push(topNode->rightChild);
        }
    }
}

///InorderTraversal-Recurssive
void BinaryTree::inorderTraversal(TreeNode* tree) {
    if (tree != nullptr) {
        inorderTraversal(tree->leftChild);
        cout<<" "<<tree->data<<" ";
        inorderTraversal(tree->rightChild);
    }
}

///Level Order Traversal
void BinaryTree::traverse() {
    queue<TreeNode*> queue;
    queue.push(rootNode);
    
    while (!queue.empty()) {
        TreeNode* currentNode = queue.front();
        queue.pop();
        cout<<" "<<currentNode->data;
        
        if (currentNode->leftChild != nullptr) {
            queue.push(currentNode->leftChild);
        }
        
        if (currentNode->rightChild != nullptr) {
            queue.push(currentNode->rightChild);
        }
    }
}

TreeNode* BinaryTree::insertNode() {
    ///LevelOrder Insertion
    ///Asymptotic Analysis: O(n)
    TreeNode* newNode = TreeNode::createNode();
    cout<<"Please Enter Info in the node: ";
    cin>>newNode->data;
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;
    if (rootNode == nullptr) {
        rootNode = newNode;
    } else {
        queue<TreeNode*> queue;
        queue.push(rootNode);
        
        while (!queue.empty()) {
            TreeNode* currentNode = queue.front();
            queue.pop();
            
            if (currentNode->leftChild != nullptr) {
                queue.push(currentNode->leftChild);
            } else {
                currentNode->leftChild = newNode;
                return rootNode;
            }
            
            if (currentNode->rightChild != nullptr) {
                queue.push(currentNode->rightChild);
            } else {
                currentNode->rightChild = newNode;
                return rootNode;
            }
        }
    }
    return rootNode;
}

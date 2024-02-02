//
//  Tree.hpp
//  Algorithms
//
//  Created by Manish Patidar on 27/01/24.
//

#ifndef Tree_hpp
#define Tree_hpp

#include "iostream"

using namespace std;

struct TreeNode {
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    
    static TreeNode* createNode() {
        TreeNode* newNode = new TreeNode();
        return newNode;
    }
};

class BinaryTree {
    TreeNode* rootNode = nullptr;
    
public:
    TreeNode* insertNode();
    
    void traverse();
    
    void inorderTraversal(TreeNode* tree);
    
    void iterativeInorderTraversal();
    
    void iterativePreorderTraversal();
    
    void iterativePostorderTraversal();
    
    TreeNode* convertToBST();
    
    int height(TreeNode* root);
    
    bool isBST();
    
    int search(int key);
    
    TreeNode* constructFromInAndPreorder(int inorder[], int preorder[]);
    
    bool isBalanced(TreeNode* root);
};

#endif /* Tree_hpp */

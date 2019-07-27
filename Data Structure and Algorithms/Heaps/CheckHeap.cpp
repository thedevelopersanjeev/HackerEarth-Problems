// check if given binary tree is a heap or not
// 1. Binary Tree must be Complete Binary Tree
// 2. Each node must be smaller/greater than its left and right child
#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
} TreeNode;

TreeNode* createNewNode(int data){
    TreeNode* temp = new TreeNode;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Count number of nodes in a binary tree
int countNodes(TreeNode* root){
    if(root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// function to check if the given tree is complete tree
bool isCompleteTree(TreeNode* root, int index, int nodesCount){
    // empty tree is always complete
    if(root == NULL)
        return true;
    // index of current node is greater than nodes count
    // means, tree is not complete
    if(index >= nodesCount)
        return false;
    // recursive call on left and right subtree
    return isCompleteTree(root->left, 2 * index + 1, nodesCount) && isCompleteTree(root->right, 2 * index + 2, nodesCount);
}

// checks heap property in the tree
bool isHeapUtil(TreeNode* root){
    if(root->left == NULL && root->right == NULL)
        return true;
    if(root->right == NULL)
        return root->data >= root->left->data;
    else{
        if(root->data >= root->left->data && root->data >= root->right->data)
            return isHeapUtil(root->left) && isHeapUtil(root->right);
        else
            return false;
    }
}

// function to check heap property of a binary tree
bool isHeap(TreeNode* root){
    int index = 0;
    int count = countNodes(root);
    return isCompleteTree(root, index, count) && isHeapUtil(root);
}

int main(){
    TreeNode* root = createNewNode(10);
    root->left = createNewNode(9);
    root->right = createNewNode(8);
    root->left->left = createNewNode(7); 
    root->left->right = createNewNode(6); 
    root->right->left = createNewNode(5); 
    root->right->right = createNewNode(4); 
    root->left->left->left = createNewNode(3); 
    root->left->left->right = createNewNode(2); 
    root->left->right->left = createNewNode(1); 
    if(isHeap(root))
        cout <<"Given tree is a Heap\n";
    else   
        cout <<"Given tree is not a Heap\n";
    return 0;
}
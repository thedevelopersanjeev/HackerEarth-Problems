// sum all the numbers formed by root to leaf traversal in a binary tree
#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;
} Node;

Node* createNewNode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// do a preorder traversal over the tree and maintain current sum in val
int treePathSumUtil(Node* root, int val){
    // empty node, return sum as 0
    if(root == NULL)
        return 0;
    // update val
    val = (val * 10) + root->data;
    // check if current node is leaf node
    if(root->left == NULL && root->right == NULL)
        // return current sum
        return val;
    // recursive call on left and right subtree
    return treePathSumUtil(root->left, val) + treePathSumUtil(root->right, val);
}

// function to return sum of all number formed by root to leaf traversal
int treePathSum(Node* root){
    return treePathSumUtil(root, 0);
}

int main(){
    Node* root = createNewNode(1);
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(6);
    root->right->right = createNewNode(7);
    cout <<treePathSum(root) <<"\n";
    return 0;
}
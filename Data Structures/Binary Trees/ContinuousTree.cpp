// Continuous Tree:  if in each root to leaf path, absolute difference between keys of two adjacent is 1
// Given a Binary Tree, check if it is continuous tree or not?
#include<bits/stdc++.h>
using namespace std;

// represents a single node in the tree
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

// creates a new node and return the pointer to it
struct Node* createNewNode(int data){
    struct Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// given a binary tree having root as root
// returns true if it is continuous tree
// else returns false
bool checkContinuous(struct Node* root){
    // empty tree, return true
    if(root == NULL)
        return true;
    // check if it is leaf node or a single node
    if(root->left == NULL && root->right == NULL)
        return true;
    // if left subtree is empty
    if(root->left == NULL){
        // check right subtree
        return (
            // absolute difference check
            abs(root->data - root->right->data) == 1 &&
            // and recursive check on right subtree
            checkContinuous(root->right)
        );
    }
    // if right subtree is empty
    if(root->right == NULL){
        // check only left subtree
        return (
            // absolute difference check
            abs(root->data - root->left->data) == 1 && 
            // recursive check on left subtree
            checkContinuous(root->left)
        );
    }
    // if none of them is empty, check both of them
    return (
        // absolute difference check on left data
        abs(root->data - root->left->data) == 1 && 
        // absolute difference check on right data
        abs(root->data - root->right->data) == 1 && 
        // recursive call on left subtree
        checkContinuous(root->left) && 
        // recursive call on right subtree
        checkContinuous(root->right)
    );
}

int main(){
    struct Node* root = createNewNode(3);
    root->left = createNewNode(2);
    root->right = createNewNode(4);
    root->left->left = createNewNode(1);
    root->left->right = createNewNode(3);
    root->right->left = createNewNode(5);
    cout <<checkContinuous(root) <<"\n";
    root->data = 42;
    cout <<checkContinuous(root) <<"\n";
    return 0;
}
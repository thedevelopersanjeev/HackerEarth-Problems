// Searching and Insertion in BST
#include<bits/stdc++.h>
using namespace std;

// Represents a single node in BST
typedef struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
} TreeNode;

// function to create a new node and return it
TreeNode* createNewNode(int data){
    TreeNode* temp = new TreeNode;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// function to search for a node in BST
TreeNode* searchNode(TreeNode* root, int data){
    // check if the current node is the same we are searching for
    if(root->data == data || root == NULL)
        return root;
    // recursive call on left or right subtree based on the property of BST
    if(root->data > data){
        // our answer is in left subtree
        return searchNode(root->left, data);
    }
    else{
        // our answer is in right subtree
        return searchNode(root->right, data);
    }
}

// function to insert new node into the tree
TreeNode* insertNode(TreeNode* root, int data){
    if(root == NULL){
        // empty tree
        // create new node and return it
        return createNewNode(data);
    }
    if(root->data < data){
        // new data is greater than the root data
        // so, it must be inserted in right subtree
        root->right = insertNode(root->right, data);
    }
    else if(root->data > data){
        // new data is less than or equal to root data
        // so, it must be inserted in left subtree
        root->left = insertNode(root->left, data);
    }
    return root;
}

void printInorder(TreeNode* root){
    if(root != NULL){
        printInorder(root->left);
        cout <<root->data <<" ";
        printInorder(root->right);
    }
}

int main(){
    TreeNode* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30); 
    insertNode(root, 20); 
    insertNode(root, 40); 
    insertNode(root, 70); 
    insertNode(root, 60); 
    insertNode(root, 80);
    printInorder(root);
    cout <<"\n";
    return 0;
}
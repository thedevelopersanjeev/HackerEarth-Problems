// convert a binary tree to binary search tree
// structure of the tree should be the same
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

void printInorderTraversal(TreeNode* root){
    if(root == NULL)
        return;
    printInorderTraversal(root->left);
    cout <<root->data <<" ";
    printInorderTraversal(root->right);
}

void storeInorderTraversal(TreeNode* root, vector<int> &temp){
    if(root == NULL)
        return;
    storeInorderTraversal(root->left, temp);
    temp.push_back(root->data);
    storeInorderTraversal(root->right, temp);
}

// index : current index in the temp array
void replaceNodesInTree(TreeNode* root, vector<int> &temp, int* index){
    if(root == NULL)
        return;
    replaceNodesInTree(root->left, temp, index);
    root->data = temp[*index];
    (*index)++;
    replaceNodesInTree(root->right, temp, index);
}

void convertToBST(TreeNode* root){
    // 1. Traverse over the tree in inorder fashion.
    // 2. Store it in an array
    // 3. Sort the array
    // 4. Traverse over the tree again
    // 5. Replace nodes value by values from the array
    // temporary array to store inorder traversal
    vector<int> temp;
    storeInorderTraversal(root, temp);
    // sort the array
    sort(begin(temp), end(temp));
    int i = 0;
    replaceNodesInTree(root, temp, &i);
}

int main(){
    TreeNode* root = createNewNode(10);
    root->left = createNewNode(30);
    root->right = createNewNode(15);
    root->left->left = createNewNode(20);
    root->right->right = createNewNode(5);
    cout <<"Inorder Traversal Before Converting to BST : \n";
    printInorderTraversal(root);
    convertToBST(root);
    cout <<"\nInorder Traversal After Converting to BST : \n";
    printInorderTraversal(root);
    cout <<"\n";
    return 0;
}
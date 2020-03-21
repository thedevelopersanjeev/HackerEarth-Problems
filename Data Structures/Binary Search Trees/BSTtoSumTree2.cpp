// Convert a BST to a Binary Tree such that sum of all greater keys is added to every key
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

// A utility which recursively iterates over the tree 
// in reverse inorder fashion and collects the sum
// and update the value of node simultaneously
void transformTreeUtil(TreeNode* root, int* sum){
    // Base case
    if(root == NULL)
        return;
    // recursive call on right subtree
    transformTreeUtil(root->right, sum);
    // update value of sum
    *sum += root->data;
    // update current node's value
    root->data = *sum;
    // recursive call on left subtree
    transformTreeUtil(root->left, sum);
}

void transformTree(TreeNode* root){
    int sum = 0;
    transformTreeUtil(root, &sum);
}

int main(){
    TreeNode* root = createNewNode(5);
    root->left = createNewNode(2);
    root->right = createNewNode(13);
    cout <<"Inorder before : \n";
    printInorderTraversal(root);
    cout <<"\n";
    transformTree(root);
    cout <<"Inorder after : \n";
    printInorderTraversal(root);
    cout <<"\n";
    return 0;
}
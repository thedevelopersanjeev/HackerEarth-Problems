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

// Utility method to recursively iterate over the tree in 
// Inorder fashion and collect sum and update value of each node
void transformTreeUtil(TreeNode* root, int* sum){
    // base case
    if(root == NULL)
        return;
    // recursive call on left subtree
    transformTreeUtil(root->left, sum);
    // update value of sum
    *sum += root->data;
    // update current node's data
    root->data = *sum;
    // recursive call on right subtree
    transformTreeUtil(root->right, sum);
}

void transformTree(TreeNode* root){
    int sum = 0;
    transformTreeUtil(root, &sum);
}

int main(){
    TreeNode* root = createNewNode(9);
    root->left = createNewNode(6);
    root->right = createNewNode(15);
    root->left->left = createNewNode(3);
    root->right->right = createNewNode(21);
    cout <<"Inorder Traversal Before : \n";
    printInorderTraversal(root);
    cout <<"\n";
    transformTree(root);
    cout <<"Inorder Traversal After : \n";
    printInorderTraversal(root);
    cout <<"\n";
    return 0;
}
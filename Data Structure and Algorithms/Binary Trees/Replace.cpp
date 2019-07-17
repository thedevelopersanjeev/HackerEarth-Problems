// Replace each node in binary tree with the sum of its inorder predecessor and successor
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

void inorderTraversal(TreeNode* root, vector<int> &arr){
    if(root == NULL)
        return;
    inorderTraversal(root->left, arr);
    arr.push_back(root->data);
    inorderTraversal(root->right, arr);
}

// replace every node in tree by its inorder predecessor and successor
void replaceNode(TreeNode* root, vector<int> &arr, int* i){
    if(root == NULL)
        return;
    // recursive call on left subtree
    replaceNode(root->left, arr, i);
    // set current node data
    root->data = arr[*i - 1] + arr[*i + 1];
    // move i to next arr element
    (*i)++;
    // recursive call on right subtree
    replaceNode(root->right, arr, i);
}

void printInorder(TreeNode* root){
    if(root == NULL)
        return;
    printInorder(root->left);
    cout <<root->data <<" ";
    printInorder(root->right);
}

int main(){
    TreeNode* root = createNewNode(1);
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(6);
    root->right->right = createNewNode(7);
    cout <<"Inorder Before Replacement: \n";
    printInorder(root);
    cout <<"\n";
    // array to store inorder traversal of the tree
    vector<int> arr;
    // add 0 in beginning
    arr.push_back(0);
    inorderTraversal(root, arr);
    // add 0 in the end
    arr.push_back(0);
    // replace every node in inorder traversal by arr[i-1] + arr[i+1]
    // starting with i = 1
    int i = 1;
    replaceNode(root, arr, &i);
    cout <<"Inorder After Replacement: \n";
    printInorder(root);
    cout <<"\n";
    return 0;
}
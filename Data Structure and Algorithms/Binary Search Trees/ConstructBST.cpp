// Construct BST from Level Order Traversal
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

TreeNode* constructBSTUtil(TreeNode* root, int ele){
    if(root == NULL)
        return createNewNode(ele);
    // new element is less than current node
    // this it will go in left subtree
    if(ele <= root->data)
        root->left = constructBSTUtil(root->left, ele);
    else
        root->right = constructBSTUtil(root->right, ele);
    return root;
}

TreeNode* constructBST(vector<int> &arr){
    if(arr.empty())
        return NULL;
    TreeNode* root = NULL;
    for(auto ele : arr)
        root = constructBSTUtil(root, ele);
    return root;
}

int main(){
    vector<int> arr = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    TreeNode* root = constructBST(arr);
    cout <<"Inorder Traversal of Constructed BST : \n";
    printInorderTraversal(root);
    cout <<"\n";
    return 0;
}
// Given a sorted array, convert it to height balanced BST
// Height Balanced BST
// |height(LST) - height(RST)| <= 1

#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
} TreeNode;

TreeNode* sortedArrayToBSTUtil(const vector<int> &A, int start, int end){
    // leaf node
    if(start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    // middle element will be root
    TreeNode* root = new TreeNode;
    root->val = A[mid];
    // left subtree will be formed by elements in left subarray
    root->left = sortedArrayToBSTUtil(A, start, mid - 1);
    // right subtree will be formed by elements in right subarray
    root->right = sortedArrayToBSTUtil(A, mid + 1, end);
    // finally return the created subtree
    return root;
}

TreeNode* sortedArrayToBST(const vector<int> &A){
    return sortedArrayToBSTUtil(A, 0, A.size()-1);
}

void inorderTraversal(TreeNode* root){
    if(root == NULL)
        return;
    inorderTraversal(root->left);
    cout <<root->val <<" ";
    inorderTraversal(root->right);
}

int main(){
    vector<int> arr = {1, 2, 4, 5, 8};
    TreeNode* root = sortedArrayToBST(arr);
    inorderTraversal(root);
    cout <<"\n";
    return 0;
}
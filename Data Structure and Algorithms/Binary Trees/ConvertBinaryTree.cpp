// Given an arbitrary binary tree, convert it
// to a binary tree which satisfies Children Sum Property
// You can't decrement the value of a node
// You can increment the value of a node

#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
} TreeNode;

TreeNode* createNewNode(int data){
    TreeNode* temp = new TreeNode;
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// increment the root's subtree by diff
void increment(TreeNode* root, int diff){
    if(root->left != NULL){
        root->left->val += diff;
        increment(root->left, diff);
    }
    else if(root->right != NULL){
        root->right->val += diff;
        increment(root->right, diff);
    }
}

TreeNode* solve(TreeNode* root){
    int left = 0;
    int right = 0;
    int diff;
    // check for empty node or single node
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return root;
    TreeNode* leftNode = solve(root->left);
    TreeNode* rightNode = solve(root->right);
    if(root->left != NULL)
        left = root->left->val;
    if(root->right != NULL)
        right = root->right->val;
    // get the difference
    diff = left + right - root->val;
    if(diff > 0)
        // current node's data can be incremented
        root->val += diff;
    if(diff < 0)
        // tricky step
        // as we are not allowed to decrement any node's value
        // so, we need to increment the children node's value
        // -diff to make diff positive
        increment(root, -diff);
    TreeNode* ans = new TreeNode;
    ans->val = root->val;
    ans->left = leftNode;
    ans->right = rightNode;
    return ans;
}

int main(){
    
    return 0;
}
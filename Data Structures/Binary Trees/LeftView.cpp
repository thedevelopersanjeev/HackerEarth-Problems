// print left view of a binary tree

#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
} TreeNode;

void leftView(TreeNode* root, int level, int* maximum_level, vector<int> &ans){
    // base case
    if(root == NULL)
        return;
    if(*maximum_level < level){
        // 1st node of this level
        ans.push_back(root->val);
        *maximum_level = level;
    }
    // recursive call on left subtree
    leftView(root->left, level + 1, maximum_level, ans);
    // recursive call on right subtree
    leftView(root->right, level + 1, maximum_level, ans);
}

vector<int> solve(TreeNode* A){
    // max level of the tree
    int maximum_level = 0;
    vector<int> ans;
    leftView(A, 1, &maximum_level, ans);
    return ans;
}

int main(){

    return 0;
}
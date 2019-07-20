/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

const int mod = 1003;

int treePathSumUtil(TreeNode* root, int temp){
    // empty node, return sum as 0
    if(root == NULL)
        return 0;
    // update val
    temp = ((temp * 10) + root->val) % mod;
    // check if current node is leaf node
    if(root->left == NULL && root->right == NULL)
        // return current sum
        return temp % mod;
    // recursive call on left and right subtree
    return (treePathSumUtil(root->left, temp) + treePathSumUtil(root->right, temp)) % mod;
}
 
int Solution::sumNumbers(TreeNode* A) {
    return treePathSumUtil(A, 0) % mod;
}
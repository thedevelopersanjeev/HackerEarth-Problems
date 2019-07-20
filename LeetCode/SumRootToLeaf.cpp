/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int treePathSumUtil(TreeNode* root, int temp){
    // empty node, return sum as 0
    if(root == NULL)
        return 0;
    // update val
    temp = ((temp * 10) + root->val);
    // check if current node is leaf node
    if(root->left == NULL && root->right == NULL)
        // return current sum
        return temp;
    // recursive call on left and right subtree
    return (treePathSumUtil(root->left, temp) + treePathSumUtil(root->right, temp));
}
    int sumNumbers(TreeNode* root) {
            return treePathSumUtil(root, 0);

    }
};
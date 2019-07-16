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
    
    int findHeight(TreeNode* root){
    
    if(root == NULL)
        return 0;
    
    if(root->left == NULL)
        return 1 + findHeight(root->right);
    
    if(root->right == NULL)
        return 1 + findHeight(root->left);
    
    int x = findHeight(root->left);
    int y = findHeight(root->right);
    
    if(x > y)
        return 1 + x;
    else
        return 1 + y;
    
}
    
    bool isBalanced(TreeNode* A) {
        if(A == NULL)
        return 1;

    int x = findHeight(A->left);
    int y = findHeight(A->right);
    
    if(abs(x - y) <= 1 && isBalanced(A->left) && isBalanced(A->right))
        return true;
    else 
        return false;
    }
};
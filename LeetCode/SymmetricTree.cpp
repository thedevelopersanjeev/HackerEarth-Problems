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
    
    bool isMirror(TreeNode* A, TreeNode* B){
    // if both nodes are null, return true
    if(A == NULL && B == NULL)
        return true;
    // for subtree A and B to be mirror of each other
    // 1. their data should be same
    // 2. neither of them should be NULL
    // 3. left->left should be mirror image of right->right
    // 4. left->right should be mirror image of right->left
    if(A != NULL && B != NULL && A->val == B->val)
        return isMirror(A->left, B->right) && isMirror(A->right, B->left);
    // none of the above conditions is true
    return false;
}
    
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
    
    
};
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
    
    void bstToGstUtil(TreeNode* root, int* sum){
        if(root == NULL)
            return;
        bstToGstUtil(root->right, sum);
        (*sum) += root->val;
        root->val = (*sum);
        bstToGstUtil(root->left, sum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        bstToGstUtil(root, &sum);
        return root;
    }
};
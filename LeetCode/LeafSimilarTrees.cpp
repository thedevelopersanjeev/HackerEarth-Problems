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
    
    // this function will traverse over the tree inorder fashion
    // and only push the leaf nodes into the temp array
    void f(TreeNode* root, vector<int> &temp){
        if(root == NULL)
            return;
        f(root->left, temp);
        if(root->left == NULL && root->right == NULL)
            temp.push_back(root->val);
        f(root->right, temp);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        f(root1, a);
        f(root2, b);
        return a == b;
    }
};
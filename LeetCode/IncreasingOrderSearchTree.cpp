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
    void f(TreeNode* root, vector<int> &temp){
        if(root == NULL)
            return;
        f(root->left, temp);
        temp.push_back(root->val);
        f(root->right, temp);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> temp;
        f(root, temp);
        TreeNode* ans = new TreeNode(temp[0]);
        TreeNode* x = ans;
        for(int i = 1; i < temp.size(); i++){
            ans->right = new TreeNode(temp[i]);
            ans = ans->right;
        }
        return x;
    }
};
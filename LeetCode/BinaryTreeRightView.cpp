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
    
            void rightView(TreeNode* root, int level, int* maximum_level, vector<int> &ans){
            // base case
            if(root == NULL)
                return;
            if(*maximum_level < level){
                // 1st node of this level
                ans.push_back(root->val);
                *maximum_level = level;
            }
            // recursive call on right subtree
            rightView(root->right, level + 1, maximum_level, ans);
            // recursive call on left subtree
            rightView(root->left, level + 1, maximum_level, ans);
        }
    
    vector<int> rightSideView(TreeNode* A) {
         // max level of the tree
        int maximum_level = 0;
        vector<int> ans;
        rightView(A, 1, &maximum_level, ans);
        return ans;
    }
};
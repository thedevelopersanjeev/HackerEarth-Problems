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

	int ans;

    int maxPathSum(TreeNode* root) {
		ans = INT_MIN;
		pathSum(root);
		return ans;        
    }

    int pathSum(TreeNode* node){
    	if(node == NULL) {
    		return 0;
    	}
    	int left = max(0, pathSum(node->left));
    	int right = max(0, pathSum(node->right));
    	ans = max(ans, left + right + node->val);
    	return max(left, right) + node->val;
    }

};
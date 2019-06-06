/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    vector<int> ans;
    s.push(A);
    while(!s.empty()){
        A = s.top();
        ans.push_back(A->val);
        s.pop();
        if(A->right)
            s.push(A->right);
        if(A->left)
            s.push(A->left);
    }
    return ans;
}

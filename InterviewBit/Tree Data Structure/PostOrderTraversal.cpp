/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    vector<int> ans;
    while(1){
        while(A != NULL){
            s.push(A);
            s.push(A);
            A = A->left;
        }
        if(s.empty())
            return ans;
        A = s.top();
        s.pop();
        if(!s.empty() && s.top() == A)
            A = A->right;
        else{
            ans.push_back(A->val);
            A = NULL;
        }
    }
}

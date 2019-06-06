/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    bool done = false;
    vector<int> ans;
    while(!done){
        if(A != NULL){
            s.push(A);
            A = A->left;
        }
        else{
            if(!s.empty()){
                A = s.top();
                s.pop();
                ans.push_back(A->val);
                A = A->right;
            }
            else
                done = true;
        }
    }
    return ans;
}

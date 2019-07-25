/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void convertBSTtoList(TreeNode* A, vector<int> &arr){
    if(A == NULL)
        return;
    convertBSTtoList(A->left, arr);
    arr.push_back(A->val);
    convertBSTtoList(A->right, arr);
}
 
vector<int> Solution::solve(TreeNode* A, TreeNode* B) {

    vector<int> l1;
    vector<int> l2;
    convertBSTtoList(A, l1);
    convertBSTtoList(B, l2);
    vector<int> ans(l1.size() + l2.size());
    merge(l1.begin(), l1.end(), l2.begin(), l2.end(), ans.begin());
    return ans;
    
}
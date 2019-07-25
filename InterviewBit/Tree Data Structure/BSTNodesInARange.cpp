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
 
int Solution::solve(TreeNode* A, int B, int C) {

    vector<int> temp;
    convertBSTtoList(A, temp);
    return upper_bound(temp.begin(), temp.end(), C) - lower_bound(temp.begin(), temp.end(), B);
    
}
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int findMax(vector<int> &arr, int start, int end){
    int ans = start;
    int ele = arr[start];
    for(int i = start; i <= end; i++){
        if(ele < arr[i]){
            ele = arr[i];
            ans = i;
        }
    }
    return ans;
}
 
TreeNode* f(vector<int> &arr, int start, int end){
    if(start > end)
        return NULL;
    int i = findMax(arr, start, end);
    // max element is at root
    TreeNode* root = new TreeNode(arr[i]);
    root->left = f(arr, start, i-1);
    root->right = f(arr, i+1, end);
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> &A) {
    return f(A, 0, A.size()-1);
}
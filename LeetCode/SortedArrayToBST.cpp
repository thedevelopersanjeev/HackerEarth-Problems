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
    
    TreeNode* sortedArrayToBSTUtil(const vector<int> &A, int start, int end){
    // leaf node
    if(start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    // middle element will be root
    TreeNode* root = new TreeNode(A[mid]);
    // root->val = A[mid];
    // left subtree will be formed by elements in left subarray
    root->left = sortedArrayToBSTUtil(A, start, mid - 1);
    // right subtree will be formed by elements in right subarray
    root->right = sortedArrayToBSTUtil(A, mid + 1, end);
    // finally return the created subtree
    return root;
}
    
    TreeNode* sortedArrayToBST(vector<int>& A) {
        return sortedArrayToBSTUtil(A, 0, A.size()-1);
    }
};
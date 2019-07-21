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
    
    void storeInorder(TreeNode* A, vector<int> &arr){
    if(A == NULL)
        return;
    storeInorder(A->left, arr);
    arr.push_back(A->val);
    storeInorder(A->right, arr);
    }
    
    int kthSmallest(TreeNode* A, int B) {
            vector<int> temp;
    storeInorder(A, temp);
    return temp[B-1];
    }
};
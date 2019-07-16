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
    
     TreeNode* utilityFunction(vector<int> &A, vector<int> &B, int i, int j, int *p, unordered_map<int, int> &mp){
    // Base Case
    if(i > j)
        return NULL;
    // Get current node from post order array or current root of the tree
    int curr = B[*p];
    TreeNode* node = new TreeNode(curr);
    (*p)--;
    // check if this node has no children
    // it can be checked by comparing the starting and ending indexes in inorder array
    if(i == j)
        // this node has no left subtree and no right subtree
        return node;
    // find index of this node in inorder traversal
    int temp = mp[curr];
    // using this index, construct left and right subtree
    // by calling this function recursively
    // all elements on left of curr in inorder traversal are in left subtree
    // all elements on right of curr in inorder traversal are in right subtree
    node->right = utilityFunction(A, B, temp + 1, j, p, mp);
    node->left = utilityFunction(A, B, i, temp - 1, p, mp);
    // return the newly constructed node
    return node;
}
    
    TreeNode* buildTree(vector<int>& A, vector<int>& B) {
        // get number of nodes in the tree
    int n = A.size();
    // store indexes to access them in O(1) time
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
        mp[A[i]] = i;
    // last index in post order
    // last index in post order is always root node
    int index = n - 1;
    return utilityFunction(A, B, 0, n - 1, &index, mp);
    }
};
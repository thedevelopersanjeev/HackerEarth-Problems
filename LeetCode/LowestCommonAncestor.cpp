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
    
     
 

// find path from root node to A in Binary Tree
bool findPath(TreeNode* root, int A, vector<TreeNode*> &path){
    // empty tree
    if(root == NULL)
        return false;
    // add current node in path
    path.push_back(root);
    // reached destination node
    if(root->val == A)
        return true;
    // search for A in left or right subtree
    if((root->left != NULL && findPath(root->left, A, path)) || 
       (root->right != NULL && findPath(root->right, A, path)))
        return true;
    // not found
    // remove this root from path and return false
    path.pop_back();
    return false;
}

// find LCA(A, B) for Binary Tree having root as root
// and return it
TreeNode* findLCA(TreeNode* root, int A, int B){
    // array to store path from root to A
    vector<TreeNode*> pathA;
    // array to store path from root to B
    vector<TreeNode*> pathB;
    // no common node found
    // return -1
    if(!findPath(root, A, pathA) || !findPath(root, B, pathB))
        return NULL;
    int i = 0;
    // compare paths and return first unmatching node
    for(i = 0; i < pathA.size() && i < pathB.size(); i++)
        if(pathA[i] != pathB[i])
            // first unmatch found
            break;
    return pathA[i-1];
}

    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = findLCA(root, p->val, q->val);
        return ans;
    }
};
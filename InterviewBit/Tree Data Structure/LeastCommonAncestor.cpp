/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 

// find path from root node to A in Binary Tree
bool findPath(TreeNode* root, int A, vector<int> &path){
    // empty tree
    if(root == NULL)
        return false;
    // add current node in path
    path.push_back(root->val);
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
int findLCA(TreeNode* root, int A, int B){
    // array to store path from root to A
    vector<int> pathA;
    // array to store path from root to B
    vector<int> pathB;
    // no common node found
    // return -1
    if(!findPath(root, A, pathA) || !findPath(root, B, pathB))
        return -1;
    int i = 0;
    // compare paths and return first unmatching node
    for(i = 0; i < pathA.size() && i < pathB.size(); i++)
        if(pathA[i] != pathB[i])
            // first unmatch found
            break;
    return pathA[i-1];
}

 
int Solution::lca(TreeNode* A, int B, int C) {

    return findLCA(A, B, C);
    
}
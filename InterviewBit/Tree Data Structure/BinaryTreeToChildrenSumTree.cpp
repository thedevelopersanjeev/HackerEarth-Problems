/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int solveUtil(TreeNode* root){
    if(root == NULL)
        return 0;
    
    if(root->left == NULL && root->right == NULL)
        return root->val;
    
    int left = solveUtil(root->left);
    int right = solveUtil(root->right);
    
    int diff = root->val - (left + right);
    
    if(diff < 0){
        // we can add the diff into root's value to make it chiildren tree
        root->val += (-diff);
    }
    else if(diff > 0){
        // as, we are not allowed to subtract, so we need to add the diff into child nodes
        TreeNode* temp;
        if(root->left != NULL)
            temp = root->left;
        else
            temp = root->right;
        while(1){
            temp->val += diff;
            if(temp->left != NULL)
                temp = temp->left;
            else if(temp->right != NULL)
                temp = temp->right;
            else
                break;
        }
    }
    
    return root->val;
}
 
TreeNode* Solution::solve(TreeNode* A) {
    solveUtil(A);
    return A;
}
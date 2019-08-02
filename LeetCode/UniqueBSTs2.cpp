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
    /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
TreeNode* createNewNode(int data){
    TreeNode* temp = new TreeNode(data);
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
vector<TreeNode*> generateTree(int start, int end){
    vector<TreeNode*> ans;
    if(start > end){
        // Invalid range of numbers
        ans.push_back(NULL);
        return ans;
    }
    // iterate over start to end and take each case considering 
    // each node as root in that particular case
    for(int i = start; i <= end; i++){
        // construct left subtree
        // it will have nodes from start to i - 1
        vector<TreeNode*> left = generateTree(start, i - 1);
        // construct right subtree
        // it will have nodes from i + 1 to end
        vector<TreeNode*> right = generateTree(i + 1, end);
        // iterate over all left and right subtrees and attach them to ith node
        for(int j = 0; j < left.size(); j++){
            for(int k = 0; k < right.size(); k++){
                // create ith root
                TreeNode* root = createNewNode(i);
                // attach left subtree
                root->left = left[j];
                // attach right subtree
                root->right = right[k];
                // add this tree to final answer
                ans.push_back(root);
            }
        }
    }
    return ans;
}

 
vector<TreeNode*> generateTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A == 0)
        return vector<TreeNode*> {};
    return generateTree(1, A);
}

};
// construct all possible unique BSTs possible from keys [1, N]
#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
} TreeNode;

TreeNode* createNewNode(int data){
    TreeNode* temp = new TreeNode;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printInorderTraversal(TreeNode* root){
    if(root == NULL)
        return;
    printInorderTraversal(root->left);
    cout <<root->data <<" ";
    printInorderTraversal(root->right);
}

// create all possible BST possible with keys from start to end both inclusive
vector<TreeNode*> generateTrees(int start, int end){
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
        vector<TreeNode*> left = generateTrees(start, i - 1);
        // construct right subtree
        // it will have nodes from i + 1 to end
        vector<TreeNode*> right = generateTrees(i + 1, end);
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

void printPreorderTraversal(TreeNode* root){
    if(root == NULL)
        return;
    cout <<root->data <<" ";
    printPreorderTraversal(root->left);
    printPreorderTraversal(root->right);
}

int main(){
    vector<TreeNode*> ans = generateTrees(1, 10);
    // print preorder traversal of all generated trees
    cout <<"Preorder Traversal of All BSTs : \n";
    for(auto ele : ans){
        printPreorderTraversal(ele);
        cout <<"\n";
    }
    return 0;
}
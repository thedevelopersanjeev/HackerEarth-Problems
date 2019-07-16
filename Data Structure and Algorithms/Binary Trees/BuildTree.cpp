// Construct Binary Tree from Inorder and Postorder
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

TreeNode* createNewNode(int data){
    TreeNode* temp = new TreeNode;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// helper function to print Preorder Traversal of Binary Tree
void printPreorderTraversal(TreeNode* root){
    if(root == NULL)
        return;
    cout <<root->data <<" ";
    printPreorderTraversal(root->left);
    printPreorderTraversal(root->right);
}

// Helper Function to Build Binary Tree from Inorder and Postorder Traversal
// A : Inorder Traversal Array
// B : Postorder Traversal Array
// i : Starting Index of Inorder Traversal Array
// j : Ending Index of Inorder Traversal Array
// p : Index in Post Order
// mp: Inorder Traversal Array Indexes, Reduces Time Complexity by O(n)
struct TreeNode* utilityFunction(vector<int> &A, vector<int> &B, int i, int j, int *p, unordered_map<int, int> &mp){
    // Base Case
    if(i > j)
        return NULL;
    // Get current node from post order array or current root of the tree
    int curr = B[*p];
    TreeNode* node = createNewNode(curr);
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
    node->right = utilityFunction(A, B, temp + 1, j, p, mp);
    // all elements on right of curr in inorder traversal are in right subtree
    node->left = utilityFunction(A, B, i, temp - 1, p, mp);
    // return the newly constructed node
    return node;
}

// A : Inorder Traversal
// B : Postorder Traversal
TreeNode* buildTree(vector<int> &A, vector<int> &B){
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

int main(){
    vector<int> A = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> B = {8, 4, 5, 2, 6, 7, 3, 1};
    TreeNode* root = buildTree(A, B);
    printPreorderTraversal(root);
    cout <<"\n";
    return 0;
}
// Construct Binary Tree from Inorder and Preorder Traversal
#include<bits/stdc++.h>
using namespace std;

// Structure of single node in the tree
typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Create a new node and return the pointer to it
TreeNode* createNewNode(int data){
    TreeNode* temp = new TreeNode;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Utility method to build the tree
// A : Inorder Traversal
// B : Preorder Traversal
// i : starting index in Inorder Traversal
// j : ending index in Inorder Traversal
// mp: map of index of Inorder Traversal elements
TreeNode* utilityMethod(vector<int> &A, vector<int> &B, int i, int j, unordered_map<int, int> &mp){
    // starting index in Preorder traversal
    // It will always point to root in current subtree
    static int p = 0;
    // base condition
    if(i > j)
        return NULL;
    // Pick current node and increment pre index
    int curr = B[p++];
    // Create new node with current element
    TreeNode* currentNode = createNewNode(curr);
    // check if this node has no children
    if(i == j)
        // current node has no left and right child
        // so, return current node
        return currentNode;
    // construct left subtree
    // get index of current element from Inorder
    int temp = mp[curr];
    currentNode->left = utilityMethod(A, B, i, temp - 1, mp);
    currentNode->right = utilityMethod(A, B, temp + 1, j, mp);
    return currentNode;
}

// Prints post order of binary tree having root node as root
void printPostOrder(TreeNode* root){
    if(root == NULL)
        return;
    // recursive call on left
    printPostOrder(root->left);
    // recursive call on right
    printPostOrder(root->right);
    // print current node data
    cout <<root->data <<" ";
}

// Build tree and pointer to root node
// A : Inorder traversal over the tree
// B : Preorder traversal over the tree
TreeNode* buildTree(vector<int> &A, vector<int> &B){
    // number of nodes in the tree
    int n = A.size();
    // map to store index of Inorder traversal
    // makes searching time O(1)
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
        mp[A[i]] = i;
    return utilityMethod(A, B, 0, n - 1, mp);
}

int main(){
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {3, 2, 4, 1, 5};
    TreeNode* root = buildTree(B, A);
    printPostOrder(root);
    cout <<"\n";
    return 0;
}
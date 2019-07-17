// Find the Lowest Common Ancestor of 2 Nodes in a Binary Tree
// All Nodes are unique
// Node which is Parent of both A and B and farthest from the root node
// is called the LCA of A and B
// Approach One to solve this Problem
// 1. Store path from A to root
// 2. Store path from B to root
// 3. Compare two paths and find first matching node.
// Time Complexity : O(n)
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

// find path from root node to A in Binary Tree
bool findPath(TreeNode* root, int A, vector<int> &path){
    // empty tree
    if(root == NULL)
        return false;
    // add current node in path
    path.push_back(root->data);
    // reached destination node
    if(root->data == A)
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

int main(){
    TreeNode* root = createNewNode(1);
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(6);
    root->right->right = createNewNode(7);
    cout <<"LCA(2, 6) : " <<findLCA(root, 2, 6) <<"\n";
    cout <<"LCA(4, 5) : " <<findLCA(root, 4, 5) <<"\n";
    cout <<"LCA(4, 7) : " <<findLCA(root, 4, 7) <<"\n";
    cout <<"LCA(0, 7) : " <<findLCA(root, 0, 7) <<"\n";
    return 0;
}
// Find LCA of two nodes in a tree without using extra space
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

// find and return LCA of A and B
// flagA : flag to denote if A has been visited or not
// flagB : flag to denote if B has been visited or not
TreeNode* LCAUtil(TreeNode* root, int A, int B, bool &flagA, bool &flagB){
    // base case
    if(root == NULL)
        return NULL;
    // if current key is one of node A or B
    // this is the LCA of both A and B
    if(root->data == A){
        flagA = true;
        return root;
    }
    if(root->data == B){
        flagB = true;
        return root;
    }
    TreeNode* left = LCAUtil(root->left, A, B, flagA, flagB);
    TreeNode* right = LCAUtil(root->right, A, B, flagA, flagB);
    // One node is in left subtree
    // and other node is in right subtree
    // return curent node as this is the LCA
    if(left != NULL && right != NULL)
        return root;
    // either left or right will be the answer in other case
    if(left != NULL)
        return left;
    else
        return right;
}

// returns LCA(A, B) for Binary Tree having root as root
TreeNode* findLCA(TreeNode* root, int A, int B){
    // Node A not visited yet
    bool flagA = false;
    // Node B not visited yet
    bool flagB = false;
    TreeNode* lca = LCAUtil(root, A, B, flagA, flagB);
    if(flagA && flagB && lca != NULL)
        return lca;
    return NULL;
}

int main(){
    TreeNode* root = createNewNode(1);
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(6);
    root->right->right = createNewNode(7);
    TreeNode* ans = findLCA(root, 4, 7);
    if(ans != NULL)
        cout <<"LCA(4, 7) : " <<ans->data <<"\n";
    ans = findLCA(root, 3, 2);
    if(ans != NULL)
        cout <<"LCA(3, 2) : " <<ans->data <<"\n";
    ans = findLCA(root, 1, 4);
    if(ans != NULL)
        cout <<"LCA(1, 4) : " <<ans->data <<"\n";
    ans = findLCA(root, 0, 5);
    if(ans != NULL)
        cout <<"LCA(0, 5) : " <<ans->data <<"\n";
    return 0;
}
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

// Utility method to print path from root to leaf node
// len : length of path
// root: current node of tree
// path: current path traversed so far
void printPathUtil(TreeNode* root, vector<int> &path){
    if(root == NULL){
        path.clear();
        return;
    }
    path.push_back(root->data);
    if(root->left == NULL && root->right == NULL){
        for(auto ele : path)
            cout <<ele <<" ";
        cout <<"\n";
        path.clear();
    }
    else{
        printPathUtil(root->left, path);
        printPathUtil(root->right, path);
    }
}

void printPath(TreeNode* root){
    vector<int> path;
    printPathUtil(root, path);
}

int main(){
    TreeNode* root = createNewNode(10);
    root->left = createNewNode(8);
    root->right = createNewNode(2);
    root->left->left = createNewNode(3);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(2);
    printPath(root);
    return 0;
}
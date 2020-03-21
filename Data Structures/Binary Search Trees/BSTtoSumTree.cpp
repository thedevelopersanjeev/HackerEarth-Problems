// convert BST to Sum Tree
// Sum Tree : Each Node has value sum of all nodes greater than that node.
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

void printInorder(TreeNode* root){
    if(root == NULL)
        return;
    printInorder(root->left);
    cout <<root->data <<" ";
    printInorder(root->right);
}

// Traverse over the tree in reverse inorder traversal and collect sum 
// at each iteration, and keep updating the nodes...
void transformTreeUtil(TreeNode* root, int *sum){
    // Base case
    if(root == NULL)
        return;
    // recursive call on right subtree
    transformTreeUtil(root->right, sum);
    // update sum by collecting current node's data
    *sum += root->data;
    // update current node's data
    root->data = *sum - root->data;
    // recursive call on left subtree
    transformTreeUtil(root->left, sum);
}

// function to convert given tree into Sum Tree
void transformTree(TreeNode* root){
    // initial sum
    int sum = 0;
    // pass sum by reference as it is going to update in each recursive call
    transformTreeUtil(root, &sum);
}

int main(){
    TreeNode* root = createNewNode(11);
    root->left = createNewNode(7);
    root->right = createNewNode(15);
    root->left->left = createNewNode(3);
    root->left->right = createNewNode(10);
    root->right->left = createNewNode(12);
    root->right->right = createNewNode(20);
    cout <<"Inorder before transform : \n";
    printInorder(root);
    cout <<"\n";
    transformTree(root);
    cout <<"Inorder after transform : \n";
    printInorder(root);
    cout <<"\n";
    return 0;
}
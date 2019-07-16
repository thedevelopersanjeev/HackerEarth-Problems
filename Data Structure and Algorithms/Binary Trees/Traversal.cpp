// Different Types of Binary Tree Traversals
// * Inorder
// * Preorder
// * Postorder
#include<bits/stdc++.h>
using namespace std;

// Represents a single node in the tree
struct TreeNode{
    // data stored in the node
    int data;
    // left pointer to left subtree
    struct TreeNode* left;
    // right pointer to right subtree
    struct TreeNode* right;
};

// creates new node with given data and
// returns a pointer to it
TreeNode* createNewNode(int data){
    TreeNode* temp = new TreeNode;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// print inorder traversal of the tree having root as root
// Left Subtree -> Root -> Right Subtree
void inorderTraversal(TreeNode* root){
    // reached the end of tree
    if(root == NULL)
        return;
    // recursive call on left subtree
    inorderTraversal(root->left);
    // print current node
    cout <<root->data <<" ";
    // recursive call on right subtree
    inorderTraversal(root->right);
}

// print preorder traversal of the tree having root as root
// Root -> Left Subtree -> Right Subtree
void preorderTraversal(TreeNode* root){
    // reached the end of tree
    if(root == NULL)
        return;
    // print current node
    cout <<root->data <<" ";
    // recursive call on left subtree
    preorderTraversal(root->left);
    // recursive call on right subtree
    preorderTraversal(root->right);
}

// print post order traversal of the binary tree having root as root
// Left Subtree -> Right Subtree -> Root
void postorderTraversal(TreeNode* root){
    // reached end of tree
    if(root == NULL)
        return;
    // recursive call on left
    postorderTraversal(root->left);
    // recursive call on right
    postorderTraversal(root->right);
    // print current node
    cout <<root->data <<" ";
}

int main(){
    TreeNode* root = createNewNode(1);
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(6);
    root->right->right = createNewNode(7);
    cout <<"Inorder Traversal of the tree:\n";
    inorderTraversal(root);
    cout <<"\nPost order Traversal of the tree:\n";
    postorderTraversal(root);
    cout <<"\nPre order Traversal of the tree:\n";
    preorderTraversal(root);
    return 0;
}
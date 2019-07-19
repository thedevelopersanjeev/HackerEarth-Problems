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

TreeNode* findMinimum(TreeNode* root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

TreeNode* insertNode(TreeNode* root, int data){
    if(root == NULL)
        return createNewNode(data);
    else if(root->data < data)
        root->right = insertNode(root->right, data);
    else
        root->left = insertNode(root->left, data);
    return root;
}

TreeNode* deleteNode(TreeNode* root, int data){
    // empty tree
    if(root == NULL)
        return root;
    // node to be deleted is in right subtree
    // means, greater than current node value
    else if(root->data < data)
        root->right = deleteNode(root->right, data);
    // node to be deleted is in left subtree
    // means, smaller than current node value
    else if(root->data > data)
        root->left = deleteNode(root->left, data);
    // found the node to be deleted
    else{
        // Case 1 : No Child
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        // Case 2 : Single Child
        else if(root->left == NULL){
            TreeNode* temp = root;
            root = root->left;
            delete temp;
        }
        else if(root->right == NULL){
            TreeNode* temp = root;
            root = root->right;
            delete temp;
        }
        // Case 3 : 2 Children
        else{
            TreeNode* temp = findMinimum(root);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void printInorderTraversal(TreeNode* root){
    if(root == NULL)
        return;
    printInorderTraversal(root->left);
    cout <<root->data <<" ";
    printInorderTraversal(root->right);
}

int main(){
    TreeNode* root = NULL;
    root = insertNode(root, 5);
    root = insertNode(root, 10);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 1);
    root = insertNode(root, 11);
    cout <<"Inorder Before: \n";
    printInorderTraversal(root);
    cout <<"\nInorder After: \n";
    deleteNode(root, 5);
    printInorderTraversal(root);
    cout <<"\n";
    return 0;
}
// Given two BST's
// print the common nodes between them
#include<bits/stdc++.h>
using namespace std;

// structure of a single node in BST
typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
} TreeNode;

// create a new node and return pointer to it
TreeNode* createNewNode(int data){
    TreeNode* temp = new TreeNode;
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Print Inorder Traversal of BST
void inorderTraversal(TreeNode* root){
    if(root == NULL)
        return;
    inorderTraversal(root->left);
    cout <<root->val <<" ";
    inorderTraversal(root->right);
}

// insert new node in given BST
TreeNode* insertNewNode(TreeNode* root, int data){
    // current node is empty
    if(root == NULL)
        return createNewNode(data);
    // if new data is less than root value, it will go in left subtree
    if(data < root->val){
        root->left = insertNewNode(root->left, data);
    }
    // new data is greater than root value, then insert in right subtree
    else if(data > root->val){
        root->right = insertNewNode(root->right, data);
    }
    return root;
}

// print common nodes between given two BSTs
// idea is to do inorder traversal iteratively using two stacks
// and compare the elements while traversing...
void printCommonNodes(TreeNode* A, TreeNode* B){
    // s1 : for traversal over tree A
    // s2 : for traversal over tree B
    stack<TreeNode*> s1, s2;
    while(1){
        // push nodes of first tree into s1
        if(A != NULL){
            s1.push(A);
            A = A->left;
        }
        else if(B != NULL){
            s2.push(B);
            B = B->left;
        }
        // both nodes are null
        else if(!s1.empty() && !s2.empty()){
            // get current nodes
            A = s1.top();
            B = s2.top();
            // current nodes are equal
            if(A->val == B->val){
                // print the value and move to inorder successor
                cout <<A->val <<" ";
                s1.pop();
                s2.pop();
                A = A->right;
                B = B->right;
            }
            else if(A->val < B->val){
                // node of first tree is smaller
                // thus, inorder successor of first subtree can 
                // have same value as second subtree current value
                s1.pop();
                // move to inorder successor
                A = A->right;
                B = NULL;
            }
            else if(A->val > B->val){
                // node of first tree is greater
                // inorder successor of second subtree can
                // have same value as first subtree
                s2.pop();
                B = B->right;
                A = NULL;
            }
        }
        else{
            // both roots are null and both stacks are empty
            break;
        }
    }
}

int main(){
    TreeNode* A = NULL;
    A = insertNewNode(A, 5);
    A = insertNewNode(A, 1);
    A = insertNewNode(A, 10);
    A = insertNewNode(A, 0);
    A = insertNewNode(A, 4);
    A = insertNewNode(A, 7);
    A = insertNewNode(A, 9);
    TreeNode* B = NULL;
    B = insertNewNode(B, 10);
    B = insertNewNode(B, 7);
    B = insertNewNode(B, 20);
    B = insertNewNode(B, 4);
    B = insertNewNode(B, 9);
    cout <<"Tree 1 : \n";
    inorderTraversal(A);
    cout <<"\n";
    cout <<"Tree 2 : \n";
    inorderTraversal(B);
    cout <<"\n";
    cout <<"Common Nodes : \n";
    printCommonNodes(A, B);
    cout <<"\n";
    return 0;
}
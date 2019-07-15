// check if given tree is mirror image of itself or not
#include<bits/stdc++.h>
using namespace std;

// structure of a single node in the tree
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

// function to create new node and return the pointer to it
struct Node* createNewNode(int data){
    struct Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// function to check if trees rooted at A and B are mirror image of each other or not
bool isMirror(struct Node* A, struct Node* B){
    // if both nodes are null, return true
    if(A == NULL && B == NULL)
        return true;
    // for subtree A and B to be mirror of each other
    // 1. their data should be same
    // 2. neither of them should be NULL
    // 3. left->left should be mirror image of right->right
    // 4. left->right should be mirror image of right->left
    if(A != NULL && B != NULL && A->data == B->data)
        return isMirror(A->left, B->right) && isMirror(A->right, B->left);
    // none of the above conditions is true
    return false;
}

int main(){

    return 0;
}
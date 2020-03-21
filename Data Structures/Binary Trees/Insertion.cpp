// Insertion of new node in a binary tree
#include<bits/stdc++.h>
using namespace std;

// Representation of a Single Node in a Binary Tree
// left points to Left Subtree
// right points to Right Subtree
// content of Node is stored in data variable
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

// create new node with given data 
// and return a pointer to it
struct Node* createNewNode(int data){
    // allocate memory for new node
    struct Node* temp = new Node;
    // assign the data
    temp->data = data;
    // make left pointer point to NULL
    temp->left = NULL;
    // make right pointer point to NULL
    temp->right = NULL;
    // return the newly created node
    return temp;
}

// Performs inorder traversal over the tree
// root is the root node of the tree
void inorderTraversal(struct Node* root){
    // check if tree is empty
    if(root == NULL)
        return;
    // recursive call on left
    inorderTraversal(root->left);
    // print current contents of node
    cout <<root->data <<" ";
    // recursive call on right
    inorderTraversal(root->right);
}

// Insert new node with data into given tree having root node as root
void insertNewNode(struct Node* root, int data){
    // initialise a queue to traverse in Breadth First Manner over the tree
    queue<struct Node*> q;
    q.push(root);
    while(!q.empty()){
        // get first node from the queue
        struct Node* temp = q.front();
        q.pop();
        // check on left side
        if(temp->left == NULL){
            // left side is empty of this node
            // add a new node here
            temp->left = createNewNode(data);
            break;
        }
        else{
            // left side is not empty
            // push it into the queue
            q.push(temp->left);
        }
        // check on right side
        if(temp->right == NULL){
            // right is empty for this node
            // add a new node here
            temp->right = createNewNode(data);
            break;
        }
        else{
            // right side is not empty
            // enqueue it into the queue
            q.push(temp->right);
        }
    }
    cout <<"\n";
}

int main(){
    struct Node* root = createNewNode(1);
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(6);
    root->right->right = createNewNode(7);
    cout <<"Inorder Traversal Before Insertion\n";
    inorderTraversal(root);
    // insert some random nodes in the tree
    insertNewNode(root, 42);
    insertNewNode(root, 24);
    insertNewNode(root, 48);
    insertNewNode(root, 84);
    cout <<"Inorder Traversal After Insertion\n";
    inorderTraversal(root);
}
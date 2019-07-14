// Delete a node from a binary tree
#include<bits/stdc++.h>
using namespace std;

// Represents a single node in the tree
struct Node{
    // data stored in the node
    int data;
    // pointer to left sub tree
    struct Node* left;
    // pointer to right sub tree
    struct Node* right;
};

// creates a new node with given data and
// returns a pointer to it
struct Node* createNewNode(int data){
    // allocate memory
    struct Node* temp = new Node;
    // assign data
    temp->data = data;
    // point left pointer to null
    temp->left = NULL;
    // point right pointer to null
    temp->right = NULL;
    // return the newly created node
    return temp;
}

// performs Inorder Traversal over the binary tree having root node as root
// Inorder Traversal
// left -> root -> right
void inorderTraversal(struct Node* root){
    // Base condition
    // reached the end of tree
    if(root == NULL)
        return;
    // recursive call on left
    inorderTraversal(root->left);
    // print current data
    cout <<root->data <<" ";
    // recurive call on right
    inorderTraversal(root->right);
}

// function to delete node del_node from binary tree having root as root
void deleteDeepest(struct Node* root, struct Node* del_node){
    // queue for level order traversal
    // search for the target node in BFS manner
    queue<struct Node*> q;
    q.push(root);
    struct Node* temp = NULL;
    while(!q.empty()){
        // get the current node from queue
        temp = q.front();
        q.pop();
        // check if it is the node to be deleted
        if(temp == del_node){
            // assign this node to null to delete it
            temp = NULL;
            // clear memory and return
            delete(del_node);
            return;
        }
        // check in right subtree
        if(temp->right != NULL){
            // there is a node in right
            if(temp->right == del_node){
                // right node is the same node to be deleted
                // assign right pointer to remove it
                temp->right = NULL;
                // free the memory
                delete(del_node);
                return;
            }
            else{
                q.push(temp->right);
            }
        }
        // check in the left subtree
        if(temp->left != NULL){
            // there is node in left
            if(temp->left == del_node){
                // left node is same node to be deleted
                // delete it and return
                temp->left = NULL;
                delete(del_node);
                return;
            }
            else{
                q.push(temp->left);
            }
        }
    }
}

// Delete the node with given value(data)
// and return the root of new tree
struct Node* deleteGivenNode(struct Node* root, int data){
    // if the tree is empty, return null
    if(root == NULL)
        return NULL;
    // if tree contains only a single node
    if(root->left == NULL && root->right == NULL){
        // check if it is the same node to be deleted
        if(root->data == data){
            // delete this node and return null
            return NULL;
        }
        else{
            // data does not match, so don't delete it
            return root;
        }
    }
    // do level order traversal of the tree to find the node to be deleted
    // using queue for BFS
    queue<struct Node*> q;
    q.push(root);

    // node used for traversal over the tree
    struct Node* temp;
    // node to be deleted
    struct Node* del_node = NULL;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        // if data matches of current node
        // this is the node to be deleted
        if(temp->data == data)
            del_node = temp;
        // push left node into queue
        if(temp->left != NULL)
            q.push(temp->left);
        // push right node into queue
        if(temp->right != NULL)
            q.push(temp->right);
    }
    // if node to be deleted is found
    if(del_node != NULL){
        // temp is pointing to last(bottom and rightmost node in tree)
        // del_node is pointing to node to be deleted
        // get value of last node
        int x = temp->data;
        // remove the last node
        deleteDeepest(root, temp);
        // assign the value of last node back into del_node
        del_node->data = x;
    }
    return root;
}

int main(){
    struct Node* root = new Node;
    root->data = 1;
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(6);
    root->right->right = createNewNode(7);
    cout<<"Inorder Traversal of New Tree:\n";
    inorderTraversal(root);
    cout <<"\n";
    root = deleteGivenNode(root, 2);
    cout<<"Inorder Traversal After Deleting 2:\n";
    inorderTraversal(root);
    cout <<"\n";
    return 0;
}
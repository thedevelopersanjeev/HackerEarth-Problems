// Inorder Traversal using stack and without using stack
#include<bits/stdc++.h>
using namespace std;

// Represents a single node in the tree
struct TreeNode{
    // data contained in the node
    int data;
    // pointer to left subtree
    struct TreeNode* left;
    // pointer to right subtree
    struct TreeNode* right;
};

// Creates a new node in the tree and returns the pointer to it
TreeNode* createNewNode(int data){
    TreeNode* temp = new TreeNode;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Approach one using stack
void inorderTraversalOne(TreeNode* root){
    // stack to implement the recusrsion process involved in inorder traversal
    stack<TreeNode*> s;
    struct TreeNode* temp;
    temp = root;
    bool done = false;
    while(!done){
        // keep pushing left nodes into the stack
        if(temp != NULL){
            s.push(temp);
            temp = temp->left;
        }
        else{
            // all left nodes are now in the stack
            if(!s.empty()){
                // there is left node remaining to be explored
                // explore that first
                temp = s.top();
                s.pop();
                // print current node data
                cout <<temp->data <<" ";
                // recurse on right subtree
                temp = temp->right;
            }
            else{
                // stack is empty
                // means the whole tree has been explored
                done = true;
            }
        }
    }
}

// Approach Two
// Inorder Traversal without using stack
void inorderTraversalTwo(TreeNode* root){
    // current node
    struct TreeNode* curr = root;
    // inorder predecessor
    struct TreeNode* pre = NULL;
    // empty tree
    if(root == NULL)
        return;
    while(curr != NULL){
        if(curr->left == NULL){
            // left node is null
            // means this is the leftmost node
            // print it and recurse on right node
            cout <<curr->data <<" ";
            curr = curr->right;
        }
        else{
            // find inorder predecessor of current node
            pre = curr->left;
            while(pre->right != NULL && pre->right != curr)
                pre = pre->right;
            // now pre is the inorder predecessor of curr
            // make curr as right child of pre
            if(pre->right == NULL){
                pre->right = curr;
                curr = curr->left;
            }
            // restore original tree
            else{
                pre->right = NULL;
                cout <<curr->data <<" ";
                curr = curr->right;
            }
        }
    }
}

int main(){
    TreeNode* root = createNewNode(1);
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(6);
    root->right->right = createNewNode(7);
    cout<<"Inorder Traversal using stack:\n";
    inorderTraversalOne(root);
    cout <<"\n";
    cout <<"\nInorder Traversal without using stack:\n";
    inorderTraversalTwo(root);
    cout <<"\n";
    return 0;
}
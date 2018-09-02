void inOrder(Node *root) {
        
        // Base Case 
        if(root == NULL)
            return;
        
        // Recursive call
        inOrder(root->left);
        
        // Output the data
        cout <<root->data <<" ";
        
        // Recursive Call
        inOrder(root->right);
    }
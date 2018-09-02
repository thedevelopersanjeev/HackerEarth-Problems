Node * insert(Node * root, int data) {
        if(root == NULL)
            return new Node(data);
            
        if(data < root->data)
            root->left = insert(root->left, data);
        
        if(data > root->data)
            root->right = insert(root->right, data);
            
        return root;
    }
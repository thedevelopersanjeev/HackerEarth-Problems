#include <bits/stdc++.h>
using namespace std;

class BinarySearchTree {
   private:
    int data;
    BinarySearchTree* left;
    BinarySearchTree* right;

   public:
    BinarySearchTree(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    void insertNode(int data) {
        if (data <= this->data) {
            // new node will go in left as data is less than current node
            if (this->left == NULL) {
                this->left = new BinarySearchTree(data);
            } else {
                this->left->insertNode(data);
            }
        } else {
            // new node will go in right as data is greater than current node
            if (this->right == NULL) {
                this->right = new BinarySearchTree(data);
            } else {
                this->right->insertNode(data);
            }
        }
    }

    void printTree() {
        if (this->left != NULL)
            this->left->printTree();
        write(this->data, " ");
        if (this->right != NULL)
            this->right->printTree();
    }
};

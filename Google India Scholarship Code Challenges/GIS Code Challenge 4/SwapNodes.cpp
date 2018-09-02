#include <bits/stdc++.h>

using namespace std;
typedef struct node {
    int data;
    int level;
    node* left;
    node* right;
}node;

node* createNode(int data, int level) {
    node* newNode = new node();
    newNode->data = data;
    newNode->level = level;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void swapChildNodes(node* parent, int level) {
    if(parent == NULL)
        return;
    if(parent->level == level) {
        node* temp = parent->left;
        parent->left = parent->right;
        parent->right = temp;
        return;
    }
    swapChildNodes(parent->left, level);
    swapChildNodes(parent->right, level);
}

void inOrder(node* root) {
    if(root->left != NULL)
        inOrder(root->left);
    cout << root->data << " ";
    if(root->right != NULL)
        inOrder(root->right);
}

int main() {
    int N,T;
    cin >> N;
    queue<node*> nodeQueue;
    node* nullNode = NULL;
    node* root = createNode(1,1);
    nodeQueue.push(root);
    node* mainroot = root;
    int level;
    for(int i = 0; i < N; i++) {
        root = nodeQueue.front(); nodeQueue.pop();
        if(root != NULL) {
            int l, r;
            cin >> l >> r;
            level = root->level + 1;
            root->left = (l != -1) ? (createNode(l,level)) : (nullNode);
            root->right = (r != -1) ? (createNode(r,level)) : (nullNode);
            nodeQueue.push(root->left);
            nodeQueue.push(root->right);
        }
        else
            i--;
    }

    cin >> T;
    for(int i = 0; i < T; i++) {
        int K; cin >> K;
        for(int j = 1; j * K < level; j++) {
            swapChildNodes(mainroot, j * K);
        }
        inOrder(mainroot); cout << endl;
    }
    return 0;
}
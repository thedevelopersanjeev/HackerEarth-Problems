// Given a sorted linked list
// Convert it to height balanced BST
#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
} TreeNode;

typedef struct ListNode{
    int data;
    ListNode* next;
} ListNode;

ListNode* createNewListNode(int data){
    ListNode* temp = new ListNode;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

TreeNode* createNewTreeNode(int data){
    TreeNode* temp = new TreeNode;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printList(ListNode* head){
    while(head != NULL){
        cout <<head->data <<"->";
        head = head->next;
    }
}

void printInorderTraversal(TreeNode* root){
    if(root == NULL)
        return;
    printInorderTraversal(root->left);
    cout <<root->data <<" ";
    printInorderTraversal(root->right);
}

// head: head pointer to linked list
// len : length of Linked List
TreeNode* convertListToBST(ListNode** head, int len){
    // base condition
    if(len <= 0)
        return NULL;
    // construct left subtree from left half of list
    TreeNode* left = convertListToBST(head, len / 2);
    // create root of the tree
    TreeNode* root = createNewTreeNode((*head)->data);
    // attach left subtree
    root->left = left;
    // change head pointer
    (*head) = (*head)->next;
    // attach right subtree
    root->right = convertListToBST(head, len - len/2 - 1);
    return root;
}

int findLengthOfLinkedList(ListNode* head){
    int len = 0;
    while(head != NULL){
        head = head->next;
        len++;
    }
    return len;
}

int main(){
    ListNode* head = createNewListNode(1);
    head->next = createNewListNode(2);
    head->next->next = createNewListNode(3);
    head->next->next->next = createNewListNode(4);
    head->next->next->next->next = createNewListNode(5);
    head->next->next->next->next->next = createNewListNode(6);
    head->next->next->next->next->next->next = createNewListNode(7);
    cout <<"Linked List : \n";
    printList(head);
    cout <<"\n";
    int n = findLengthOfLinkedList(head);
    cout <<"Length of List : " <<n <<"\n";
    TreeNode* root = convertListToBST(&head, n);
    cout <<"Inorder Traversal of Binary Search Tree : \n";
    printInorderTraversal(root);
    cout <<"\n";
    return 0;
}
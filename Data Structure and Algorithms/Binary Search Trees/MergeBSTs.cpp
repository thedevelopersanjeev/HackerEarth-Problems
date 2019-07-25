#include<bits/stdc++.h>
using namespace std;

// structure of a single node in BST
typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
} TreeNode;

void convertBSTtoList(TreeNode* A, vector<int> &arr){
    if(A == NULL)
        return;
    convertBSTtoList(A->left, arr);
    arr.push_back(A->val);
    convertBSTtoList(A->right, arr);
}

vector<int> solve(TreeNode* A, TreeNode* B){
    vector<int> l1;
    vector<int> l2;
    convertBSTtoList(A, l1);
    convertBSTtoList(B, l2);
    vector<int> ans(l1.size() + l2.size());
    merge(l1.begin(), l1.end(), l2.begin(), l2.end(), ans.begin());
    return ans;
}

TreeNode* createNewNode(int data){
    TreeNode* temp = new TreeNode;
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main(){
    TreeNode* A = createNewNode(5);
    A->left = createNewNode(3);
    A->right = createNewNode(8);
    TreeNode* B = createNewNode(7);
    B->left = createNewNode(2);
    B->right = createNewNode(9);
    vector<int> ans = solve(A, B);
    for(auto ele : ans)
        cout <<ele <<" ";
    cout <<"\n";
    return 0;
}
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode*> q;
    q.push(A);
    while(!q.empty()){
        TreeLinkNode* prev = NULL;    
        int count = q.size();
        while(count--){
            TreeLinkNode* root = q.front();
            q.pop();
            if(prev)
                prev->next = root;
            prev = root;
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
    }
}
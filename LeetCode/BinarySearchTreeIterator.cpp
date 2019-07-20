/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    
    stack<TreeNode*> st;

void insert(TreeNode* root){
    while(root != NULL){
        st.push(root);
        root = root->left;
    }
}
    
    BSTIterator(TreeNode* root) {
        // stack<TreeNode*> temp;
    // swap(st, temp);
    st = stack<TreeNode*>();
    // st.clear();
    insert(root);
    }
    
    /** @return the next smallest number */
    int next() {
        auto least = st.top();
    st.pop();
    insert(least->right);
    return least->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
            return st.size() != 0;

    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
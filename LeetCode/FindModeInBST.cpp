/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if(root == NULL) {
            return vector<int>(0);
        }
        unordered_map<int, int> mp;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            auto curr = st.top();
            st.pop();
            mp[curr->val]++;
            if (curr->left != NULL) {
                st.push(curr->left);
            }
            if (curr->right != NULL) {
                st.push(curr->right);
            }
        }
        int mx = INT_MIN;
        for(const auto &ele : mp) {
            mx = max(mx, ele.second);
        }
        vector<int> ans;
        for(const auto &ele : mp) {
            if(ele.second == mx) {
                ans.push_back(ele.first);
            }
        }
        return ans;
    }
};
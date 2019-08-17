/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        // base condition
        if(root == NULL)
            return 0;
        int ans = 0;
        // recursive call
        for(auto ele : root->children)
            ans = max(ans, maxDepth(ele));
        return 1 + ans;
    }
};  
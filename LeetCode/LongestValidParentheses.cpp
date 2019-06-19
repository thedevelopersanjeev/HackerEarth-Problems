class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> index;
        index.push(-1);
        int ans = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                index.push(i);
            else{
                index.pop();
                if(!index.empty())
                    ans = max(ans, i - index.top());
                else
                    index.push(i);
            }
        }
        return ans;
    }
};
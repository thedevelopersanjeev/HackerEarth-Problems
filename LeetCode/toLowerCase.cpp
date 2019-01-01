class Solution {
public:
    string toLowerCase(string str) {
        vector<char> answer;
        for(int i = 0; i < str.size(); i++){
            int x = str[i];
            if(x >= 65 && x <= 90){
                x += 32;
            }
            answer.push_back(char(x));
        }
        string ans(answer.begin(), answer.end());
        return ans;
    }
};
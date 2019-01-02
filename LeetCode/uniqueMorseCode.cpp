class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        string codes[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> answer;
        
        for(auto word : words){

            string ans;
            
            for(int i = 0; i < word.size(); i++){
                
                ans += codes[((int)word[i])%97];
                
            }
            
            cout <<"\n";
            
            answer.insert(ans);
        
        }
        
        return answer.size();
        
    }
};
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        // array to store indegree - outdegree
        vector<int> degree(N+1, 0);
        for(auto ele : trust){
            ++degree[ele[1]];
            --degree[ele[0]];
        }
        for(int i = 1; i < N + 1; i++){
            int ele = degree[i];
            if(ele == N - 1){
                // if indegree - outdegree is N - 1, 
                // we found our answer
                return i;
            }
        }
        // control reaches here, if no such node(judge) was found
        return -1;
    }
};
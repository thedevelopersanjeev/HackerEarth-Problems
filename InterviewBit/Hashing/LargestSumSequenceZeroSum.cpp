struct Pair{
    int start;
    int end;
};

vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<int, Pair> freq;
    int n = A.size(), sum = 0;
    for(int i = 0; i < n; i++){
        sum += A[i];
        if(freq.find(sum) != freq.end())
            // this sum has been seen before
            // hence, there is a subarray with zero sum
            freq[sum].end = i;
        else{
            freq[sum].start = i;
            freq[sum].end = -1;
        }
    }
    int min = n, max = 0;
    auto it = freq.begin();
    while(it != freq.end()){
        if(it->first == 0){
            if(it->second.end != -1)
                max = it->second.end;
            else
                max = it->second.start;
            min = -1;
        }
        else if(it->second.end != -1){
            if((max-min) < (it->second.end-it->second.start)){
                max = it->second.end;
                min = it->second.start;
            }
            else if(((max-min) == (it->second.end-it->second.start)) && min > it->second.start){
                max = it->second.end;
                min = it->second.start;
            }
        }
        it++;
    }
    vector<int> ans;
    for(int i = min+1; i <= max; i++)
        ans.push_back(A[i]);
    return ans;
}

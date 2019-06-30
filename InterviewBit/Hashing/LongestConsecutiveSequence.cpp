int Solution::longestConsecutive(const vector<int> &arr) {
    
    

    // find max and min element.
    auto it1 = min_element(arr.begin(), arr.end());
    auto it2 = max_element(arr.begin(), arr.end());
    
    int mi = *it1;
    int ma = *it2;
    
    // cout <<"Min Element : " <<mi <<"\n";
    // cout <<"Max Element : " <<ma <<"\n";

    // map to store frequency of each element
    map<int, int> freq;
    
    for(auto ele : arr)
        freq[ele]++;
        

    // for(auto ele : freq)
    //    cout <<ele.first <<"  " <<ele.second <<"\n";

    int count = 0, ans = 0;
    for(int i = mi; i <= ma; i++){
        // next consecutive element is available
        if(freq[i] != 0)
            count++;
        else{
            // next consecutive element is not available
            // update final answer
            // ans = max(ans, count);
            // cout <<"Answer Updated\n";
            count = 0;
        }
        ans = max(ans, count);
    }
    
    // return final answer
    return ans;
    

    
}
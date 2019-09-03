#include<bits/stdc++.h>

bool comp(string a, string b){
    return (a + b) > (b + a);
}

string Solution::largestNumber(const vector<int> &A) {

    vector<string> arr;
    for(auto ele : A)
        arr.push_back(to_string(ele));
    sort(arr.begin(), arr.end(), comp);
    string ans = "";
    int n = arr.size();
    for(auto ele : arr)
        ans += ele;
    int i = 0;
    while(ans[i] == '0' && (i + 1) < n)
        i++;
    return ans.substr(i);

}

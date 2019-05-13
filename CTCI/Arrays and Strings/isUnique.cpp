// Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures?

#include<bits/stdc++.h>
using namespace std;

int main(){
    // output "YES" if input string has unique characters
    // else "NO"
    string s;
    cin >>s;
    // map to store frequency of each character
    map<char, int> freq;
    for(auto c : s)
        freq[c]++;
    bool flag = true;
    for(auto ele : freq){
        if(ele.second > 1){
            // it means a character occurs more than once.
            flag = false;
            break;
        }
    }
    if(flag)
        cout <<"YES" <<endl;
    else
        cout <<"NO" <<endl;
    return 0;
}
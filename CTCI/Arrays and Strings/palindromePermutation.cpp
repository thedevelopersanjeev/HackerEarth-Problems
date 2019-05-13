// Given a string, write a function to check if it is a permutation of
// a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A
// permutation is a rearrangement of letters. The palindrome does not need to be limited to just
// dictionary words.

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    // frequency of each character in string
    map<char, int> freq;
    for(auto ele : s)
        freq[ele]++;
    int countOdd = 0;
    // count number of odd frequencies
    for(auto ele : freq){
        if(ele.second % 2 == 1)
            countOdd++;
        else
            countOdd--;
    }
    // odd frequency can be atmost 1 for a string to be palindrome
    if(countOdd <= 1)
        cout <<"True" <<endl;
    else 
        cout <<"False" <<endl;
    return 0;
}
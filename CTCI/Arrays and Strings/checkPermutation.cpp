// Check Permutation: Given two strings, write a method to decide if one is a permutation of the
// other

#include<bits/stdc++.h>
using namespace std;

// return true if input strings are 
// permutations of each other
// else false
bool checkPermutation(string a, string b){
    // if size is not same, they can't be permutations
    if(a.size() != b.size())
        return false;
    // use the definition of permutation
    map<int, int> freq;
    // count number of chars in a
    for(auto ele : a)
        freq[ele]++;
    // count number of chars in b
    for(auto ele : b){
        freq[ele]--;
        // only possible if char was not there in a
        if(freq[ele] < 0)
            return false;
    }
    return true;
}

int main(){
    string x, y;
    cin >>x >>y;
    cout <<checkPermutation(x, y) <<endl;
    return 0;
}
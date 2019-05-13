// There are three types of edits that can be performed on strings: insert a character,
// remove a character, or replace a character. Given two strings, write a function to check if they are
// one edit (or zero edits) away.

#include<bits/stdc++.h>
using namespace std;

// checks if one char can be replaced to match the strings
bool oneEditReplace(string first, string second){
    // flag variable to note first char difference
    bool foundDifference = false;
    for(int i = 0; i < first.size(); i++){
        if(first[i] != second[i]){
            // characters not matching
            if(foundDifference){
                // there is already one char before 
                // which was different in both strings
                return false;
            }
            foundDifference = true;
        }
    }
    // both string are same or differ by atmost one char only
    return true;
}

// checks if one char can be inserted in first to match it with second
bool oneEditInsert(string first, string second){
    int i = 0, j = 0;
    while(j < second.size() && i < first.size()){
        if(first[i] != second[j]){
            // current characters are different
            if(i != j){
                return false;
            }
            j++;
        }
        else{
            // current characters are same
            i++;
            j++;
        }
    }
    return true;
}

bool oneEditAway(string first, string second){
    if(first.size() == second.size())
        // size is same, which means one character might be replaced
        return oneEditReplace(first, second);
    else if(first.size() + 1 == second.size())
        // one character might be inserted in first string
        // to match it with second string
        return oneEditInsert(first, second);
    else if(first.size() - 1 == second.size())
        // one character might be inserted in second string 
        // to match it with first string
        return oneEditInsert(second, first);
    else
        // string size difference is more than one
        // not possible
        return false;
}

int main(){
    string a, b;
    cin >>a >>b;
    if(oneEditAway(a, b)){
        cout <<"YES" <<endl;
    }
    else{
        cout <<"NO" <<endl;
    }
    return 0;
}
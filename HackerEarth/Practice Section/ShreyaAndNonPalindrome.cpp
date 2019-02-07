#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    for(int i = 0; i < s.size()/2; i++){
        if(s[i] != s[s.size()-i-1])
            return false;
    }
    return true;
}

int check(string s){
    char ch = s[0];
    
    for(int i = 1; i < s.size(); i++){
        if(s[i] == ch)
            break;
    }
    if(isPalindrome(s))
       return s.size()-1;

    return s.size();
}

int main(){
    string s;
    cin >>s;
    
    return 0;
}
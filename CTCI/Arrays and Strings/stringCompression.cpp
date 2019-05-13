// Implement a method to perform basic string compression using the counts
// of repeated characters. For example, the string aabcccccaaa would become a2blc5a3 . If the
// "compressed" string would not become smaller than the original string, your method should return
// the original string. You can assume the string has only uppercase and lowercase letters (a - z).

#include<bits/stdc++.h>
using namespace std;

string compressString(string s){
    stringstream compressed;
    int countConsecutive = 0;
    for(int i = 0; i < s.size(); i++){
    	countConsecutive++;
    	
    	// check if next is different or not
    	if(i + 1 >= s.size() || s[i] != s[i+1]){
    		compressed << s[i];
    		compressed << countConsecutive;
    		countConsecutive = 0;
    	}
    }
    return compressed.str().size() < s.size() ? compressed.str() : s;
}

int main(){
    string s;
    cin >>s;
    cout <<compressString(s) <<endl;
    return 0;
}
// Assume you have a method isSubstring which checks if one word is a substring
// of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one
// call to isSubstring (e.g., Uwaterbottleuis a rotation of uerbottlewat U).

#include<bits/stdc++.h>
using namespace std;

bool isSubstring(string s2, string s1){
	int M = s1.length(); 
    int N = s2.length();
    for (int i = 0; i <= N - M; i++) { 
        int j;
        for (j = 0; j < M; j++) 
            if (s2[i + j] != s1[j]) 
                break;
        if (j == M) 
            return i; 
    }
    return false; 
}

bool isRotation(string s1, string s2){
	int len = s1.size();
	if(len == s2.size() && len > 0){
		string s1s1 = s1 + s1;
		return isSubstring(s1s1, s2);
	}
	return false;
}

int main(){
	string x, y;
	cin >>x >>y;
	cout <<isRotation(x, y) <<endl;
	return 0;
}
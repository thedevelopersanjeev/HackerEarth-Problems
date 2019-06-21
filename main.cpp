/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
        	for(int k = i; k <= j; k++)
        		cout <<arr[k] <<" ";
        	cout <<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	vector<int> arr = {1, 2, 3};
	solve(arr);
	return 0;
}
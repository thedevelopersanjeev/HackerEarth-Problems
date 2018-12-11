#include<bits/stdc++.h>
using namespace std;

int values[4];

int func(int a, int b){
    if(a == 0 && b == 0)
        return values[0];
    else if(a == 0 && b == 1)
        return values[1];
    else if(a == 1 && b == 0)
        return values[2];
    else
        return values[3];
}

int main(){
	int t, c1, c2, c3, c4;
	cin >>t;
	while(t--){
		cin >>values[0] >>values[1] >>values[2] >>values[3];
		int flag = 1;
		for(int i = 0; i < 2; i++){
		    for(int j = 0; j < 2; j++){
		        for(int k = 0; k < 2; k++){
		            flag = flag * (func(i, func(j, k)) == func(func(i, j), k));
		        }
		    }
		}
		if(flag)
		    cout <<"Yes\n";
		else
		    cout <<"No\n";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, arr[10005], k;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &k);
	for(int i=1; i<=k; i++) {
	    printf("%d", i);
	    if(i < k)
	        printf(" ");
	    else
	        printf("\n");
	}
	return 0;
}
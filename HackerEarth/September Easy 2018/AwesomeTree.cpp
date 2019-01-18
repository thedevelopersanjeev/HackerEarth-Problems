#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <assert.h>
#include <iostream>
using namespace std;
const int MAX_N = 5000;
vector<int> way[MAX_N+5];
long long a[MAX_N+5];
long long res;
long long need;
void gofind(int v, int par, int d, long long sum){
    sum += a[v];
    need = min(need, sum/d);
    for(int u : way[v]) if(u != par) gofind(u, v, d+1, sum);
    return;
}
void dfs(int v, int par){
    need = a[v];
    for(int u : way[v]) if(u != par) gofind(u, v, 2, a[v]);
    long long diff = a[v]-need;
    res += diff;
    a[v] = need;
    for(int u : way[v]) if(u != par){
        a[u] += diff;
        dfs(u, v);
    }
    return;
}
int main(){
    int N;
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%lld", &a[i]);
    for(int i=0; i<N-1; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        way[u].push_back(v);
        way[v].push_back(u);
    }
    dfs(1, 0);
    printf("%lld\n", res);
    return 0;
}

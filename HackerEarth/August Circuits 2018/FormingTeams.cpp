#include <bits/stdc++.h>
using namespace std;
 
int calcteams(int kid, unordered_map<int, unordered_set<int> > &bacche, int daddy, int rank[], vector<vector<int> >&memo, int mid)
{
  if(memo[kid][daddy]!=-1)
    {
       // cout<<memo[kid][daddy]<<" ";
        return memo[kid][daddy];
    }
  int ans = 0;
  unordered_set<int>::iterator it = bacche[kid].begin();
  while(it!=bacche[kid].end())
  {
    int temp = abs(rank[*it] - rank[daddy]);
    
   // cout<<(*it)<<"\n";
    if(temp<=mid)//acceptable
    {
     // cout<<rank[*it]<<" "<<rank[daddy]<<" "<<*it<<" "<<daddy<<" "<<mid<<"\n";
      ans += min(calcteams(*it, bacche, *it, rank, memo, mid) + 1, calcteams(*it, bacche, daddy, rank, memo, mid));
    }
    else
      ans += calcteams(*it, bacche, *it, rank, memo, mid) + 1;
    it++;
  }
  memo[kid][daddy] = ans;
  return ans;
}
 
void solvecase()
{
  int n, k;
  scanf("%d %d", &n, &k);
  int rank[n];
  int minrank = 1000000009;
  int maxrank = -1000000009;
  for(int i = 0; i<n; i++)
  {
    scanf("%d", &rank[i]);
    minrank = min(minrank, rank[i]);
    maxrank = max(maxrank, rank[i]);
  }
  unordered_map<int, unordered_set<int> > bacche;
  for(int i = 0; i<n-1; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    bacche[a].insert(b);
  }
  int beg = 0, end = maxrank - minrank;
  vector<vector<int> > memo(n+1,vector<int>(n+1));
  
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=n; j++)
          memo[i][j] = -1;
    }
    int teams = calcteams(0, bacche, 0, rank, memo, mid) + 1;
    cout<<endl;
    if(teams<=k)
    {
        end = mid-1;
    }
    else
      beg = mid+1;
  }
  cout<<end+1<<"\n";
}
 
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    solvecase();
}
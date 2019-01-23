#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m,l,a;
    cin>>n>>m>>l>>a;
    
    vector<pair< ll,ll>> pr;
    ll p,h;
    for(int i=0;i<n;i++)
      {
          cin>>p>>h;
          ll f=p*a-h;
          ll t=p*a+h;
          
          if(f<0||t>l*a)
          {
             cout << "No\n";
             return 0; 
          }
          
          pr.emplace_back(f, 1);
          pr.emplace_back(t,-1);
      }
       
      sort(pr.begin(),pr.end());
      ll st=-1;
      ll bl=0;
     
     for(auto &p : pr)
     {
         if(bl==0)
            st=p.first;
          
         if(p.first-st>2*m)
         {
             cout << "No\n";
             return 0;
         }
         bl+=p.second;        
     }
 
     cout << "Yes\n";
 
 return 0;    
}
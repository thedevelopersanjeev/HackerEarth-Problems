#include<iostream>
#include<algorithm>
#include <cstdlib>
#include <time.h>
#include<vector>
#define pb push_back
 
using namespace std;
 
const int maxn = 1000025;
 
int GR[maxn],X[maxn],Y[maxn],C[maxn],no,hu,minim,a[515][515],j,mux[maxn],muy[maxn];
int i,u,N,M,ANS,IND[maxn],CE,K,bif[513][513],b[515][515],pas,i1;
vector<int> VANS;
 
int grupa(int i)
{
    if (GR[i] == i) return i;
    GR[i] = grupa(GR[i]);
    return GR[i];
}
 
void reuniune(int i,int j)
{
    GR[grupa(i)] = grupa(j);
}
 
bool cmpf(int i,int j)
{
    return(C[i] > C[j]);
}
 
int main()
{
    cin >>  N >>  M >> CE >> K ;
    srand(time(NULL));
    for(i = 1;i <= M;++i)
    {
        cin >> X[i] >> Y[i] >> C[i];
        a[X[i]][Y[i]]=C[i];
        a[Y[i]][X[i]]=C[i];
        IND[i] = i;
    }
    for(i = 1;i <= N; ++i) GR[i] = i;
    sort(IND + 1,IND + M + 1,cmpf);
    for(i1=1;i1<=M;i1++)
    {
       i=rand()%M+1;
        if (grupa(X[IND[i]]) != grupa(Y[IND[i]])){
            ANS += C[IND[i]];reuniune(X[IND[i]],Y[IND[i]]);
            VANS.pb(IND[i]);
        }
    }
 
    for(i = 0;i < N - 1; ++i)
        {bif[X[VANS[i]]][Y[VANS[i]]]=1;bif[Y[VANS[i]]][X[VANS[i]]]=1;}
    no=0;pas=0;
    while(no<CE) 
    {
    pas++;    
    for(i=M;i>=1;i--)
    {
         if((bif[X[IND[i]]][Y[IND[i]]]==0)and(a[X[IND[i]]][Y[IND[i]]]>0)and(b[X[IND[i]]][Y[IND[i]]]<pas))
         { 
         bif[X[IND[i]]][Y[IND[i]]]=1;
         bif[Y[IND[i]]][X[IND[i]]]=1;
         b[X[IND[i]]][Y[IND[i]]]=pas;
         b[Y[IND[i]]][X[IND[i]]]=pas;
         no++;
         mux[no]=X[IND[i]];
         muy[no]=Y[IND[i]];
        
         }
        if(no==CE)i=0;  
    }
    }
    for(i=1;i<=CE;i++)
         cout << mux[i] << " " << muy[i] << "\n" ;
    return 0;
}

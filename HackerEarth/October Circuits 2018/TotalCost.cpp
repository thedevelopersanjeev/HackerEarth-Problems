#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int initCost, availSeats, thresSeats, finalCost, numMembers;
    cin >>initCost >>availSeats >>thresSeats >>finalCost >>numMembers;
    int totalCost = 0;
    while(numMembers != 0){
        
        if(availSeats <= thresSeats){
            totalCost += finalCost;
            availSeats--;
        }
        else{
            totalCost += initCost;
            availSeats--;
        }
        
        numMembers--;
    }
    cout <<totalCost;
    return 0;
}
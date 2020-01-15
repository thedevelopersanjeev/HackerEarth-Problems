/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target ("sse4")
#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>
#include <boost/functional/hash.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define deb(x) cout << #x << " is " << x << "\n";

using namespace std;
using namespace __gnu_pbds;

const double PI = 2 * acos(0.0);
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

unsigned long long f(unsigned long long a, unsigned long long b){
    if(b == 0)
        return 1;
    else if(b == 1)
        return a;
    else if(b == 2)
        return a * a;
    else if(b % 2 == 0)
        return f(a * a, b / 2);
    else 
        return a * f(a * a, (b - 1) / 2);
}

int main(){ 
    unsigned long long int t, n, a, b, c, d, e, s, x;
    cin >>t;
    while(t--){
        cin >>n >>a;
        unsigned long long p = f(10, n);
        s = a + (2 * p);
        cout <<s <<endl <<flush;
        fflush(stdout);
        cin >>b;
        c = p - b;
        cout <<c <<endl <<flush;
        fflush(stdout);
        cin >>d;
        e = p - d;
        cout <<e <<endl <<flush;
        fflush(stdout);
        cin >>x;
        if(x == -1)
            return 0;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
cin >> n;
long int a[n], b[n], c[n];
memset(c, 0, sizeof(c));
long long int cnt=0;
for (int i = 0; i < n; i++)
cin >> a[i];
for (int i = 0; i < n; i++)
cin >> b[i];

for (int i = n-1; i >= 0; i--) {
for (int j = i-1; j >= 0; j--) {
if (a[i] > a[j])
c[i]++;
}
}

for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
if (a[i] < b[j])
cnt+=c[i];
}
}
cout << cnt;
}
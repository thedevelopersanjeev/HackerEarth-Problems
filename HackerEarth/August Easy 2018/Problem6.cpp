#include<bits/stdc++.h>
using namespace std;
int seg1[2500005], bit[600005];
int a[1000005];
int ans, n, q;
int build(int st, int en, int i)
{
    if(st == en)
    {
        seg1[i] = a[st];
        return seg1[i];
    }
    int mid = (st+en)/2;
    return seg1[i] = max(build(st, mid, (2*i)), build(mid+1, en, (2*i)+1));
}
int update(int st, int en, int i, int ind, int val)
{
    if(en < ind || ind < st)
        return seg1[i];
    if(st == en)
        return seg1[i] = val;
    int mid = (st+en)/2;
    return seg1[i] = max(update(st, mid, (2*i), ind, val), update(mid+1, en, (2*i)+1, ind, val));
}
void query1(int st, int en, int i, int ind)
{
    if(en < ind || ind < st)
        return;
    if(st == en)
    {
        ans = seg1[i];
        return;
    }
    int mid = (st+en)/2;
    query1(st, mid, (2*i), ind);
    query1(mid+1, en, (2*i)+1, ind);
    return;
}
int query2(int st, int en, int l, int r, int i)
{
    if(r < st || en < l)
        return 0;
    if(l <= st && en <= r)
        return seg1[i];
    int mid = (st+en)/2;
    return max(query2(st, mid, l, r, (2*i)), query2(mid+1, en, l, r, (2*i)+1));
}
void upd(int i, int val)
{
    while(i <= n+q+q)
    {
        bit[i] += val;
        i += i&(-i);
    }
    return;
}
int que1(int i)
{
    int ans1 = 0;
    while(i > 0)
    {
        ans1 += bit[i];
        i -= i&(-i);
    }
    return ans1;
}
int que(int i)
{
    int l = 1, r = n+q+q;
    int ans;
    while(l <= r)
    {
        int mid = (l+r)/2;
        int x = que1(mid);
        if(x == i)
        {
            ans = mid;
            r = mid - 1;
            continue;
        }
        if(x < i)
            l = mid+1;
        else
            r = mid - 1;
    }
    return ans;
}
signed main()
{
    scanf("%d %d", &n, &q);
    for(int i = 1;i <= n+q+q;i++)
        a[i] = 0;
    for(int i = q+1;i <= q+n;i++)
        scanf("%d", &a[i]);
    for(int i = 0;i <= n+q+q;i++)
        bit[i] = 0;
    for(int i = 1;i <= n;i++)
        upd(i+q, 1);
    build(1, n+q+q, 1);
    for(int qq = 1;qq <= q;qq++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if(x == 1)
        {
            y = que(y);
            z = que(z);
            // printf("\t%d %d\n", y, z);
            printf("%d\n", query2(1, n+q+q, y, z, 1));
        }
        else
        {
            if(y == 1)
            {
                z = que(z);
                query1(1, n+q+q, 1, z);
                int yu = que(n);
                update(1, n+q+q, 1, yu+1, ans);
                update(1, n+q+q, 1, z, 0);
                upd(z, -1);
                upd(yu+1, 1);
            }
            else
            {
                z = que(z);
                query1(1, n+q+q, 1, z);
                int yu = que(1);
                update(1, n+q+q, 1, yu-1, ans);
                update(1, n+q+q, 1, z, 0);
                upd(z, -1);
                upd(yu-1, 1);
            }
        }
    }
    return 0;
}
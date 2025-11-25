#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

bool check(LL h,vector<LL> &a,LL n,ULL x)
{
    unsigned long long sum = 0;
    for(int i=1;i<=n;i++)
    {
        LL t = h - a[i];
        if(t <= 0) t = 0;
        sum += t;
    }
    return sum <= x;
}

void solve()
{
    LL n;
    ULL x;
    cin>>n>>x;
    vector<LL> a(n+1,0);
    for(int i = 1;i <= n;i++) cin>>a[i];
    
    LL l = 1,r = 2e9;
    while(r > l)
    {
        LL mid = l + r + 1 >> 1;
        if(check(mid,a,n,x)) l = mid;
        else r = mid - 1;
    }
    cout<<l<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
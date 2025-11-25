#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve()
{
    int n;
    cin>>n;
    
    vector<int> a(n+1,0),b(n+1,0);
    LL sum1 = 0,sum2 = 0;
    for(int i = 1;i <= n; i++) cin>>a[i],sum1 += a[i];
    for(int i = 1;i <= n; i++) cin>>b[i],sum2 += b[i];
    
    sort(a.begin()+1,a.end()),sort(b.begin()+1,b.end());
    cout<<min(sum1 + 1ll * b[1] * n,sum2 + 1ll * a[1] * n)<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
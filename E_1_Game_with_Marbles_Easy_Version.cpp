#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve()
{
    int n;
    cin>>n;
    
    LL A = 0,B = 0;
    vector<LL> a(n,0),b(n,0);
    for(int i = 0;i < n; i++) cin>>a[i],A += a[i];
    for(int i = 0;i < n; i++) cin>>b[i],B += b[i];
    
    vector<int> p(n);
    iota(p.begin(),p.end(),0);
    sort(p.begin(),p.end(),
    [&](int i,int j){
        return a[i] + b[i] > a[j] + b[j];
    });
    
    LL ans = 0;
    for(int i = 0; i < n; i++)
    {
        int idx = p[i];
        if(i % 2 == 0) 
        {
            ans = (A - 1) - (B - b[idx]);
            A -= 1;
            B -= b[idx];
        }
        else
        {
            ans = (A - a[idx]) - (B - 1);
            A -= a[idx];
            B -= 1;
        }
    }
    
    cout<<ans<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
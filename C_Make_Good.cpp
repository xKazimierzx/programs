#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve()
{
    int n;
    cin>>n;
    
    vector<LL> a(n+1,0);
    LL sum = 0,s_xor = 0;
    for(int i = 1;i <= n; i++) cin>>a[i],sum += a[i],s_xor ^= a[i];
    
    if(sum == s_xor * 2ll)
    {
        puts("0");
        puts("");
        return;
    }
    
    if(s_xor)
    {
        puts("2");
        cout<<s_xor<<" "<<sum + s_xor<<endl;
    }
    else
    {
        puts("1");
        cout<<sum<<endl;
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
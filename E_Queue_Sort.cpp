#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
bool st[N];
typedef long long LL;

void solve()
{
    int n;
    cin>>n;
    vector<LL> a(n+1,0);
    
    LL minv = 1e9;
    for(int i = 1;i <= n; i++) cin>>a[i],minv = min(minv,a[i]);
    
    int len = 1;
    for(int i = n; i - 1 >= 1;i--)
        if(a[i] >= a[i-1]) len++;
        else break;
        
    for(int i = 1;i <= n - len; i++)
        if(a[i] == minv)
        {
            puts("-1");
            return;
        }
    
    cout<<n - len<<endl;
    
}

int main()
{
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
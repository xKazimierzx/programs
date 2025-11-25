#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        if(c=='B') a[i] = 1;
        else a[i] = 0;
    }
    
    int ans = 0;
    for(int i=1;i<=n;)
        if(a[i]==1)
        {
            ans++;
            i += k;
            if(i > n) break;
        }else i++;

    cout<<ans<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
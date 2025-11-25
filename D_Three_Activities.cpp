#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
typedef pair<int,int> PII;
typedef long long LL;

void solve()
{
    int n;
    cin>>n;
    vector<PII> a(n),b(n),c(n);
    for(int i = 0;i < n; i++)
    {
        int x;
        cin>>x;
        a[i] = {x,i};
    }
    for(int i = 0;i < n; i++)
    {
        int x;
        cin>>x;
        b[i] = {x,i};
    }
    for(int i = 0;i < n; i++)
    {
        int x;
        cin>>x;
        c[i] = {x,i};
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    
    int ans = 0;
    for(int i = 0;i < 3 && n - i  - 1 >= 0; i++)
        for(int j = 0;j < 3 && n - j  - 1 >= 0; j++)
            for(int k = 0;k < 3 && n - k  - 1 >= 0; k++)
                if(a[n - 1 - i].second != b[n - 1 - j].second && c[n - 1 - k].second != b[n - 1 - j].second
                && a[n - 1 - i].second != c[n - 1 - k].second)
                    ans = max(ans,a[n - 1 - i].first + b[n - 1 - j].first + c[n - 1 - k].first);
    cout<<ans<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
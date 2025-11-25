#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

void solve()
{
    int n;
    cin>>n;
    
    vector<vector<int>> e(n+1);
    for(int i = 2;i <= n; i++)
    {
        int x;
        cin>>x;
        e[x].push_back(i);
    }
    
    vector<int> sz(n+1,0);
    auto dfs1 = [&](auto self,int u) -> void{
        sz[u] = 1;
        for(auto v:e[u])
        {
            self(self,v);
            sz[u] += sz[v];
        }
    };
    
    dfs1(dfs1,1);
    
    auto dfs = [&](auto self,int u) -> int{
        int mx = 0;
        for(auto v:e[u]) mx = max(mx,sz[v]);
        
        int now = (sz[u] - 1) / 2;
        if(mx * 2 > sz[u] - 1)
        {
            for(auto v:e[u]) 
                if(sz[v] == mx)
                    return self(self,v) + min(sz[u] - 1 - mx,(sz[u] - 1 - 2*self(self,v))/2);
        }
        else return now;
    };
    
    int ans = dfs(dfs,1);
    cout<<ans<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
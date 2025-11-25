#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

void solve()
{
    int n;
    cin>>n;
    
    char g[N][N];
    for(int i = 1;i <= n; i++)
        for(int j = 1;j <= n; j++) cin>>g[i][j];
    
    int ans = 0;
    for(int st = 1,ed = n;st <= n/2; st++,ed--)
    {
        int len = ed - st + 1;

        string t;

        for(int i = 0; i < len - 1; i++)
        {
            string s;
            s.push_back(g[st][st+i]);
            s.push_back(g[st+i][ed]);
            s.push_back(g[ed][ed-i]);
            s.push_back(g[ed-i][st]);
            char tmp = 'a';
            for(auto i:s)
                if(i >= tmp) tmp = i;
            
            for(auto i:s) 
                if(tmp - i >= 0) ans += (tmp - i);
            //cout<<s<<endl;
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
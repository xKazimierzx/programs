#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define debug(x) cout << x << endl
#define cy puts("YES")
#define cn puts("NO")
#define lowbit(x) (x & (-x))
#define endl '\n'

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<PII,int> PIII;
typedef pair<double,double> PDD;
typedef pair<PDD,double> PDDD;

const int N = 1e5 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;

vector<int> e[N];
bool st[N];

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        if(x == y) continue;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    int ans = 0;
    auto dfs = [&](auto &dfs,int u,int cnt) -> void
    {
        st[u] = true;
        if(cnt > m) return;
        int res = 0;
        for(auto now:e[u])
        {
            if(st[now]) continue;
            res++;
            if(a[u] == 1)
            {
                if(a[now] == 1) dfs(dfs,now,cnt + 1);
                else dfs(dfs,now,0);
            }else{
                if(a[now] == 1) dfs(dfs,now,1);
                else dfs(dfs,now,0);
            }
        }

        if(!res && cnt <= m) ans++;
    };
    dfs(dfs,1,a[1]);
    cout << ans << endl;
}

int main()
{
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
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

const int N = 2e5 + 10;
const int MOD = 998244353;
const int DEP = 19;
const double PI = acos(-1);
const double EPS = 1e-8;

int f[N][20],dep[N],ans[N],d[N],fa[N],n,m;
vector<int> edge[N];
bool st[N];

void bfs2()
{
    queue<int> q;
    q.push(1);
    dep[1] = 1;

    while(q.size())
    {
        int t = q.front();
        q.pop();

        for(auto j:edge[t])
        {
            if(dep[j]) continue;
            dep[j] = dep[t] + 1;
            ans[j] = ans[t] + (fa[j] != fa[t]);
            q.push(j);
            f[j][0] = t;
            for(int k=1;k<=DEP;k++) f[j][k] = f[f[j][k-1]][k-1];
        }
    }
}

void bfs1()
{
    for(int i = 1;i <= n;i++) fa[i] = -1;
    queue<tuple<int,int>> q;
    
    for(int i = 1;i <= n;i++)
        if(d[i] > 2) q.push({i,i});

    while(q.size())
    {
        auto [u,t] = q.front();
        q.pop();
        if(fa[u] != -1) continue;
        fa[u] = t;
        for(auto to:edge[u])
            if(fa[to] == -1) q.push({to,t});
    }
}

int lca(int a,int b)
{
    if(dep[a]<dep[b]) swap(a,b);

    for(int i=DEP;i>=0;i--)
        if(dep[f[a][i]]>=dep[b]) a = f[a][i];
    if(a==b) return a;

    for(int i=DEP;i>=0;i--)
        if(f[a][i]!=f[b][i]) a = f[a][i],b = f[b][i];
    return f[a][0];
}

void solve()
{
    cin >> n;

    for(int i = 1;i <= n - 1;i++)
    {
        int u,v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        d[u]++,d[v]++;
    }

    bfs1();
    bfs2();

    cin >> m;
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        cout << ans[u] + ans[v] - 2 * ans[lca(u,v)] + 1 << endl;
    }
}

int main()
{
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
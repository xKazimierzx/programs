#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define bp(x) __builtin_poptount(x)
#define bpll(x) __builtin_poptountll(x)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rep_(i,a,b) for(int i=a;i>=b;i--)
#define debug(x) cout << x << '\n'
#define cy cout << "Yes" << '\n'
#define cn cout << "No" << '\n'
#define x first
#define y second

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef pair<double,double> PDD;
typedef pair<double,PDD> PDDD;

const int N = 1e4 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;
const int DEP = 31;

vector<PII> e[N];
int dis[N],d[N],f[N][DEP+1];

void bfs(int u)
{
    queue<int> q;
    dis[u] = 0;
    d[u] = 1;
    q.push(u);

    while(q.size())
    {
        auto now = q.front();
        q.pop();

        for(auto [to,w] : e[now])
        {
            if(d[to]) continue;
            d[to] = d[now] + 1;
            dis[to] = dis[now] + w;
            q.push(to);
            f[to][0] = now;
            for(int i = 1;i <= DEP;i++) f[to][i] = f[f[to][i - 1]][i - 1];
        }
    }
}

int lca(int u,int v)
{
    if(d[u] < d[v]) swap(u,v);

    for(int i = DEP;i >= 0;i--)
        if(d[f[u][i]] >= d[v]) u = f[u][i];

    if(u == v) return u;

    for(int i = DEP;i >= 0;i--)
        if(f[u][i] != f[v][i]) u = f[u][i],v = f[v][i];
    return f[u][0];
}

void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n - 1;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    bfs(1);
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        cout << dis[u] + dis[v] - 2 * dis[lca(u,v)] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
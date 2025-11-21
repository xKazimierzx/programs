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

const int N = 4e4 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;
const int DEP = 31;

vector<int> e[N];
int n,m,root = -1;
int f[N][DEP + 1],d[N];

void bfs(int u)
{
    queue<int> q;
    d[u] = 1;
    q.push(u);

    while(q.size())
    {
        auto now = q.front();
        q.pop();

        for(auto to:e[now])
        {
            if(d[to]) continue;
            d[to] = d[now] + 1;
            q.push(to);
            f[to][0] = now;
            for(int i = 1;i <= DEP;i++) f[to][i] = f[f[to][i-1]][i - 1];
        }
    }
}

int lca(int a,int b)
{
    if(d[a] < d[b]) swap(a,b);

    for(int i = DEP;i >= 0;i--)
        if(d[f[a][i]] >= d[b]) a = f[a][i];

    if(a == b) return a;

    for(int i = DEP;i >= 0;i--)
        if(f[a][i] != f[b][i]) a = f[a][i],b = f[b][i];

    return f[a][0];
}

void solve()
{
    cin >> n;
    rep(i,1,n)
    {
        int u,v;
        cin >> u >> v;
        if(v == -1) root = u;
        else{
            e[u].push_back(v);
            e[v].push_back(u);
        }
    }

    bfs(root);

    cin >> m;
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        //cout << lca(u,v) << endl;
        if(lca(u,v) == u) cout << 1 << endl;
        else if(lca(u,v) == v) cout << 2 << endl;
        else cout << 0 << endl;
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


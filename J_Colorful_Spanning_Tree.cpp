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
typedef pair<int,PII> PIII;
typedef pair<double,double> PDD;
typedef pair<PDD,double> PDDD;

const int N = 1e3 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;

int f[N];

int find(int x)
{
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) f[i] = i;

    vector<int> a(n + 1);
    for(int i = 1;i <= n;i++) cin >> a[i];

    vector<PIII> edge;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
        {
            int w;
            cin >> w;
            edge.push_back({w,{i,j}});
        }
    
    sort(edge.begin(),edge.end());

    LL ans = 0;
    for(auto t:edge)
    {
        int w = t.x,u = find(t.y.x),v = find(t.y.y);

        if(u != v) ans += (LL)(a[u] + a[v] - 1) * w;
        else ans += (LL)(a[u] - 1) * w;

        a[u] = a[v] = 1;
        f[v] = u;
    }

    cout << ans << endl;
}

int main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
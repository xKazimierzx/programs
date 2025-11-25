#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define bp(x) __builtin_poptount(x)
#define bpll(x) __builtin_poptountll(x)
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define rep_(i,a,b) for(int i = a;i >= b;--i)
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

const int N = 2e5 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;
const int DEP = 31;

struct DSU{
    vector<int> f,sz;

    DSU(int n){
        f.resize(n + 1);
        sz.resize(n + 1);
        for(int i = 1;i <= n;i++) f[i] = i,sz[i] = 1;
    }

    int find(int x){
        if(x != f[x]) return f[x] = find(f[x]);
        return f[x]; 
    }

    bool same(int a,int b) {
        return find(a) == find(b);
    }

    bool merge(int a,int b){
        int fa = find(a),fb = find(b);
        if(fa == fb) return false;
        if(sz[fa] < sz[fb]) swap(fa,fb);
        sz[fa] += sz[fb];
        f[fb] = fa;
        return true;
    }

    int size(int x){
        return sz[find(x)];
    }
};

void solve()
{
    int n;
    cin >> n;    
    vector<int> a(n + 1),pre(n + 1,n),suf(n + 2),id(n + 1);
    for(int i = 1;i <= n;i++) cin >> a[i],id[a[i]] = i;
    for(int i = 1;i <= n;i++) pre[i] = min(pre[i - 1],a[i]);
    for(int i = n;i >= 1;i--) suf[i] = max(suf[i + 1],a[i]);

    for(int i = 2;i <= n;i++)
        if(pre[i - 1] > suf[i])
        {
            cn;
            return;
        }
    cy;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
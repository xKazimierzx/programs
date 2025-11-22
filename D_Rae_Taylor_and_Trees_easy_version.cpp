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
    DSU p(n);
    vector<int> a(n + 1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    
    stack<int> stk;
    for(int i = 1;i <= n;i++)
    {
        int t = a[i];
        while(stk.size() && t > a[stk.top()])
        {
            p.merge(i,stk.top());
            a[i] = min(a[i],a[stk.top()]);
            stk.pop();
        }
        stk.push(i);
    }   

    int r = p.find(1);
    for(int i = 2;i <= n;i++)
        if(p.find(i) != r)
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
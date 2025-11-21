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

const int N = 1e5 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;
const int DEP = 31;

void solve()
{
    int n,m,l;
    cin >> n >> m >> l;
    vector<LL> a(n),b(m),c(l);
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < m;i++) cin >> b[i];
    for(int i = 0;i < l;i++) cin >> c[i];
    int i = 0,j = 0,k = 0;
    LL ans = LONG_LONG_MAX;
    while(i < n && j < m && k < l)
    {
        ans = min(ans,max(max(a[i],b[j]),c[k]) - min(min(a[i],b[j]),c[k]));
        if(a[i] <= b[j] && a[i] <= c[k]) i++;
        else if(b[j] <= a[i] && b[j] <= c[k]) j++;
        else k++;
    }
    cout << 2ll * ans << endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
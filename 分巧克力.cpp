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

int n,k;
PII a[N];

bool check(int x)
{
    int res = 0;
    for(int i = 0;i < n;i++) res += (a[i].x / x) + (a[i].y / x);
    return res >= k;
}

void solve()
{
    cin >> n >> k;
    for(int i = 0;i < n;i++) cin >> a[i].x >> a[i].y;
    
    int l = 0,r = 1e5 + 1;
    while(l + 1 != r)
    {
        int mid = l + r >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
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
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> a(n),b(n);
    for(int j = 0;j < q;j++)
    {
        int c,l,r;
        cin >> c >> l >> r;
        l--,r--;
        if(c == 1) for(int i = l;i <= r;i++) a[i] = k;
        else if(c == 2) for(int i = l;i <= r;i++) b[i] = 1;
    }

    for(int i = 0;i < n;i++)
    {
        if(a[i] == k && b[i] == 1) a[i] = k + 1;
        else if(a[i] == 0) a[i] = (i + k) % k;
        cout << a[i] << " \n"[i == n - 1];
    }
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
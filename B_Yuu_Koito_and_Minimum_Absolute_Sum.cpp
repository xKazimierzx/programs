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
    //abs(an - a1)_min
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        if(a[i] == -1 && i != n - 1 && i) a[i] = 0;
    }

    if(a[n - 1] == -1 && a[0] != -1) a[n - 1] = a[0];
    else if(a[0] == -1 && a[n - 1] != -1) a[0] = a[n - 1];
    else if(a[n - 1] == -1 && a[0] == -1) a[n - 1] = a[0] = 0;
    else ans = abs(a[n - 1] - a[0]);

    cout << ans << endl;
    for(int i = 0;i < n;i++) cout << a[i] << ' ';
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
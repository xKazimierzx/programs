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
    int n;
    cin >> n;
    vector<LL> s(n + 1);
    for(int i = 1;i <= n;i++) cin >> s[i],s[i] += s[i - 1];
    //s[n] + (l + r)*(r - l + 1) - (s[r] - s[l - 1])
    //s[n] + (r * r + r - s[r]) - (l * l - l - s[l - 1])
    LL ans = 0,mi = LONG_LONG_MAX;
    for(int i = 1;i <= n;i++)
    {
        mi = min(mi,(LL)i * i - i - s[i - 1]);
        ans = max(ans,s[n] + (LL)i * i + i - s[i] - mi);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
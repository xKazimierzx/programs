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

const int N = 2e6 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;
const int DEP = 31; 

int l[N],r[N],a[N],ans;

void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] >= 0) r[a[i]]++;
        else l[-a[i]]++;
    }
    for(int i = 1;i < N - 1;i++) l[i] += l[i - 1],r[i] += r[i - 1];
    ans = max(l[m],r[m]);
    for(int i = 1;i <= n;i++)
        if(a[i] < 0 && m >= 2 * -a[i]) ans = max(ans,l[-a[i]] + r[m + 2 * a[i]]);
        else if(a[i] >= 0 && m >= 2 * a[i]) ans = max(ans,r[a[i]] + l[m - 2 * a[i]]);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
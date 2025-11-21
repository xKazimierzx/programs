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

const int N = 1e5 + 10;
const double PI = acos(-1);
const double EPS = 1e-8;
const int DEP = 31;
const int MOD = 1e9 + 7;

LL bitpow(LL a,LL b)
{
    LL res = 1;
    while(b)
    {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res % MOD;
}

void solve()
{
    LL n;
    cin >> n;
    
    if(n == 2)
    {
        cout << "650" << endl;
        return;
    }

    LL ans = 0;
    for(LL i = 0;i < n / 2;i++) ans = (ans + bitpow(26,n / 2) * (25 - i) % MOD + MOD) % MOD;
    
    if(n & 1) ans = ans * (n - 1) % MOD;
    else ans = ans * n % MOD;

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
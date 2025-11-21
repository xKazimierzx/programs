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
const int MOD = 1e9 + 7;
const double PI = acos(-1);
const double EPS = 1e-8;
const int DEP = 31;

// 1 0
// 0 1
// 1 1
// 1 2
// 2 3
// 3 5
// 5 8
// 8 13
// 13 21
// 21 34

vector<LL> cnt0(N,0),cnt1(N,0),dp(N,0);

void solve()
{
    int n;
    cin >> n;
    cout << dp[n] << endl;
}
 
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    int n = 100000;
    cnt0[1] = 1,cnt1[2] = 1;
    for(int i = 3;i <= n;i++)
    {
        cnt0[i] =  cnt1[i - 1] % MOD;
        cnt1[i] = (cnt0[i - 1] + cnt1[i - 1]) % MOD;
    }

    for(int i = 3;i <= n;i++) 
        dp[i] = (dp[i - 1] + dp[i - 2] + cnt1[i - 2] * cnt0[i - 1] % MOD) % MOD;
    cin >> T;
    while(T--) solve();
    return 0;
}
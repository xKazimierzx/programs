#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define debug(x) cout << x << endl
#define cy puts("Yes")
#define cn puts("No")
#define lowbit(x) (x & (-x))
#define endl '\n'

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<PII,int> PIII;
typedef pair<double,double> PDD;
typedef pair<PDD,double> PDDD;

const int N = 1e5 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;

void solve()
{
    int n;
    cin >> n;
    map<LL,LL> h;
    LL maxv = 0;
    for(int i = 0;i < n;i++)
    {
        LL x;
        cin >> x;
        maxv=  max(maxv,x);
        h[x]++;
    }
    vector<LL> dp(maxv + 1);
    dp[1] = h[1];
    for(int i = 2;i <= maxv;i++) dp[i] = max(dp[i - 1],dp[i - 2] + (LL)i * h[i]);
    cout << dp[maxv] << endl;
}

int main()
{
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
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
const int MOD = 1e9 + 7;
const double PI = acos(-1);
const double EPS = 1e-8;

LL bitpow(LL a,LL b,int p)
{
    LL res = 1;
    while(b)
    {
        if(b & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res % p;
}

void solve()
{
    int n;
    cin >> n;
    vector<LL> a(n+1,0),b(n+1,0);
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) b[i] = a[i] ^ b[i - 1];
    
    LL ans = 0;
    for(int i = 1;i <= n;i++)
        if(i != n) ans = (ans + 2 * b[i] * bitpow(3,n - i - 1,MOD) + MOD) % MOD;
        else ans = (ans + b[n] + MOD) % MOD;

    cout << ans << endl;
}

int main()
{
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
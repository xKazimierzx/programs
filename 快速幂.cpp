#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define debug(x) cout << x << '\n'
#define cy cout << "Yes" << '\n';
#define cn cout << "No" << '\n';
#define lowbit(x) (x & (-x))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rep_(i,a,b) for(int i=a;i>=b;i--)
#define x first
#define y second

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef pair<double,double> PDD;
typedef pair<double,PDD> PDDD;

const int N = 1e5 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;

LL bitpow(LL a,LL b,LL p)
{
    LL res = 1;
    while(b)
    {
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p;
}

void solve()
{
    LL a,b,p;
    cin >> a >> b >> p;
    cout << bitpow(a,b,p)<< endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
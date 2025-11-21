#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define debug(x) cout << x << endl
#define cy puts("YES")
#define cn puts("NO")
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
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    if (p == n) {
        cout << (m == q ? "YES" : "NO") << endl;
    } else {
        if (n % p == 0) {
            int k = n / p;
            cout << (k * q == m ? "YES" : "NO") << endl;
        } else {
            cy;
        }
    }
}

int main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
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
    int n;
    cin >> n;
    vector<LL> a(n+1),suf(n+2),maxv(n+1);
    LL t = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        t = max(t,a[i]);
        maxv[i] = t;
    }
    for(int i = n;i >= 1;i--) suf[i] = suf[i+1] + a[i];

    for(int i = n;i >= 1;i--)
    {
        if(maxv[i] > a[i]) cout << suf[i+1] + maxv[i] << ' ';
        else cout << suf[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
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
    vector<PII> a(n);
    for(int i = 0;i < n;i++) cin >> a[i].x >> a[i].y;

    sort(a.begin(),a.end());

    int last = -0x3f3f3f3f,ans = 0;
    for(auto [l,r] : a)
    {
        if(l < last)
        {
            last = min(last,r);
            continue;
        }
        ans++;
        last = r;
    }

    cout << ans << endl;
}

int main()
{
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
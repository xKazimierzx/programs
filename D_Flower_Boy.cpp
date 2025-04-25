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
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1),b(m+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) cin >> b[i];

    vector<int> pre(n+2),suf(n+2);
    int cur = 1;
    for(int i = 1;i <= n;i++)
        if(a[i] >= b[cur]) pre[i] = pre[i - 1] + 1,cur++;
        else pre[i] = pre[i - 1];

    cur = m;
    for(int i = n;i >= 1;i--)
        if(a[i] >= b[cur]) suf[i] = suf[i + 1] + 1,cur--;
        else suf[i] = suf[i + 1];

    if(pre[n] >= m)
    {
        cout << 0 << endl;
        return;
    }

    int ans = 0x3f3f3f3f;
    for(int i = 1;i <= n + 1;i++)
    {
        int k = b[pre[i - 1] + 1];
        if(pre[i - 1] + 1 + suf[i] >= m) ans = min(ans,k);
    }

    if(ans == 0x3f3f3f3f) cout << -1 << endl;
    else cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
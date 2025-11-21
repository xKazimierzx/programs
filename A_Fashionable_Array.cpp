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
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    sort(a.begin(),a.end());

    int ans = 0x3f3f3f3f;
    for(int i = 0;i < n;i++)
        for(int j = i;j < n;j++)
           if((a[i] + a[j]) % 2 == 0) ans = min(ans,i + n - j - 1);
    cout << ans << endl;
}

int main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
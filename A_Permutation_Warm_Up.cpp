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
    
    LL ans = 1,val = 1;
    int cnt = 0;
    for(int i = 2;i <= n;i++)
    {
        ans += val;
        cnt++;
        if(cnt == 2) cnt = 0,val++;
    }

    cout << ans << endl;
 }

int main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
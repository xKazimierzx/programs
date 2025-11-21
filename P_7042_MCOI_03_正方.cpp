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
    vector<LL> g(4);
    for(int i = 0;i < 4;i++) cin >> g[i];
    sort(g.begin(),g.end());

    if(g[0] + g[3] == g[1] + g[2])
    {
        int ans1 = 1,ans2 = 1,ans3 = 1;
        if(g[0] != g[3]) ans1 = 2;
        if(g[1] != g[2]) ans2 = 2;
        if(g[0] != g[1] && g[0] != g[2]) ans3 = 2;
        cout << ans1 * ans2 * ans3 << endl;
        return;
    }
                        
    cout << 0 << endl;
}

int main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
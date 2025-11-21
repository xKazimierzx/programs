#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define debug(x) cout << x << endl
#define cy puts("Yes")
#define cn puts("No")
#define lowbit(x) (x & (-x))
#define endl '\n'

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<PII,int> PIII;
typedef pair<double,double> PDD;
typedef pair<PDD,double> PDDD;

const int N = 2025;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;

ULL c[N][N];

void solve()
{
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j <= i; j ++ )
            if (!j) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];

    string s = "kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";

    ULL cnt = 0;
    for(auto i : s)
        if(i >= '0' && i <= '9') cnt++;

    //cout << cnt << ' ' << 100 - cnt << endl;

    ULL ans = 0;
    for(int i = 7;i <= 15;i++) ans += c[88][i];
    for(int i = 1;i <= 11;i++)
    {
        if(i < 7)
        {
            for(int j = 7 - i;j <= 15 - i;j++) ans += c[11][i] * c[88][j];
        }else{
            ans += c[11][i];
            for(int j = 1;j <= 15 - i;j++) ans += c[11][i] * c[88][j];
        }
    }

    cout << ans * cnt << endl;
}

int main()
{
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
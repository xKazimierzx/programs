#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define debug(x) cout << x << endl
#define cy puts("Yes")
#define cn puts("No")
#define lowbit(x) (x & (-x))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rep_(i,a,b) for(int i=a;i>=b;i--)
#define endl '\n'

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef pair<double,double> PDD;
typedef pair<double,PDD> PDDD;

const int N = 2010;
const int MOD = 1e9 + 7;
const double PI = acos(-1);
const double EPS = 1e-8;

LL C[N][N];

void init()
{
    for(int i = 0;i <= 2000;i++)
        for(int j = 0;j <= i;j++)
            if(!j) C[i][j] = 1;
            else C[i][j] = (C[i-1][j] + C[i-1][j-1] + MOD) % MOD;
}

void solve()
{
    LL a,b;
    cin >> a >> b;
    cout << C[a][b] % MOD << endl;
}

int main()
{
    init();
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
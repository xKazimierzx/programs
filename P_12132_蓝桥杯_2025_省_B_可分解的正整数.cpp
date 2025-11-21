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
    set<int> h;
    for(int j = 3;j <= 1000;j++)
    {
        
        for(int i = -1000;i <= 1000;i++)
        {
            int res = 0;
            for(int k = 0;k < j;k++) res += i + k;
            h.insert(res);
        }
    }
    
    for(int i = 0;i <= 1000;i++)
        if(h.find(i) != h.end()) cy;
        else cn;
}

int main()
{
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
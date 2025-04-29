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
    vector<int> a(3);
    int res = 0;
    for(int i = 0;i < 3;i++) cin >> a[i],res += a[i];
    
    if(res % 3)
    {
        cn;
        return;
    }

    res /= 3;
    for(int i = 0;i < 2;i++)
        if(a[i] > res)
        {
            cn;
            return;
        }
        else if(a[i] == res) continue;
        else if(a[i] < res)
        {
            if(a[2] > res - a[i]) a[2] -= (res - a[i]);
            else
            {
                cn;
                return;
            }
        }
        
    cy;
}

int main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define cy puts("YES")
#define cn puts("NO")
#define cz puts("0")
#define co puts("1")

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<double, double> PDD;
typedef pair<int, int> PII;

using namespace std;

void solve()
{
    int n;
    cin >> n;
    
    ULL res = 0;
    for (int i = 0; i < n; i ++ )
    {
        ULL x;
        cin >> x;
        res += x;
    }
    
    if((ULL)sqrtl(res) * (ULL)sqrtl(res) == res) cy;
    else cn;
}

int main()
{
    int T;
    cin>>T;
    while(T--) solve();
    return 0;   
}
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve()
{
    int n;
    cin >> n;
    
    LL sum = 0,cnt = 0;
    for (int i = 1; i <= n; i ++ )
    {
        LL x;
        cin >> x;
        
        sum += x;
        if(x & 1) cnt++;
        
        LL res = sum;
        LL odd = cnt;
        if(i > 1)
        {
            res -= (odd / 3);
            odd %= 3;
            if(odd == 1) res--;
        }
        
        cout << res << ' ';
    }
    
    puts("");
}

int main()
{
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
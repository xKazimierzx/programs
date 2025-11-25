#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void solve()
{
    int n,len;
    cin >> n;
    len = n;
    vector<LL> a(n+1);
    LL res = 0;
    for(int i = 1;i <= n;i++) cin >> a[i],res += a[i];
    if(n > 1) res = max(res,max(a[1] - a[len],a[len] - a[1]));
    for(int k = 0;k < n-1;k++)
    {
        if(a[1] > a[len]) reverse(a.begin()+1,a.begin()+1+len);
        for(int i = 1;i < len;i++) a[i] = a[i+1] - a[i];
        len--;
        if(len > 1) res = max(res,a[len] - a[1]);
        else res = max(res,a[len]);
    }
    cout << res << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
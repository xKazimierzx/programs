#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
vector<LL> s(N,0);

void solve()
{
    int n,k;
    LL x;
    cin>>n>>k>>x;
    
    if(x < s[k] || x > s[n] || s[n] - s[n-k] < x)
    {
        puts("NO");
        return;
    }
    
    puts("YES");
}
int main()
{
    for(int i = 1;i <= N; i++) s[i] = s[i-1] + i;
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
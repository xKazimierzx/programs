#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
typedef pair<PII,int> PIII;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i = 1;i <= n; i++) cin>>a[i];
    
    vector<PIII> ans;
    ans.push_back({{1,n},899999});
    for(int j = 1;j <= n; j++)
        a[j] += 899999;
        
    for(int i = 1;i <= n; i++)
    {
        ans.push_back({{2,i},a[i] - i + 1});
        for(int j = 1;j <= i; j++) a[j] %= (a[i] - i + 1);
    }
    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
}

int main()
{
    int T = 1;
    //cin>>T;
    while(T--) solve();
    return 0;
}
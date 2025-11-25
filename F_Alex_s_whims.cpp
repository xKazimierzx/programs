#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,q;
    cin>>n>>q;
   
    for(int i = 1;i + 1 <= n ;i++) cout<<i<<" "<<i+1<<endl;

    int last = n - 1,dis = n;
    for(int i = 1;i <= q; i++)
    {
        int x;
        cin>>x;
        cout<<n<<" "<<last<<" "<<x<<endl;
        last = x;
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
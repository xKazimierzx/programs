#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int n,m;

void solve()
{
    cin>>n>>m;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    
    for(int i = 1;i <= n; i++)
        for(int j = 1;j <= m; j++) cin>>a[i][j];
    
    int ans = 0;
    for(int i = 1;i <= n; i++)
        for(int j = 1;j <= m; j++)
        {
            int t = a[i][j];
            for(int k = 1;k <= max(n,m); k++)
                if(i - k <= 0 || j - k <= 0) break;
                else t += a[i-k][j-k];
                
            for(int k = 1;k <= max(n,m); k++)
                if(i - k <= 0 || j + k > m) break;
                else t += a[i-k][j+k];
                
            for(int k = 1;k <= max(n,m); k++)
                if(i + k > n || j + k > m) break;
                else t += a[i+k][j+k];
                
            for(int k = 1;k <= max(n,m); k++)
                if(i + k > n || j - k <= 0) break;
                else t += a[i+k][j-k];
            
            ans = max(ans,t);
        }
    cout<<ans<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
				  	  	 	 		  	  	  	 	 	 		
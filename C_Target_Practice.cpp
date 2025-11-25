#include <bits/stdc++.h>
using namespace std;

const int N = 15;

void solve()
{
    int ans = 0,n = 10;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
             char c;
             cin>>c;
             
             if(i==1&&c=='X') ans += 1;
             else if(j==1&&i!=1&&i!=n&&c=='X') ans += 1;
             else if(j==n&&i!=1&&i!=n&&c=='X') ans += 1;
             else if(i==n&&c=='X') ans += 1;
             
             if(i==2&&j!=1&&j!=n&&c=='X') ans += 2;
             else if(j==2&&i!=1&&i!=n&&i!=2&&i!=n-1&&c=='X') ans += 2;
             else if(j==n-1&&i!=1&&i!=n&&i!=2&&i!=n-1&&c=='X') ans += 2;
             else if(i==n-1&&j!=1&&j!=n&&c=='X') ans += 2;
             
             if(i==3&&j!=1&&j!=n&&j!=2&&j!=n-1&&c=='X') ans += 3;
             else if(j==3&&i!=1&&i!=n&&i!=2&&i!=n-1&&i!=3&&i!=n-2&&c=='X') ans += 3;
             else if(j==n-2&&i!=1&&i!=n&&i!=2&&i!=n-1&&i!=3&&i!=n-2&&c=='X') ans += 3;
             else if(i==n-2&&j!=1&&j!=n&&j!=2&&j!=n-1&&c=='X') ans += 3;
             
             if(i==4&&j!=1&&j!=n&&j!=2&&j!=n-1&&j!=3&&j!=n-2&&c=='X') ans += 4;
             else if(j==4&&i!=1&&i!=n&&i!=2&&i!=n-1&&i!=3&&i!=n-2&&i!=4&&i!=n-3&&c=='X') ans += 4;
             else if(j==n-3&&i!=1&&i!=n&&i!=2&&i!=n-1&&i!=3&&i!=n-2&&i!=4&&i!=n-3&&c=='X') ans += 4;
             else if(i==n-3&&j!=1&&j!=n&&j!=2&&j!=n-1&&j!=3&&j!=n-2&&c=='X') ans += 4;
             
             if(i==5&&j==5&&c=='X') ans += 5;
             else if(i==5&&j==6&&c=='X') ans += 5;
             else if(i==6&&j==5&&c=='X') ans += 5;
             else if(i==6&&j==6&&c=='X') ans += 5;

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
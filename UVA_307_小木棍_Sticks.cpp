#include <bits/stdc++.h>
using namespace std;

const int N = 70;
int a[N],g[N],n,sum=0,len=0;
bool st[N];

bool dfs(int u,int s,int start)
{
    if(len*u==sum) return true;
    if(s==len) return dfs(u+1,0,0);
    
    for(int i=start;i<n;i++)
        if(s+a[i]<=len&&!st[i])
        {
            st[i] = true;
            if(dfs(u,s+a[i],i+1)) return true;
            st[i] = false;
            if(!s) return false;
            if (s + a[i] == len) return false;
            int j = i;
            while (j < n && a[i] == a[j]) j ++ ;
            i = j - 1;
        }
    
    return false;
}

int main()
{
    while(cin>>n,n)
    {
        memset(st,false,sizeof st);
        sum = 0;
        for(int i=0;i<n;i++) cin>>a[i],sum += a[i];
        sort(a,a+n);
        reverse(a,a+n);
        for(int i=1;i<=sum;i++)
            if(sum%i==0)
            {
                len = i;
                if(dfs(0,0,0))
                {
                    cout<<i<<endl;
                    break;
                }
            }
    }
}
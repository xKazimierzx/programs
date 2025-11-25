#include <bits/stdc++.h>
using namespace std;

const int N = 10050;
int a[N],n,depth;

bool dfs(int u,int depth)
{
    if(a[u-1]*(1<<(depth-u+1))<n) return false;
    if(u==depth) return a[u-1]==n;
    
    bool st[2*N] = {0};
    for(int i=u-1;i>=0;i--)
        for(int j=i;j>=0;j--)
        {
            int t = a[i] + a[j];
            if(t<=a[u-1]) return false;
            if(st[t]||t>n) continue;
            st[t] = true;
            a[u] = t;
            if(dfs(u+1,depth)) return true;
        }
    
    return false;
}

int main()
{
    while(cin>>n,n)
    {
        a[0] = 1,depth = 1;
        while(!dfs(1,depth)) depth++;
        for(int i=0;i<depth;i++)
            if(i!=depth-1) cout<<a[i]<<" ";
            else cout<<a[i];
        puts("");
    }
    return 0;
}
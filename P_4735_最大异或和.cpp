#include <bits/stdc++.h>
using namespace std;

const int N = 6e5 + 10;
int s[N],n,m;
int son[N*25][2],root[N],idx,max_id[N*25];

void insert(int i,int k,int p,int q)
{
    if(k < 0)
    {
        max_id[q] = i;
        return;
    }
    
    int u = (s[i] >> k) & 1;
    if(p) son[q][!u] = son[p][!u];
    son[q][u] = ++idx;
    insert(i,k-1,son[p][u],son[q][u]);
    max_id[q] = max(max_id[son[q][0]],max_id[son[q][1]]); 
}

int query(int l,int r,int x)
{
    int p = root[r];
    for(int i=25;i>=0;i--)
    {
        int u = (x >> i) & 1;
        if(max_id[son[p][!u]]>=l) p = son[p][!u];
        else p = son[p][u];
    }
    return x ^ s[max_id[p]];
}

int main()
{
    cin>>n>>m;
    
    max_id[0] = -1;
    root[0] = ++idx;
    insert(0,25,0,root[0]);
    
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        s[i] = s[i-1] ^ x;
        root[i] = ++idx;
        insert(i,25,root[i-1],root[i]);
    }
    
    while(m--)
    {
        char op;
        cin>>op;
        if(op=='A')
        {
            int x;
            cin>>x;
            n++;
            s[n] = s[n-1] ^ x;
            root[n] = ++idx;
            insert(n,25,root[n-1],root[n]);
        }
        else
        {
            int l,r,x;
            cin>>l>>r>>x;
            cout<<query(l-1,r-1,s[n]^x)<<endl;
        }
    }
    return 0;
}
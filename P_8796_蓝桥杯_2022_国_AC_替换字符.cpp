#include <bits/stdc++.h>
#define ls u<<1
#define rs u<<1|1
using namespace std;

const int N = 1e5 + 10,K = 26;
char s[N];
struct Node
{
    int l,r;
    char lazy[K],val;
}tr[4*N];
int n;

void build(int u,int l,int r)
{
    for(int i=0;i<K;i++) tr[u].lazy[i] = i + 'a';
    tr[u].l = l,tr[u].r = r;
    if(l==r)
    {
        tr[u].val = s[l];
        return;
    }
    int mid = l + r >> 1;
    build(ls,l,mid),build(rs,mid+1,r);
}

void pushdown(int u)
{
    for(int i=0;i<K;i++) tr[ls].lazy[i] = tr[u].lazy[tr[ls].lazy[i]-'a'];
    for(int i=0;i<K;i++) tr[rs].lazy[i] = tr[u].lazy[tr[rs].lazy[i]-'a'];
    for(int i=0;i<K;i++) tr[u].lazy[i] = i + 'a';
}

void modify(int u,int l,int r,char x,char y)
{
    if(tr[u].l>=l&&tr[u].r<=r)
    {
        for(int i=0;i<K;i++)
            if(tr[u].lazy[i]==x) tr[u].lazy[i] = y;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(l<=mid) modify(ls,l,r,x,y);
    if(r>mid) modify(rs,l,r,x,y); 
}

void Print(int u,int l,int r)
{
    if(l==r)
    {
        cout<<tr[u].lazy[tr[u].val-'a'];
        return;
    }
    pushdown(u);
    int mid = l + r >> 1;
    Print(ls,l,mid),Print(rs,mid+1,r);
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>s+1;
    n = strlen(s+1);
    build(1,1,n);
    
    int m;
    cin>>m;
    while(m--)
    {
        int l,r;
        char x,y;
        cin>>l>>r>>x>>y;
        modify(1,l,r,x,y);
    }
    Print(1,1,n);
    return 0;
}
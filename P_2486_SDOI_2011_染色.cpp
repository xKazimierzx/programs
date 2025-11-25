#include <bits/stdc++.h>
#define ls u<<1
#define rs u<<1|1
using namespace std;

const int N = 1e5 + 10,M = 2 * N;
int h[N],e[M],ne[M],idx;
int w[N],son[N],fa[N],id[N],nw[N],d[N],top[N],sz[N],cnt;
int n,m,lc,rc;

struct Node
{
    int l,r;
    int lc,rc,v,c;
}tr[4*N];

void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void pushup(int u)
{
    tr[u].v = tr[ls].v + tr[rs].v;
    if(tr[ls].rc==tr[rs].lc) tr[u].v--;
    tr[u].lc = tr[ls].lc,tr[u].rc = tr[rs].rc;
}

void pushdown(int u)
{
    Node &root = tr[u],&left = tr[ls],&right = tr[rs];
    if(root.c)
    {
        left.c = root.c,left.lc = root.c,left.rc = root.c,left.v = 1;
        right.c = root.c,right.lc = root.c,right.rc = root.c,right.v = 1;
        root.c = 0;
    }
}

void build(int u,int l,int r)
{
    tr[u].l = l,tr[u].r = r;
    if(l==r)
    {
        tr[u].lc = tr[u].rc = nw[l];
        tr[u].v = 1;
        return;
    }
    int mid = l + r >> 1;
    build(ls,l,mid),build(rs,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int c)
{
    if(tr[u].l>=l&&tr[u].r<=r)
    {
        tr[u].c = tr[u].lc = tr[u].rc = c;
        tr[u].v = 1;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(l<=mid) modify(ls,l,r,c);
    if(r>mid) modify(rs,l,r,c);
    pushup(u);
}

int query(int u,int l,int r)
{
    if(tr[u].l>=l&&tr[u].r<=r)
    {
        if(tr[u].l==l) lc = tr[u].lc;
        if(tr[u].r==r) rc = tr[u].rc;
        return tr[u].v;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(r<=mid) return query(ls,l,r);
    if(l>mid) return query(rs,l,r);
    int res = query(ls,l,r) + query(rs,l,r);
    if(tr[ls].rc==tr[rs].lc) res--;
    return res;
}

void dfs1(int u,int father,int depth)
{
    fa[u] = father,d[u] = depth,sz[u] = 1;
    for(int i=h[u];~i;i=ne[i])
    {
        int j = e[i];
        if(j==father) continue;
        dfs1(j,u,depth+1);
        sz[u] += sz[j];
        if(sz[son[u]] < sz[j]) son[u] = j;
    }
}

void dfs2(int u,int t)
{
    id[u] = ++cnt,nw[cnt] = w[u],top[u] = t;
    if(!son[u]) return;
    dfs2(son[u],t);
    for(int i=h[u];~i;i=ne[i])
    {
        int j = e[i];
        if(j==fa[u]||j==son[u]) continue;
        dfs2(j,j);
    }
}

void update_path(int u,int v,int c)
{
    while(top[u]!=top[v])
    {
        if(d[top[u]] < d[top[v]]) swap(u,v);
        modify(1,id[top[u]],id[u],c);
        u = fa[top[u]];
    }
    if(id[u] > id[v]) swap(u,v);
    modify(1,id[u],id[v],c);
}

int query_path(int u,int v)
{
    int res = 0,pos1 = 0,pos2 = 0;
    while(top[u]!=top[v])
    {
        if(d[top[u]] < d[top[v]]) swap(u,v),swap(pos1,pos2);
        res += query(1,id[top[u]],id[u]);
        if(pos1==rc) res--;
        u = fa[top[u]],pos1 = lc;
    }
    if(id[u] > id[v]) swap(u,v),swap(pos1,pos2);
    res += query(1,id[u],id[v]);
    if(pos1==lc) res--;
    if(pos2==rc) res--;
    return res;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    
    memset(h,-1,sizeof h);   
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    
    dfs1(1,-1,1); //求深度，重儿子，父节点
    dfs2(1,1); //求dfs序同时记录每条链的起点
    
    build(1,1,n);
    
    while(m--)
    {
        char op[2];
        cin>>op;
        if(op[0]=='C')
        {
            int l,r,c;
            cin>>l>>r>>c;
            update_path(l,r,c);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<query_path(l,r)<<endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e5 + 10;

int a[N];
struct Node
{
    int l, r;
    int sum;
}tr[N * 4];

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum & tr[u << 1 | 1].sum;
}

void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, a[l]};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

    int mid = tr[u].l + tr[u].r >> 1;
    int sum = (1 << 31) - 1;
    if (l <= mid) sum = query(u << 1, l, r);
    if (r > mid) sum &= query(u << 1 | 1, l, r);
    return sum;
}

void solve()
{
    memset(a,0,sizeof a);
    int n;
    cin>>n;
    
    for(int i = 1;i <= n; i++) cin>>a[i];
    build(1,1,n);
    
    int q;
    cin>>q;
    while(q--)
    {
        int ll;
        LL k;
        cin>>ll>>k;
        
        if(query(1,ll,ll) < k)
        {
            cout<<-1<<" ";
            continue;
        }
        
        int l = 1,r = n;
        while(r > l)
        {
            int mid = l + r + 1 >> 1;
            if(query(1,ll,mid) >= k) l = mid;
            else r = mid - 1;
        }
        
        cout<<l<<" ";
    }
    puts("");
}

int main()
{
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
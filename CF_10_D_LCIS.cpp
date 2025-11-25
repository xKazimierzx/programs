#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define bp(x) __builtin_poptount(x)
#define bpll(x) __builtin_poptountll(x)
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define rep_(i,a,b) for(int i = a;i >= b;--i)
#define debug(x) cout << x << '\n'
#define cy cout << "Yes" << '\n'
#define cn cout << "No" << '\n'
#define x first
#define y second

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef pair<double,double> PDD;
typedef pair<double,PDD> PDDD;

const int N = 3e5 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;
const int DEP = 31;

int a[N],b[N],n,f[N][N],m,pre[N][N];

void solve()
{
    memset(pre,-1,sizeof pre);
    cin>>n;
    for(int i = 1;i <= n; i++) cin>>a[i];
    cin>>m;
    for(int i = 1;i <= m; i++) cin>>b[i];
    
    for(int i = 1;i <= n; i++)
    {
        int maxv = 1,idx = -1;
        for(int j = 1;j <= m; j++)
        {
            if(b[j] < a[i] && maxv < f[i-1][j]+1)
            {
                maxv = f[i-1][j]+1;
                idx = j;
            }
            if(a[i]!=b[j])
            {
                f[i][j] = f[i-1][j];
                pre[i][j] = pre[i-1][j];
            }
            else{
                f[i][j] = maxv;
                pre[i][j] = idx;
            }
        }
    }
    
    int ans = 0,idx = 0;
    for(int i = 1;i <= m; i++)
        if(ans < f[n][i])
        {
            ans = f[n][i];
            idx = i;
        }
    
    stack<int> h;
    for(; ~idx ;idx = pre[n][idx]) h.push(b[idx]);
    cout<<ans<<endl;
    if(!ans) return 0;
    while(h.size())
    {
        cout<<h.top()<<" ";
        h.pop();
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
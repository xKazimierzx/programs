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

const int N = 1e5 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;
const int DEP = 31;

int tree[N];
int root = 1,n,m;

int findFather(int u)
{
    if(u == 1) return -1;
    return tree[u >> 1];
}

int getLeft(int u)
{
    return tree[u << 1];
}

int getRight(int u)
{
    return tree[u << 1 | 1];
}

void preOrder(int u)
{
    if(u > n) return;
    cout << tree[u] << ' ';
    preOrder(u << 1);
    preOrder(u << 1 | 1);
}

void midOrder(int u)
{
    if(u > n) return;
    midOrder(u << 1);
    cout << tree[u] << ' ';
    midOrder(u << 1 | 1);
}

void postOrder(int u)
{
    if(u > n) return;
    postOrder(u << 1);
    postOrder(u << 1 | 1);
    cout << tree[u] << ' ';
}

void solve()
{
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> tree[i];
    preOrder(root); cout << endl;
    midOrder(root); cout << endl;
    postOrder(root); cout << endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
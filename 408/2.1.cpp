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

int a[N];
int top = -1;
int n,m;

bool isEmpty()
{
    if(top == -1) return true;
    return false;
}

bool isFull()
{
    if(top == n - 1) return true;
    return false;
}

bool push(int x)
{
    if(isFull()) return false;
    a[++top] = x;
    return true;
}

int pop()
{
    if(!isEmpty()) return a[top--];
}

void solve()
{
    cin >> n >> m;
    while(m--)
    {
        string op;
        cin >> op;

        if(op == "push")
        {
            int x;
            cin >> x;
            push(x);
        }
        else if(op == "pop")
        {
            pop();
        }
        else if(op == "empty")
        {
            cout << isEmpty() << endl;
        }
        else if(op == "full")
        {
            cout << isFull() << endl;
        }
    }

    for(int i = 0;i <= top;i++) cout << a[i] << ' ';
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
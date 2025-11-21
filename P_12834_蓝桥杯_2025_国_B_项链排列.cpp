#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define bp(x) __builtin_poptount(x)
#define bpll(x) __builtin_poptountll(x)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rep_(i,a,b) for(int i=a;i>=b;i--)
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

void solve()
{
    int a,b,c;
    cin >> a >> b >> c;

    int n = a + b;
    if(c > n - 1) 
    {
        cout << -1 << endl;
        return;
    }
    
    if(c == n - 1)
    {
        if(a >= b)
        {
            for(int i = 0;i < n;i++)
                if(i & 1) cout << 'Q';
                else cout << 'L';
            cout << endl;
            return;
        }else{
            for(int i = 0;i < n;i++)
                if(i & 1) cout << 'L';
                else cout << 'Q';
            cout << endl;
            return;
        }
    }else{
        if(a >= b)
        {
            for(int i = 0;i < c - 1;i++)
                if(i & 1) cout << 'Q',b--;
                else cout << 'L',a--;
            if(n & 1)
            {
                while(a--) cout << 'L';
                while(b--) cout << 'Q';
            }else{
                while(b--) cout << 'Q';
                while(a--) cout << 'L';
            }
            cout << endl;
            return;
        }else{
            string ss = "";
            for(int i = 0;i < c - 1;i++)
                if(i & 1) ss += 'L',a--;
                else ss += 'Q',b--;
            if(n % 2 == 0)
            {
                while(a--) ss += 'L';
                while(b--) ss += 'Q';
            }else{
                while(b--) ss += 'Q';
                while(a--) ss += 'L';
            }
            cout << ss << endl;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
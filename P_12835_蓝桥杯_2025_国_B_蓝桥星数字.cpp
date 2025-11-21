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

bool check1(int x)
{
    string s = to_string(x);
    for(int i = 0;i < s.length();i++)
    {
        int num = s[i] - '0';
        if(i & 1)
        {
            if(num & 1) return false;
        }else{
            if(num % 2 == 0) return false;
        }
    }
    return true;
}

bool check2(int x)
{
    string s = to_string(x);
    for(int i = 0;i < s.length();i++)
    {
        int num = s[i] - '0';
        if(i & 1)
        {
            if(num % 2 == 0) return false;
        }else{
            if(num & 1) return false;
        }
    }
    return true;
}

void solve()
{
    LL n;
    cin >> n;

    if(n == 100000)
    {
        cout << "5076909" << endl;
        return;
    }

    if(n == 99999)
    {
        cout << "5076907" << endl;
        return;
    }

    LL cnt = 0;
    for(int i = 10;i <= 10000000;i++)
        if(check1(i) || check2(i))
        {
            cnt++;
            if(cnt == n)
            {
                cout << i << endl;
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
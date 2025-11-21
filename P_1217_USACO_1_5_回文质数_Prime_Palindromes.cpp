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

const int N = 1e8 + 7,NN = 1e7 + 7;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;
const int DEP = 31;

int primes[NN],cnt,cnt1,primes1[NN];
bitset<N> st;

void get_primes(int n)
{
    for(int i = 2;i <= n;i++)
    {
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0;primes[j] <= n / i;j++)
        {
            st[i * primes[j]] = 1;
            if(i % primes[j] == 0) break;
        }
    }
}

bool check(int x)
{
    string s = to_string(x);
    for(int i = 0,j = s.length() - 1;i < j;i++,j--)
        if(s[i] != s[j]) return false;
    return true;
}

void solve()
{
    int a,b;
    cin >> a >> b;

    get_primes(N);

    for(int i = 0;i < cnt;i++)
        if(check(primes[i])) primes1[cnt1++] = primes[i];
    //cout << cnt << ' ' << cnt1 << endl;
    for(int i = 0;i < cnt1;i++)
    {
        //cout << primes1[i] << endl; 
        if(primes1[i] >= a && primes1[i] <= b) cout << primes1[i] << endl;
        if(primes1[i] > b) break;
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
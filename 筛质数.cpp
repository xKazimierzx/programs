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

const int N = 1e6 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;

vector<int> primes;
bool is_prime[N];

void get_primes(int n)
{
    for(int i = 2;i <= n;i++)
    {
        if(!is_prime[i]) primes.push_back(i);
        for(int j = 0;primes[j] <= n / i;j++)
        {
            is_prime[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    get_primes(n);
    cout << primes.size() << endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define debug(x) cout << x << endl
#define cy puts("YES")
#define cn puts("NO")
#define lowbit(x) (x & (-x))
#define endl '\n'

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<PII,int> PIII;
typedef pair<double,double> PDD;
typedef pair<PDD,double> PDDD;

const int N = 1e7 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;

LL primes[N];
int cnt;
bool st[N];

void get_primes(int n)
{
    for(int i = 2;i <= n;i++)
    {
        if(!st[i]) primes[++cnt] = i;
        for(int j = 1;primes[j] <= n / i;j++)
        {
            st[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
    for(int i = 1;i <= cnt;i++) primes[i] += primes[i - 1];
}

void solve()
{
    int n;
    cin >> n;
    vector<LL> a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a.begin() + 1,a.end(),greater<int>());
    for(int i = 1;i <= n;i++) a[i] += a[i-1];

    int l = 0,r = n;
    while(r > l)
    {
        int mid = l + r + 1 >> 1;
        if(a[mid] >= primes[mid]) l = mid;
        else r = mid - 1;
    }

    cout << n - l << endl;
}

int main()
{
    get_primes(N - 1);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
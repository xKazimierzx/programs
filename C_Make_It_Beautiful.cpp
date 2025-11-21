#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define debug(x) cout << x << endl
#define cy puts("Yes")
#define cn puts("No")
#define lowbit(x) (x & (-x))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rep_(i,a,b) for(int i=a;i>=b;i--)
#define endl '\n'

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<PII,int> PIII;
typedef pair<double,double> PDD;
typedef pair<PDD,double> PDDD;

const int N = 1e5 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;

void solve()
{
    int n;
	LL k;
	cin >> n >> k;

	vector<LL> a(62,0);
	rep(i,0,n-1)
    {
		LL t;
		cin >> t;
		rep(j,0,61)
            if((t >> j) & 1) a[j]++;
	}

	rep(i,0,61)
    {
		LL t = min(n - a[i], k >> i);
		a[i] += t;
		k -= (t << i);
	}

	LL ans = 0;
	for(LL x : a) ans += x;
	cout << ans << endl;
}

int main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define endl '\n'
#define debug(x) cout << #x << "=" << x << endl;

typedef long long LL;
typedef pair<int,int> PII;

const double PI = acos(-1);
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10,M = 2*N;
const int MOD = 1e9 + 7;
const double eps = 1e-8;

void solve()
{
	LL n,x,a,b;
	cin >> n >> x >> a >> b;
	cout << x * b + (n-x) * a << endl;
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
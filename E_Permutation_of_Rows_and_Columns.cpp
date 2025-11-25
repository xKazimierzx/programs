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
	int n,m;
	cin >> n >> m;

	vector<vector<int>> a(n+1,vector<int>(m+1)); 
	vector<vector<int>> b(n+1,vector<int>(m+1)); 

	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) cin >> a[i][j];

	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) cin >> b[i][j];
	
	set<int> s;
	map<set<int>,int> h1,h2;
	for(int i = 1;i <= n;i++)
	{
		s.clear();
		for(int j = 1;j <= m;j++) s.insert(a[i][j]);
		h1[s]++;
	}

	for(int i = 1;i <= m;i++)
	{
		s.clear();
		for(int j = 1;j <= n;j++) s.insert(a[j][i]);
		h2[s]++;
	}
	
	for(int i = 1;i <= n;i++)
	{
		s.clear();
		for(int j = 1;j <=m;j++) s.insert(b[i][j]);
		if(!h1[s])
		{
			cout << "NO" << '\n'; 
			return;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		s.clear();
		for(int j = 1;j <=n;j++) s.insert(b[j][i]);
		if(!h2[s])
		{
			cout << "NO" << '\n'; 
			return;
		}
	}
	cout << "YES" << '\n';
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
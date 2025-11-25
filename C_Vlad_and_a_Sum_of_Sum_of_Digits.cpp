#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2e5 + 10;
LL ans[N];

void solve()
{
	int n;
	cin >> n;
	cout << ans[n] << endl;
}

int main()
{
	int T;
	cin >> T;
	
	for(int i = 1;i <= N - 9;i++)
	{
		int t = i;
		LL res = 0;
		while(t) res += (t%10),t /= 10;
		ans[i] = ans[i-1] + res;	
	}
	
	while(T--) solve();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
//
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

LL gcd(LL a,LL b)
{
	return b?gcd(b,a%b):a;
}

LL lcm(LL a,LL b)
{
	return a * b / gcd(a,b);
}

void solve()
{
	LL a,b;
	cin >> a >> b;
	if(a == b)
	{
		cout << "0" << '\n'; 
		return;
	}
	if(gcd(a,b) != 1 && gcd(a,b) != a && gcd(a,b) != b)
	{
		cout << a + b << endl;
		return;
	}
	LL x = 2,y = 2;
	for(int i = 2;i <= a/i;i++)
		if(a % i==0)
		{
			x = i;
			break;
		}
	for(int i = 2;i <= b/i;i++)
		if(b % i==0)
		{
			y = i;
			break;
		}
	LL t1 = lcm(a,b);
	LL t2 = lcm(a,x) + lcm(x,2) + lcm(2,y) + lcm(y,b);
	LL t3 = lcm(a,x) + lcm(x,2) + lcm(2,b);
	LL t4 = lcm(a,x) + lcm(x,b);
	LL t5 = lcm(a,y) + lcm(y,b);
	LL t6 = lcm(a,y) + lcm(y,2) + lcm(2,b);
	LL t7 = lcm(a,x) + lcm(x,y) + lcm(y,b);

	LL ans = min({t1,t2,t3,t4,t5,t6,t7});
	cout << ans << endl;

}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
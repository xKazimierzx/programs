// Problem: C. Heavy Intervals
// Contest: Codeforces - Pinely Round 3 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1909/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define x first
#define y second 
#define endl '\n'
#define int long long
const LL maxn = 4e05+7;
const LL N = 5e05+10;
const LL mod = 1e09+7;
const int inf = 0x3f3f3f3f;
const LL llinf = 5e18;
typedef pair<int,int>pl;
priority_queue<LL , vector<LL>, greater<LL> >mi;//小根堆
priority_queue<LL> ma;//大根堆
LL gcd(LL a, LL b){
	return b > 0 ? gcd(b , a % b) : a;
}
 
LL lcm(LL a , LL b){
	return a / gcd(a , b) * b;
}
int n , m;
vector<int>a(N , 0);
void init(int n){
	for(int i = 0 ; i <= n ; i ++){
		a[i] = 0;
	}
}
void solve() 
{
	cin >> n;
	int l[n] , r[n] , c[n];
	for(int i = 0 ; i < n ; i ++)
		cin >> l[i];
	for(int i = 0 ; i < n ; i ++)
		cin >> r[i];
	for(int i = 0 ; i < n ; i ++)
		cin >> c[i];
	sort(c , c + n);
	sort(l , l + n);
	sort(r , r + n);
	int pre[n];
	stack<int>st;
	int ll = 0;
	int ans = 0;
	for(int i = 0 ; i < n ;i ++){
		while(ll < n && r[i] >= l[ll]){
			
			st.push(l[ll]);
			ll++;
		}
		int x = st.top();
		st.pop();
		pre[i] = r[i] - x;
	} 	
	sort(pre , pre + n);
	for(int i = 0 ; i < n ; i ++){
		ans += pre[i] * c[n - i - 1];
	}
	cout << ans << endl;
}            
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    int t=1;
	cin>>t;
    while(t--)
    {
    	solve();
    }
    return 0;
}
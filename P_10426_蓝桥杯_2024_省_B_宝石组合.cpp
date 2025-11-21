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
typedef pair<int,PII> PIII;
typedef pair<double,double> PDD;
typedef pair<double,PDD> PDDD;

const int N = 1e5 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;

int n;
map<int,int> p;

void init(int x)
{
    for(int i = 1;i <= x / i;i++)
        if(x % i == 0)
        {
            p[i]++;
            if(i != x / i) p[x / i]++;
        }
}

void solve()
{
    cin >> n;
    vector<int> a(n);
    int res = 0;
    for(int i = 0;i < n;i++) cin >> a[i],res = max(res,a[i]);
    sort(a.begin(),a.end());
    for(int i = 0;i < n;i++) init(a[i]);

    int tmp = 0;
    for(int i = res;i >= 1;i--)
        if(p[i] >= 3)
        {
            tmp = i;
            break;
        }

    for(int i = 0,cnt = 0;i < n && cnt < 3;i++)
        if(a[i] % tmp == 0)
        {
            cout << a[i] << ' ';
            cnt++;
        }
}

int main()
{
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
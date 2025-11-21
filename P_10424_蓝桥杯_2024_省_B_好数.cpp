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

bool check(int x)
{
    string s = to_string(x);
    int cnt = 1;
    rep_(i,s.size()-1,0)
    {
        int num = s[i] - '0';
        if(cnt & 1)
        {
            if(num % 2 == 0) return false;
        }else{
            if(num & 1) return false;
        }
        cnt++;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    int ans = 0 ;
    rep(i,1,n)
        if(check(i)) ans++;
    cout << ans << endl;
}

int main()
{
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
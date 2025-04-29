#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define debug(x) cout << x << endl
#define cy puts("Yes")
#define cn puts("No")
#define lowbit(x) (x & (-x))
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
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    //for(int i = n;i >= 1;i--) cout << suf[i] << ' ';

    int ans = 0,sum = 0;
    for(int i = 1,j = 1;i <= n;i++)
    {
        while(j <= n)
        {
            sum += a[j];
            if(sum <= k) j++;   
            else{
                sum -= a[j];
                break;
            }
        }
        sum -= a[i];
        ans = max(ans,j - i);
    }

    cout << ans << endl;
}

int main()
{
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
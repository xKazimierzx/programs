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
    int n;
    LL k;
    cin >> n >> k;

    vector<LL> a(n + 1),b(n + 1);
    LL sumA = 0;
    for(int i = 1;i <= n;i++) cin >> a[i],sumA += a[i];

    for(int i = 1;i <= n;i++) cin >> b[i];

    LL last = -2;
    for(int i = 1;i <= n;i++)
    {
        if(b[i] != -1 && last != -2 && a[i] + b[i] != last)
        {
            cout << 0 << endl;
            return;
        }
        else if(b[i] != -1) last = a[i] + b[i];
    }

    if(last != -2)
    {
        for(int i = 1;i <= n;i++)
            if(b[i] == -1) 
            {
                if(last - a[i] < 0 || last - a[i] > k)
                {
                    cout << 0 << endl;
                    return;
                } 
            }
        cout << 1 << endl;
        return;
    }

    LL minv = *min_element(a.begin() + 1,a.end());
    LL maxv = *max_element(a.begin() + 1,a.end());
    cout << minv + k - maxv + 1 << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
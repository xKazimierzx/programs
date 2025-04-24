#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define debug(x) cout << x << endl
#define cy puts("Yes")
#define cn puts("No")
#define lowbit(x) (x & (-x))

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
    cin >> n;
    string s;
    cin >> s;
    
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        string t = s;

        if(s[i] == '0') s[i] = '1';
        else if(s[i] == '1') s[i] = '0';

        for(auto j:s)
            if(j == '1') ans++;
        s = t;
    }

    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
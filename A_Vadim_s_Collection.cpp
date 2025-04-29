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
    string s;
    cin >> s;

    int n = s.length();
    map<char,int> h;
    for(auto i:s) h[i]++;

    for(int i = 0;i < n;i++)
    {
        for(int j = 9 - i;j <= 9;j++)
            if(h[j + '0'])
            {
                s[i] = j + '0',h[j + '0']--;
                break;
            }
    }
    cout << s << endl;
}

int main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
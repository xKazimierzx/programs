#include <bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define debug(x) cout << x << endl
#define cy puts("YES")
#define cn puts("NO")
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
    stack<int> st;
    vector<int> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            if (st.top() == i - 1)
            {
                v.push_back(1);
            }
            else
                v.push_back(2);
            st.pop();
        }
    }
    reverse(v.begin(), v.end());
    int ans = 1, cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        cnt++;
        if (v[i] == 2)
        {
            ans = ans * cnt % MOD;
        }
    }
    cout << ans << '\n';
}

signed main()
{
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
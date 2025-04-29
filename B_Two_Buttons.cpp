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
    int n,m;
    cin >> n >> m;
    
    if(n >= m)
    {
        cout << n - m << endl;
        return;
    }

    queue<int> q;
    vector<bool> st(20010,false);
    vector<int> dis(20010,0);
    q.push(n);
    st[n] = true;
    while(q.size())
    {
        auto now = q.front();
        q.pop();

        if(now == m)
        {
            cout << dis[now] << endl;
            return;
        }

        if(!st[now * 2] && now * 2 <= 2 * m) q.push(now * 2),st[now * 2] = true,dis[now * 2] = dis[now] + 1;
        if(now - 1 >= 1 && !st[now - 1]) q.push(now - 1),st[now - 1] = true,dis[now - 1] = dis[now] + 1;
    }
}

int main()
{
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
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
    cin >> n;

    set<PDD> alls; 
    for(int i = 0;i < n;i++)
    {
        double x,y;
        cin >> x >> y;
        alls.insert({x,y});
    }

    vector<PDD> p;
    for(auto [x,y]:alls) p.push_back({x,y});
    n = p.size();

    int ans = 2;
    for(int i = 1;i < n;i++)
    { 
        set<PDD> h;
        for(int j = 0;j < i;j++)
        {
            if(p[i].x == p[j].x) continue;
            double x1 = (p[j].y - p[i].y) / (p[i].x - p[j].x);
            double y1 = p[i].x * (p[j].y - p[i].y) / (p[i].x - p[j].x) + p[i].y;
            h.insert({x1,y1});
        }
        ans += h.size() + 1;
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
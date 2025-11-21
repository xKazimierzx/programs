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

double get_dis(PDD a,PDD b)
{
    double u = a.x - b.x,v = a.y - b.y;
    return sqrt(u * u + v * v);
}

void solve()
{
    int n;
    cin >> n;
    vector<PDD> p(n);
    vector<double> r(n);
    for(int i = 0;i < n;i++) cin >> p[i].x;
    for(int i = 0;i < n;i++) cin >> p[i].y;
    for(int i = 0;i < n;i++) cin >> r[i];

    double x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        double d1 = get_dis({x1,y1},p[i]);
        double d2 = get_dis({x2,y2},p[i]);
        if(d1 < r[i] && d2 < r[i]) continue;
        //if(d1 > r[i] && d2 > r[i]) continue;
        if(d1 < r[i]) ans++;
        if(d2 < r[i]) ans++;
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
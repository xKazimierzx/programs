#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define cy cout << "Yes" << '\n'
#define cn cout << "No" << '\n'
#define x first
#define y second

using LL = long long;
using ULL = unsigned long long;
using UI = unsigned int;
using LD = long double;
using PII = pair<int,int>;
using PDD = pair<double,double>;

const int N = 1e5 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;
const int DEP = 31;
const int INF32 = INT_MAX; 
const LL INF64 = LONG_LONG_MAX;

int popcnt(int x) {return __builtin_popcount(x);}
int popcnt(UI x) {return __builtin_popcount(x);}
int popcnt(LL x) {return __builtin_popcountll(x);}
int popcnt(ULL x) {return __builtin_popcountll(x);}
int sign(double x) {return fabs(x) < EPS ? 0 : (x < 0 ? -1 : 1);}
int dcmp(double x,double y) {return fabs(x -  y) < EPS ? 0 : (x < y ? -1 : 1);}

void solve()
{
    
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
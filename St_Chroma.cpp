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
    int n, x;
    cin >> n >> x;
    vector<int> p;
    
    if (x == 0) {
        for (int i = 1; i < n; i++) p.push_back(i);
        p.push_back(0);
    } else if (x == n) {
        for (int i = 0; i < n; i++) p.push_back(i);
    } else 
    {
        for (int i = 0; i < x; i++) p.push_back(i);
        for (int i = x + 1; i < n; i++) p.push_back(i);
        p.push_back(x);
    }
    
    for (int x : p) cout << x << " ";
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
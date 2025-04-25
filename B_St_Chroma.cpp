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
    int n,x;
    cin >> n >> x;
    
    if(n == x)
    {
        for(int i = 0;i < n;i++) cout << i << ' ';
        cout << endl;
        return;
    }

    vector<int> a(n);
    a[n - 1] = x;

    for(int i = 0;i < n - 1;i++)
        if(i < x) a[i] = i;
        else a[i] = i + 1;
    
    for(auto i:a) cout << i << ' ';
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
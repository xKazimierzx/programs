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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> b,c;
    for (int i = 0; i < n; i++) 
        if ((i + 1) % 2 == 1) b.push_back(a[i]);
        else c.push_back(a[i]);
    
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    
    vector<int> res(n);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
        if ((i + 1) % 2 == 1) res[i] = b[cnt1++];
        else res[i] = c[cnt2++];
    
    for (int num : res) {
        cout << num << ' ';
    }
    cout << endl;
}

int main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
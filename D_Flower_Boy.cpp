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
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];
    
    vector<int> pre(m + 1, -1);
    int cur = 0;
    pre[0] = -1;
    for (int i = 0; i < n; i++) 
    {
        if (cur < m && a[i] >= b[cur]) {
            cur++;
            pre[cur] = i;
        }
    }

    if (pre[m] != -1) 
    {
        cout << 0 << endl;
        return;
    }
    
    vector<int> suf(m + 1, n);
    cur = m - 1;
    for (int i = n - 1; i >= 0; --i) 
        if (cur >= 0 && a[i] >= b[cur]) 
        {
            suf[cur] = i;
            cur--;
        }
    
    
    int min_k = 0x3f3f3f3f;
    for (int j = 0; j < m; j++) {
        if (j == 0) {
            if (m == 1) {
                min_k = min(min_k, b[0]);
            } else {
                if (suf[1] != n) {
                    min_k = min(min_k, b[0]);
                }
            }
        } else if (j == m - 1) {
            if (pre[j] != -1) {
                min_k = min(min_k, b[j]);
            }
        } else {
            if (pre[j] != -1 && suf[j + 1] != n && pre[j] < suf[j + 1]) {
                min_k = min(min_k, b[j]);
            }
        }
    }
    
    if (min_k == 0x3f3f3f3f) {
        cout << -1 << endl;
    } else {
        cout << min_k << endl;
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
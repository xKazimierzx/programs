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
    int n;
    LL k;
    cin >> n >> k;

    vector<LL> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<LL> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    
    vector<LL> t;
    for (int i = 0; i < n; i++) 
        if (b[i] != -1) t.push_back(a[i] + b[i]);
    
    
    if (!t.empty()) {
        LL x_val = t[0];
        bool flag = false;
        for (LL x : t) 
            if (x != x_val) 
            {
                flag = true;
                break;
            }
                
        if (flag) {
            cout << 0 << endl;
            return;
        }
        
        bool flag1 = true;
        for (int i = 0; i < n; i++) 
        {
            if (b[i] == -1) 
            {
                LL bi = x_val - a[i];
                if (bi < 0 || bi > k) 
                {
                    flag1 = false;
                    break;
                }
            }
        }
        cout << (flag1 ? "1" : "0") << endl;
    } else {
        LL max_a = *max_element(a.begin(), a.end());
        LL min_ak = a[0] + k;
        for (LL ai : a) {
            if (ai + k < min_ak) {
                min_ak = ai + k;
            }
        }
        if (max_a > min_ak) {
            cout << "0\n";
        } else {
            cout << (min_ak - max_a + 1) << "\n";
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
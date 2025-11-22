#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define bp(x) __builtin_poptount(x)
#define bpll(x) __builtin_poptountll(x)
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define rep_(i,a,b) for(int i = a;i >= b;--i)
#define debug(x) cout << x << '\n'
#define cy cout << "Yes" << '\n'
#define cn cout << "No" << '\n'
#define x first
#define y second

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef pair<double,double> PDD;
typedef pair<double,PDD> PDDD;

const int N = 1e6 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;
const int DEP = 31;

void solve()
{
    int n;
    cin >> n;
    vector<int> sa(n),sb(n);
    int ca[32] = {0},cb[32] = {0};
    for(int i = 0;i < n;i++) cin >> sa[i];
    for(int i = 0;i < n;i++) cin >> sb[i];
    
    for(int j = 0;j < 31;j++)
        for(int i = 0;i < n;i++)
        {
            if((sa[i] >> j) & 1) ca[j]++;
            if((sb[i] >> j) & 1) cb[j]++;
        }

    for(int j = 0;j < 31;j++)
        for(int i = 0;i < n;i++)
        {
            int t1 = (sa[i] >> j) & 1;
            int t2 = (sb[i] >> j) & 1;
            if(t1 == t2) continue;
            if(i & 1)
            {
                if(cb[j] % 2 == 0)
                {
                    if(t1) cb[j]++,ca[j]--;
                    else  cb[j]--,ca[j]++;
                }
            }else{
                if(ca[j] % 2 == 0)
                {
                    if(t1) cb[j]++,ca[j]--;
                    else  cb[j]--,ca[j]++;
                }
            }
        }

    int ans1 = 0,ans2 = 0;
    for(int i = 0;i < 31;i++)
    {
        if(ca[i] & 1) ans1 += (1 << i);
        if(cb[i] & 1) ans2 += (1 << i);
    }

    if(ans1 > ans2) cout << "Ajisai" << endl;
    else if(ans1 < ans2) cout << "Mai" << endl;
    else cout << "Tie" << endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
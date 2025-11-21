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
    int n,k;
    cin >> n >> k;
    if(n > k || n * n - k  + 1 < n)
    {
        cn;
        return;
    }
    cy;
    vector<vector<int>> a(n,vector<int>(n));
    unordered_map<int,int> cnt;
    for(int i = 0;i < n;i++)
    {
        a[0][i] = k - i;
        a[i][i] = k + i;    
        cnt[k - i] = 1;
        cnt[k + i] = 1;
    }

    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            if(a[i][j] == 0)
            {
                //cout << i << ' ' << j << endl;
                for(int k = 1;k <= n * n;k++)
                    if(cnt[k] == 0)
                    {
                        //cout << k << endl;
                        a[i][j] = k;
                        cnt[k] = 1;
                        break;
                    }
            }
        

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++) cout << a[i][j] << ' ';
        cout << endl;
    }
}

int main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
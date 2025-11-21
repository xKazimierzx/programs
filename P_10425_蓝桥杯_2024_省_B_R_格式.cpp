#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define debug(x) cout << x << endl
#define cy puts("Yes")
#define cn puts("No")
#define lowbit(x) (x & (-x))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define rep_(i,a,n) for(int i=a;i>=n;i--)
#define endl '\n'

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef pair<double,double> PDD;
typedef pair<double,PDD> PDDD;

const int N = 1e5 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;

vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i ++ )
    {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

void solve()
{
    int n;
    string d;
    cin >> n >> d;
    
    int idx = 0;
    string s = "";
    for(int i = 0;i < d.size();i++)
        if(d[i] != '.') s += d[i];
        else idx = d.size() - i - 1;
    d = s;

    vector<int> A;
    for (int i = d.size() - 1; i >= 0; i -- ) A.push_back(d[i] - '0');

    vector<int> C = mul(A, 2);
    for(int i = 0;i < n - 1;i++) C = mul(C,2);
    vector<int> ans;
    for (int i = C.size() - 1; i >= 0; i -- )
    {
        if(i == idx - 1)
        {
            if(C[i] >= 5) ans[ans.size() - 1]++;
            break;
        }
        else ans.push_back(C[i]);
    }

    for(auto i:ans) cout << i;
}

int main()
{
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
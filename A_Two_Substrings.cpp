#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define debug(x) cout << x << endl
#define cy puts("YES")
#define cn puts("NO")
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
    string s;
    cin >> s;
    int n = s.length();

    string t = s;
    if(s.find("AB") == -1 || s.find("BA") == -1)
    {
        cn;
        return;
    }

    auto idx1 = s.find("AB") + 1; //find AB
    reverse(s.begin(),s.end());
    auto idx2 = n - s.find("AB") - 2; //find BA

    if(idx1 < idx2)
    {
        cy;
        return;
    }
    s = t;

    idx1 = s.find("BA") + 1; //find BA
    reverse(s.begin(),s.end());
    idx2 = n - s.find("BA") - 2; //find AB

    if(idx1 < idx2)
    {
        cy;
        return;
    }

    cn;
}

int main()
{
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
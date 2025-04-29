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
    int n;
    cin >> n;
    string s;
    cin >> s;

    if((s[n - 1] == s[n - 2]) || (s[0] == s[n - 1]))
        if(s[n - 1] == 'A')
        {
            puts("Alice");
            return;
        }else{
            puts("Bob");
            return;
        }
    
    string A(n-1,'A');
    if(s.substr(0,n-1) == A)
    {
        puts("Alice");
        return;
    }else{
        puts("Bob");
        return;
    }

    string B(n-1,'B');
    if(s.substr(0,n-1) == B)
    {
        puts("Bob");
        return;
    }else{
        puts("Alice");
        return;
    }
}

int main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
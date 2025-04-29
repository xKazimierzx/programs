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

bool check(vector<int> &a,int k)
{
    if(!a.size() || a[0] == 0) return false;
    int res = 0;
    for(auto i:a) res += i;
    return res == k;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    
    if(n == 1 && m > 9)
    {
        puts("-1 -1");
        return;
    }

    if(n == 1 && m == 0)
    {
        puts("0 0");
        return;
    }

    vector<int> a,b;
    int t = m;
    for(int i = 1;i <= n;i++)
        for(int j = 0;j <= 9;j++)
        {
            if(i == 1 && t >= j && t >= n - i && j && (n - i) * 9 >= t - j)
            {
                a.push_back(j);
                t -= j;
                break;
            }
            else if(i != 1 && t >= j && t >= n - i && (n - i) * 9 >= t - j)
            {
                a.push_back(j);
                t -= j;
                break;
            }
        }
    

    t = m;
    for(int i = 1;i <= n;i++)
        for(int j = 9;j >= 0;j--)
        {
            if(i == 1 && t >= j && t >= n - i && j)
            {
                b.push_back(j);
                t -= j;
                break;
            }
            else if(i != 1 && t >= j && t >= n - i)
            {
                b.push_back(j);
                t -= j;
                break;
            }
        }
    
    if(check(a,m) || check(b,m))
    {
        if(check(a,m) && !check(b,m))
        {
            for(int i = 0;i < n;i++)
                if(i < a.size()) cout << a[i];
                else cout << 0;

            cout << ' ';
            for(int i = 0;i < n;i++)
                if(i < a.size()) cout << a[i];
                else cout << 0;
            cout << endl;
        }
        else if(!check(a,m) && check(b,m))
        {
            for(int i = 0;i < n;i++)
                if(i < b.size()) cout << b[i];
                else cout << 0;

            cout << ' ';
            for(int i = 0;i < n;i++)
                if(i < b.size()) cout << b[i];
                else cout << 0;
            cout << endl;
        }
        else if(a[0] != 0 && b[0] != 0)
        {
            for(int i = 0;i < n;i++)
                if(i < a.size()) cout << a[i];
                else cout << 0;

            cout << ' ';
            for(int i = 0;i < n;i++)
                if(i < b.size()) cout << b[i];
                else cout << 0;
            cout << endl;
        }
        return;
    }

    puts("-1 -1");
}

int main()
{
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
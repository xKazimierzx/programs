#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define debug(x) cout << x << endl
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

    vector<vector<int>> g(n, vector<int>(n, -1));
    int x = (n - 1) / 2, y = (n - 1) / 2;
    int num = 0;
    g[x][y] = num++;

    if (n == 1) 
    {
        cout << "0" << endl;
        return;
    }

    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int step = 1;
    int dir = 0;

    while (num < n * n) 
    {
        for (int s = 0; s < 2; s++) 
        {
            for (int i = 0; i < step; i++) 
            {
                x += dirs[dir][0];
                y += dirs[dir][1];
                if (x < 0 || x >= n || y < 0 || y >= n || g[x][y] != -1) 
                {
                    x -= dirs[dir][0];
                    y -= dirs[dir][1];
                    break;
                }
                g[x][y] = num++;
            }
            dir = (dir + 1) % 4;
        }
        step++;
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)  cout << g[i][j] << " ";
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
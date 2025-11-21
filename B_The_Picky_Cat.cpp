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
    vector<vector<int>> grid(n, vector<int>(n, -1));
    int cx = n / 2, cy = n / 2;
    if (n % 2 == 0) {
        cx--;
        cy--;
    }
    grid[cx][cy] = 0;
    if (n == 1) {
        cout << "0\n";
        return;
    }

    int current = 1;
    int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // Right, Down, Left, Up
    int dir = 0;
    int x = cx, y = cy;
    int step = 1;

    while (current < n * n) {
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < step; i++) {
                x += dirs[dir][0];
                y += dirs[dir][1];
                if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != -1) {
                    x -= dirs[dir][0];
                    y -= dirs[dir][1];
                    break;
                }
                grid[x][y] = current++;
            }
            dir = (dir + 1) % 4;
        }
        step++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
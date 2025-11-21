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
typedef pair<int,PII> PIII;
typedef pair<double,double> PDD;
typedef pair<PDD,double> PDDD;

const int N = 1e6 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;

int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int dis[3][N];
int n,color = 1;
char g[3][N];
int st[3][N];
bool vis[3][N];

void dfs(int x,int y)
{
    st[x][y] = color;
    for(int i = 0;i < 4;i++)
    {
        int dx = x + dir[i][0],dy = y + dir[i][1];
        if(dx > 2 || dx < 1 || dy > n || dy < 1 || g[dx][dy] != '#' || st[dx][dy]) continue;
        dfs(dx,dy);
    }
}

void bfs(int x,int y)
{
    memset(dis,0x3f,sizeof dis);
    priority_queue<PIII,vector<PIII>,greater<PIII>> q;
    q.push({0,{x,y}});
    dis[x][y] = 0;

    while(q.size())
    {
        auto now = q.top().y;
        int xx = now.x,yy = now.y;
        q.pop();

        if(vis[xx][yy]) continue;
        vis[xx][yy] = true;

        for(int i = 0;i < 4;i++)
        {
            int dx = xx + dir[i][0],dy = yy + dir[i][1];
            if(dx > 2 || dx < 1 || dy > n || dy < 1 || vis[dx][dy]) continue;

            if(st[dx][dy] == st[xx][yy] && st[dx][dy])
            {
                dis[dx][dy] = dis[xx][yy];
                q.push({dis[dx][dy],{dx,dy}});
            }else{
                if(g[dx][dy] == '.')
                {
                    if(dis[dx][dy] > dis[xx][yy] + 1)
                    {
                        dis[dx][dy] = dis[xx][yy] + 1;
                        q.push({dis[dx][dy],{dx,dy}});
                    }
                }
                else{
                    dis[dx][dy] = dis[xx][yy];
                    q.push({dis[dx][dy],{dx,dy}});
                }
            }
            
        }
    }
}

void solve()
{
    string s1,s2;
    cin >> s1 >> s2;
    n = s1.size();
    for(int i = 1;i <= n;i++) g[1][i] = s1[i - 1];
    for(int i = 1;i <= n;i++) g[2][i] = s2[i - 1];

    for(int i = 1;i <= 2;i++)
        for(int j = 1;j <= n;j++)
            if(!st[i][j] && g[i][j] == '#')
            {
                dfs(i,j);
                color++;
            }
    
    for(int i = 1;i <= n;i++)
    {
        if(g[1][i] == '#')
        {
            bfs(1,i);
            break;
        }
        else if(g[2][i] == '#')
        {
            bfs(2,i);
            break;
        }
    }

    int ans = 0;

    // for(int i = 1;i <= 2;i++)
    //     for(int j = 1;j <= n;j++)
    //         if(st[i][j]) ans = max(ans,dis[i][j]);

    for(int i = n;i >= 1;i--)
    {
        if(g[1][i] == '#')
        {   
            ans = dis[1][i];
            break;
        }
        else if(g[2][i] == '#')
        {
            ans = dis[2][i];
            break;
        }
    }

    cout << ans << endl;
}

int main()
{
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}


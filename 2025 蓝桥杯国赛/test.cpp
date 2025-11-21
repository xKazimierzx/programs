#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n,m,visited[N];
vector<int> edge[N];

void DFS(int v)  //从顶点v开始的深度优先遍历算法
{
    cout << v << " "; 
    visited[v]=1;
    for(auto u:edge[v]) 
        if(!visited[u]) DFS(u);
}

void BFS(int v)  //从顶点v开始的广度优先遍历算法
{
    queue<int> q;
    q.push(v);
    visited[v] = 1;

    while(q.size())
    {
        auto now = q.front();
        q.pop();
        cout << now << " ";
        for(auto u:edge[now])
            if(!visited[u]) q.push(u),visited[u] = 1;
    }
}


int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
    }
    DFS(1);
    for (int i=1;i<=N;i++) visited[i]=0;
    cout << "\n";
    BFS(1);
    return 0;
}




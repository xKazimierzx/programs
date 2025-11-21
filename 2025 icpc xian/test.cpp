#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }

    vector<int> col(n, -1);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q0;
    for (int i = 0; i < n; i++) {
        if (deg[i] > 2) {
            q0.emplace(0, i, i);
        }
    }
    
    while (!q0.empty()) {
        auto [d, s, x] = q0.top();
        q0.pop();

        if (col[x] > -1) {
            continue;
        }

        col[x] = s;

        for (int y : adj[x]) {
            if (col[y] == -1) {
                q0.emplace(d + 1, s, y);
            }
        }
    }

    const int lg = __lg(n);
    vector<vector<int>> pa(lg + 1, vector<int>(n, -1));
    vector<int> dep(n), sum(n);

    auto dfs = [&](auto dfs, int x, int p) -> void {
        for (int i = 0; (2 << i) <= dep[x]; i++) {
            pa[i + 1][x] = pa[i][pa[i][x]];
        }

        for (auto y : adj[x]) {
            if (y != p) {
                pa[0][y] = x;
                dep[y] = dep[x] + 1;
                sum[y] = sum[x] + (col[x] != col[y]);
                dfs(dfs, y, x);
            }
        }
    };

    auto lca = [&](int x, int y) {
        if (dep[x] < dep[y]) {
            swap(x, y);
        }

        for (int i = lg; i >= 0; i--) {
            if(dep[x] - dep[y] >= (1 << i)) {
                x = pa[i][x];
            }
        }

        if (x == y) {
            return x;
        }

        for (int i = lg; i >= 0; i--) {
            if(pa[i][x] != pa[i][y]) {
                x = pa[i][x], y = pa[i][y];
            }
        }
        return pa[0][x];
    };

    dfs(dfs, 0, -1);

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;

        u--, v--;
        cout << sum[u] + sum[v] - 2 * sum[lca(u, v)] + 1 << '\n';
    }

    return 0;
}

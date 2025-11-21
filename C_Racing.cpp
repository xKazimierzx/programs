#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> d(n), l(n), r(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
        }

        ll h = 0;  // 当前高度
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (d[i] == 0 || d[i] == 1) {
                // 已知操作，直接更新
                h += d[i];
                if (h < l[i] || h > r[i]) {
                    ok = false;
                    break;
                }
            } else {
                // 未知时，优先尝试 d[i]=0
                if (h >= l[i] && h <= r[i]) {
                    d[i] = 0;
                    // h 不变
                } else if (h + 1 >= l[i] && h + 1 <= r[i]) {
                    d[i] = 1;
                    h += 1;
                } else {
                    ok = false;
                    break;
                }
            }
        }

        if (!ok) {
            cout << "-1\n";
        } else {
            for (int x : d) {
                cout << x << ' ';
            }
            cout << "\n";
        }
    }
    return 0;
}

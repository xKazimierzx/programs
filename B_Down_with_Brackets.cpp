#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int balance = 0;
        int primitives = 0;
        for (char c : s) {
            if (c == '(') ++balance;
            else --balance;
            // 每次前缀平衡回到 0，就结束了一个原语
            if (balance == 0) {
                ++primitives;
            }
        }
        // 如果原语数 ≥ 2，则可以删去一对跨原语的括号使之失衡
        cout << (primitives > 1 ? "YES\n" : "NO\n");
    }
    return 0;
}

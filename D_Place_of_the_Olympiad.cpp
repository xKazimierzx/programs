#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a = (k + n - 1) / n;
    int b = m - a;
    cout << (a + b) / (b + 1) << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
# Solved Problems

$\begin{pmatrix}
1 & 1 & \cdots & 1 \\
1 & 1 & \cdots & 1 \\
\vdots & \vdots & \ddots & \vdots \\
1 & 1 & \cdots & 1 \\
\end{pmatrix}$

```cpp
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
```

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int N = 1e6 + 10;
ULL stk[N];
int top;

void solve()
{
    int n;
    cin >> n;
    top = 0;
    while(n--)
    {
        string s;
        cin >> s;
        if(s == "push")
        {
            ULL x;
            cin >> x;
            stk[++top] = x;
        }
        else if(s == "pop")
        {
            if(top == 0) cout << "Empty" << endl;
            else top--;
        }
        else if(s == "query")
        {
            if(top == 0) cout << "Anguei!" << endl;
            else cout << stk[top] << endl;
        }
        else cout << top << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
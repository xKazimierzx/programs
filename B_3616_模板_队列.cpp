#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int N = 1e6 + 10;
ULL q[N];
int head,tail;

void solve()
{
    int n;
    cin >> n;
    
    while(n--)
    {
        string s;
        cin >> s;
        if(s == "1")
        {
            ULL x;
            cin >> x;
            q[tail++] = x;
        }
        else if(s == "2")
        {
            if(head == tail) cout << "ERR_CANNOT_POP" << endl;
            else head++;
        }
        else if(s == "3")
        {
            if(head == tail) cout << "ERR_CANNOT_QUERY" << endl;
            else cout << q[head] << endl;
        }
        else cout << tail - head << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
typedef long long LL;

vector<int> prime;
bool st[N];

void get_primes(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i]) prime.push_back(i);
        for(int j=0;i*prime[j]<=n;j++)
        {
            st[i*prime[j]] = true;
            if(i%prime[j]==0) break;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for(auto j:prime)
        if(j <= n) ans += n / j;
        else break;
    cout << ans << endl;
}

int main()
{
    int T;
    get_primes(10000000);
    cin >> T;
    while(T--) solve();
    return 0;
}
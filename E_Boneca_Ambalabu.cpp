#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve()
{
    int n;
    cin >> n;
    vector<LL> a(n);


    //0 1000 8 $ 2 * 8 + 4 * 4 + 1 * 2 + 3 = 37 37
    //0 1101 13 2 * 8 + 1 * 4 + 1 * 2 + 2 = 24 24
    //0 0100 4 3 * 8 + 1 * 4 + 1 * 2 + 3 =  33
    //0 0101 5 3 * 8 + 1 * 4 + 1 * 2 + 2 =  32
    //0 1111 15 2 * 8 + 1 * 4 + 4 * 2 + 2 =  30
    //0 3413 0
    //0 2142 1
    
    //0 0001
    //0 0010
    //0 0100
    //0 1000
    //1 0000 $
    //1 1111

    //001110000100 900 1
    //001101001001 841 1
    //001011011001 729 1
    //001001110001 625
    //001010100100 676 2 $
    //001100010000 784
    //006333232203
    //000333434463
    
    for(int i = 0;i < n;i++) cin >> a[i];

    map<int,int> h;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < 30;j++)
            if((1ll << j) & a[i]) h[j]++;
    
    LL ans = 0;
    for(int i = 0;i < n;i++)
    {
        LL res = 0;
        for(int j = 0;j < 30;j++)
            if((1ll << j) & a[i]) res += (n - h[j]) * (1ll << j);
            else res += h[j] * (1ll << j);
        ans = max(ans,res);
    }

    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T--) solve();
}
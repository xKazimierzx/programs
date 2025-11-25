#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> PII;
 
void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
 
    if((!m && n > 26) || m >= k)
    {
        puts("No");
        return;
    }
 
    if(!m)
    {
        puts("Yes");
        int t = 'a';
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < k;j++)
                cout << char(t);
            t++;
            cout << endl;
        }
 
        return;
    }
 
    vector<PII> a;
    for(int i = 'a';i < 'z';i++)
        for(int j = i + 1;j < 'z';j++)
        {
            a.push_back({i,j});
        }
 
    //for(auto [i,j]:a) cout << char(i) << ' ' << char(j) << endl;
    
    puts("Yes");
    for(int j = 1;j <= k - m;j++)
        if(j & 1) cout << char(a[0].first);
        else cout <<  char(a[0].second);
    for(int i = 1;i <= m;i++) cout << 'z';
    cout << endl;
 
    for(int i = 1;i <= m;i++) cout << 'z';
    for(int j = 1;j <= k - m;j++)
        if(j & 1) cout << char(a[1].first);
        else cout <<  char(a[1].second);
    
    cout << endl;
 
    for(int i = 2;i < n;i++) 
    {
        for(int j = 1;j <= k;j++)
            if(j & 1) cout << char(a[i].first);
            else cout <<  char(a[i].second);
        cout << endl;
    }
 
    
}
 
int main()
{
    solve();
    return 0;
}
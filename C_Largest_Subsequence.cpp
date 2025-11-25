#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    if(is_sorted(s.begin(),s.end()))
    {
        puts("0");
        return;
    }
    
    deque<char> q;
    int idx[n+1] = {},top = 0;
    for(int i = 0;i < s.length(); i++)
    {
        while(q.size() && s[i] > q.back()) q.pop_back(),top--;
        q.push_back(s[i]);
        idx[top++] = i;
    }
    
    map<int,int> cnt;
    char maxv = 'a';
    for(auto i:q) maxv = max(maxv,i),cnt[i]++;
    
    for(int i = 0;i < q.size()/2; i++) swap(s[idx[i]],s[idx[top-i-1]]);
    //cout<<s<<endl;
    if(is_sorted(s.begin(),s.end())) cout<<q.size() - cnt[maxv]<<endl;
    else puts("-1");
}

int main()
{
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
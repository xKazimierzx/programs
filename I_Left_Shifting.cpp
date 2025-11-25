#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
int n;
void solve(){
    string s;cin>>s;
    n=s.size();
    if(s[0]==s[n-1]){
        cout<<0<<endl;return;
    }
    rep(i,0,n-1){
       if(i+1<n&&s[i]==s[i+1]){
        cout<<i+1<<endl;return;
       }
    }
    cout<<-1<<endl;
}
signed main(){
   int _=1;
   cin>>_;
   while(_--)
   solve();
   return 0;
}
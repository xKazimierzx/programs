#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rep_(i,a,b) for(int i=a;i>=b;--i)
#define PII pair<int,int>
#define tul array<int,3>
#define cy cout<<"YES"<<endl
#define cn cout<<"NO"<<endl
const int N=5e5+5,yyx=1e9+7;
int n,m,k,a[N];
inline int mod(int x){
    return (x%yyx+yyx)%yyx;
}
template<class T> inline int cmax(T &x,T y){
   return x<y?x=y,1:0;
}
template<class T> inline int cmin(T &x,T y){
    return x>y?x=y,1:0;
}
int suf[N];
inline void solve(){
    cin>>n;
    rep(i,1,n) cin>>a[i];
    suf[n+1]=0;
    rep_(i,n,1) suf[i]=suf[i+1]+a[i];
    int ans=suf[1];
    sort(suf+2,suf+1+n,greater<int>());
    cout<<ans<<" ";
    rep(i,2,n){
        ans+=suf[i];
        cout<<ans<<" ";
    }
    cout<<endl;
}
signed main(){
   cin.tie(0)->sync_with_stdio(0);
   int _=1;
   cin>>_;
   while(_--)
   solve();
   return 0;
}
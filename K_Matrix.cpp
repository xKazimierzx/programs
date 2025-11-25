#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rep_(i,a,b) for(int i=a;i>=b;--i)
#define PII pair<int,int>
#define tul array<int,3>
#define cy cout<<"Yes"<<endl
#define cn cout<<"No"<<endl
const int N=5e2+5,yyx=1e9+7;
int n,m,k,a[N][N];
inline int mod(int x){
    return (x%yyx+yyx)%yyx;
}
template<class T> inline int cmax(T &x,T y){
   return x<y?x=y,1:0;
}
template<class T> inline int cmin(T &x,T y){
    return x>y?x=y,1:0;
}
inline void solve(){
    cin>>n;
    if(n==2){
      cy;
      int cnt=0;
      rep(i,1,n) rep(j,1,n) a[i][j]=++cnt;
      rep(i,1,n) rep(j,1,n) cout<<a[i][j]<<" \n"[j==n];return;
    }
    if(n==3){
      cy;
      a[1][1]=3;a[1][2]=2;a[1][3]=6;
      a[2][1]=4;a[2][2]=3;a[2][3]=3;
      a[3][1]=3;a[3][2]=1;a[3][3]=5;
      rep(i,1,n) rep(j,1,n) cout<<a[i][j]<<" \n"[j==n];return;
    }
    cy;
    int cnt=0;
    rep(i,1,n) a[1][i]=++cnt;
    rep(i,1,2) a[2][i]=++cnt;
    rep(i,3,n){
        a[2][i]=i;
    }
    rep(i,3,n){
      ++cnt;
      rep(j,1,n) a[i][j]=min(cnt,2*n);
    }
    rep(i,1,n) rep(j,1,n) cout<<a[i][j]<<" \n"[j==n];
}
signed main(){
   cin.tie(0)->sync_with_stdio(0);
   int _=1;
   //cin>>_;
   while(_--)
   solve();
   return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define bp(x) __builtin_poptount(x)
#define bpll(x) __builtin_poptountll(x)
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define rep_(i,a,b) for(int i = a;i >= b;--i)
#define debug(x) cout << x << '\n'
#define cy cout << "Yes" << '\n'
#define cn cout << "No" << '\n'
#define x first
#define y second

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef pair<double,double> PDD;
typedef pair<double,PDD> PDDD;

const int N = 1e5 + 10;
const int MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-8;
const int DEP = 31;

void get_fac(int x)
{
    for(int i=2;i<=x/i;i++)
        if(x%i==0)
        {
            int s = 0;
            while(x%i==0) x/=i,s++;
            p[i] += s;
        }
    if(x>1) p[x]++;
}


void solve()
{
    int n;
    unordered_map<int,int> p;
    vector<PII> a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        get_fac(x);
    }
    
    for(auto i:p) a.push_back({i.first,i.second});
    sort(a.begin(),a.end());
    
    //for(auto i:a) cout<<i.first<<" "<<i.second<<endl;
    
    int res = 0;
    for(int i=0;i<a.size();i++)
    {
        int &x = a[i].first,&s = a[i].second;
        if(s>=2) res += (s/2),s%=2;
    }
    
    int cnt = 0;
    for(int i=0;i<a.size();i++)
    {
        int &x = a[i].first,&s = a[i].second;
        if(s) cnt++,s--;
        if(cnt>=3) cnt=0,res++;
    }
    cout<<res<<endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
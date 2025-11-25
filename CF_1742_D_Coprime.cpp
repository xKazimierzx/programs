#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10; 
int a[N];
unordered_map<int,int> p;

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		p.clear();
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i],p[a[i]] = max(p[a[i]],i);
		
		int ans = 0;
		for(int i=1;i<=1000;i++)
			for(int j=1;j<=1000;j++)
				if(p[i]&&p[j]&&gcd(i,j)==1) ans = max(ans,p[i]+p[j]);
		
		if(ans) cout<<ans<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}
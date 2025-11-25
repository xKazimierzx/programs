//123123
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
typedef pair<int,int> Point;
typedef long long LL;

const int N = 1e5 + 10;
int n;
Point p[N];

int dot(Point a, Point b)
{
    return a.x * b.x + a.y * b.y;
}

int cross(Point a, Point b)
{
    return a.x * b.y - b.x * a.y;
}

int get_dis(Point a,Point b)
{
	int u = a.x - b.x,v = a.y - b.y;
	return u * u + v * v;	
} 

LL todo(Point a,Point b,int l,int r)
{
	Point c = {b.x - a.x,b.y - a.y};
	
	LL ans1 = 0,ans2 = 0;
	map<int,int> h1,h2;
	for(int i = 0;i < n;i++)
		if(i != l && i != r)
		{
			double t = cross({p[i].x - a.x,p[i].y - a.y},{b.x - a.x,b.y - a.y});
			if(t == 0) continue;
			if(t < 0)
			{
				if(get_dis(p[i],a) == get_dis(p[i],b)) ans1++; 
			}
			if(t > 0)
			{
				if(dot({p[i].x - a.x,p[i].y - a.y},{b.x - a.x,b.y - a.y}) == 0)
				{
					h1[get_dis(p[i],a)]++; 
				}
				
				if(dot({p[i].x - b.x,p[i].y - b.y},{b.x - a.x,b.y - a.y}) == 0)
				{
					h2[get_dis(p[i],b)]++; 
				}
			} 
		}
	
	for(auto [x,y]:h1)
		if(h2[x]) ans2++;
		
	return ans1 * ans2;
}

signed main()
{
	cin >> n;
	for(int i = 0;i < n;i++) cin >> p[i].x >> p[i].y;
	
	LL ans = 0; 
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			if(i != j) ans += todo(p[i],p[j],i,j);
	cout << ans << endl;
	return 0;
}
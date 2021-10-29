#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+100;
struct cake
{
	ll num;
	int id;	
}a[N];
ll l,r,ans;
ll b[N];
int n,m;

bool check(ll all)
{
	ll now=0;
	for(int i=1;i<=n;i++) b[i]=a[i].num;
	int i=1,j=1;
	while(j<=n)
	{
		if(now+b[j]<all)
		{
			now+=b[j];
			j++;	
		}
		else if(now+b[j]==all)
		{
			now=0;
			i++;j++;
			if(j==n+1&&i==m+1) return 1;
		}
		else
		{
			b[j]=now+b[j]-all;
			i++;now=0;
		}
	}
	if(i<=m) return 1;
	return 0;
}

void work(ll all)
{
	for(int i=1;i<=n;i++) b[i]=a[i].num;
	int i=1,j=1;
	ll now=0,t1,t2,t3;
	bool flag=0;
	while(j<=n)
	{
		if(now+b[j]<all)
		{
			if(!flag) cout<<1<<' '<<i<<' '<<now<<' '<<now+b[j]<<endl;
			else cout<<2<<' '<<i<<' '<<now<<' '<<now+b[j]<<' '<<t1<<' '<<t2<<' '<<t3<<endl;
			now+=b[j]; j++;
		}
		else if(now+b[j]==all)
		{
			cout<<1<<' '<<i<<' '<<now<<' '<<now+b[j]<<endl;
			i++;now=0; j++;	
		}
		else
		{
			flag=1;
			t1=i,t2=now,t3=all;
//			cout<<2<<' '<<i<<' '<<now<<' '<<all<<' ';
			b[j]=now+b[j]-all;i++;now=0;	
		}
	}
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num;
		a[i].id=i;
		l=max(l,a[i].num);	
	}
	r=1e18;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)) { ans=mid;r=mid-1; }
		else l=mid+1;
	}
	work(ans);
	return 0;
}
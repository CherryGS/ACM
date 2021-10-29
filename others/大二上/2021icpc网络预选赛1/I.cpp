#include <bits/stdc++.h>
using namespace std;

const int N=1e6+100;
int a[N],n,x,dis,l,r;

int main()
{
//	freopen("a.in","r",stdin);
	int t=1;
	while(scanf("%d",&a[t])!=EOF)
	{
		t++;
	}
	t--;
	n=t-2,x=a[t-1],dis=a[t];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(abs(x-a[i])<=dis) { l=i;break; }
	}
	for(int i=n;i>=1;i--)
	{
		if(abs(x-a[i])<=dis) { r=i;break; }	
	}
	for(int i=r;i>=l;i--) cout<<a[i]<<' ';
	return 0;
}

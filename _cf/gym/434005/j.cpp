#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 100050;
int n,lp[N],rp[N];
ll a[N];
int sta[N],tl;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		while(tl&&a[sta[tl]]>a[i])rp[sta[tl]]=i-1,tl--;
		sta[++tl]=i;
	}
	while(tl)rp[sta[tl]]=n,tl--;
	for(int i=n;i>=1;i--)
	{
		while(tl&&a[sta[tl]]>=a[i])lp[sta[tl]]=i+1,tl--;
		sta[++tl]=i;
	}
	while(tl)lp[sta[tl]]=1,tl--;
	ll ans = 0,l,r;
	for(int i=1;i<=n;i++) {
        ll pre = a[i]*(rp[i]-lp[i]+1);
		if(pre>ans)
		{
			ans=pre;
			l=lp[i],r=rp[i];
		}else if((lp[i]<l || (lp[i] == l && rp[i] > r))&&a[i]*(rp[i]-lp[i]+1)==ans)
		{
			l=lp[i],r=rp[i];
		}
    }
	printf("%lld %lld %lld\n",l,r,ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define LL long long
const ll mod=998244353;
ll T,n,X,now,last1,ans;
ll ANS[6000];

ll qpow(LL a, LL b){
	LL root = a, ans = 1;
	while (b){
		if (b & 1){
			ans = ans * root % mod;
		}
		root = root * root % mod;
		b >>= 1;
	}
	return ans;
}

ll inv(ll x)
{
	return qpow(x, mod - 2);
}

int main()
{
//	freopen("A.out","w",stdout);
	cin>>T;
	cout<<1152*6*5*4*3*2<<endl;
	while(T)
	{
		ans=0;
		now=1;
		last1=0;
//		n=T;
		cin>>n;
		X=1;
		for(ll i=n*n-n;i>=1;i--) X=X*i%mod;
		for(ll i=1;i<=n;i++)
		{
			now=now*(n-i+1)%mod;
			now=now*inv(i)%mod;
			ll tt=1;
			for(ll j=i*n;j>=(i-1)*n+1;j--) tt=tt*j%mod;
			tt=now*tt%mod;
			ll QQ=tt;
			tt=(tt-last1+mod)%mod;
			last1=QQ;
			ans=(ans+i*tt%mod)%mod;
		}
		ans=ans*X%mod;
		printf("%lld\n",ans);
		ANS[T]=ans;
		T--;
	}
/*
	for(int i=1;i<=5000;i++)
	{
		printf("%lld",ANS[i]);
		if(i!=5000) printf(",");	
	}
*/
	return 0;	
}

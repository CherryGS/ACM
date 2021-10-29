#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define LL long long
const ll mod=998244353;
ll T,n,X,now,last1;
ll ANS[5010],A[25000010],C[5010][5010],nowans[5010];

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
	freopen("A.out","w",stdout);
	for(ll i=1;i<=5000;i++) C[i][0]=1;
	A[0]=1;
	for(ll i=1;i<=5000*5000;i++) A[i]=A[i-1]*i%mod;
	C[0][0]=1;
	for(ll i=1;i<=5000;i++)
	{
		for(ll j=1;j<=i;j++)
		{
			C[i][j]=A[i]*inv(A[j])%mod*inv(A[i-j])%mod;
		}
	}
	T=5000;
//	cin>>T;
	while(T)
	{
		memset(nowans,0,sizeof(nowans));
		now=1;
		last1=0;
		n=T;
//		cin>>n;
		X=1;
		for(ll i=n*n-n;i>=1;i--) X=X*i%mod;
		for(ll i=1;i<=n;i++)
		{
			now=C[n][i];
			ll tt=A[n*i]*inv(A[n*(i-1)])%mod;
			tt=now*tt%mod;
			nowans[i]=tt;
			for(ll j=1;j<=i-1;j++)
				nowans[i]=(nowans[i]-(nowans[j]*C[n-j][i-j])%mod+mod)%mod;
		}
		ll E=0;
		for(ll i=1;i<=n;i++)
			E=(E+nowans[i]*i%mod*X%mod)%mod;
//		printf("%lld\n",E);
		ANS[T]=E;
		T--;
	}
	
	for(ll i=1;i<=5000;i++)
	{
		printf("%lld",ANS[i]);
		if(i!=5000) printf(",");	
	}
	
	return 0;	
}

#include<bits/stdc++.h>
using namespace std;

#define mo 998244353
#define ll long long
#define M 800005

const int bas=350;
const int bas1=46;
const int bas2=46*46;
ll q1[M],q2[M],q0[M],a[M],b[M],la[M],lb[M],ha[M],hb[M],q3[M],q4[M],ma[M],mb[M];
ll sum[bas+5][bas+5];
int p[M],rev[M];
ll ans[M];
ll ksm(ll a,ll b){
	ll res=1;
	for (;b;b>>=1){
		if (b&1)res=res*a%mo;
		a=a*a%mo;
	}
	return res;
}


void solve(ll *a,int n,int DFT){
	for (int i=0;i<n;i++){
		if (i<rev[i])swap(a[i],a[rev[i]]);
	}
	for (int m=1;m<n;m<<=1){
		int k=m<<1;
		ll w=1;
		ll wn=ksm(3,(mo-1)/k);
		if (DFT)wn=ksm(wn,mo-2);
		for (int i=0;i<m;i++){
			for (int j=i;j<n;j+=k){
				ll l=a[j],r=a[j+m];
				a[j]=(l+w*r)%mo;
				a[j+m]=(l-w*r)%mo;
			}
			w=w*wn%mo;
		}
	}
	if (DFT){
		ll w=ksm(n,mo-2);
		for (int i=0;i<n;i++)a[i]=(a[i]*w%mo+mo)%mo;
	}

}






void solve(int n,int ct){
	for (int i=0;i<n;i++){
		la[i]=a[i]%bas1;
		lb[i]=b[i]%bas1;
		ma[i]=a[i]/bas1%bas1;
		mb[i]=b[i]/bas1%bas1;
		ha[i]=a[i]/bas2;
		hb[i]=b[i]/bas2;
//printf("%lld %lld\n",a[i],b[i]);
	}
	
	int k;
	n=n*2;
	for (k=1;k<=n;k<<=1);
	for (int i=0;i<k;i++)rev[i]=(rev[i>>1]>>1)|((i&1)*(k>>1));
	solve(la,k,0);
	solve(ha,k,0);
	solve(ma,k,0);
	solve(mb,k,0);
	solve(lb,k,0);
	solve(hb,k,0);
	for (int i=0;i<k;i++){
		q0[i]=la[i]*lb[i]%mo;
		q1[i]=(la[i]*mb[i]+ma[i]*lb[i])%mo;
		q2[i]=(la[i]*hb[i]%mo+lb[i]*ha[i]%mo+ma[i]*mb[i]%mo)%mo;
		q3[i]=(ma[i]*hb[i]+mb[i]*ha[i])%mo;
		q4[i]=(ha[i]*hb[i])%mo;
	}
	solve(q0,k,1);
	solve(q1,k,1);
	solve(q2,k,1);
	solve(q3,k,1);
	solve(q4,k,1);
	for (int i=0;i<ct;i++){
//		printf("%lld %lld %lld\n",q0[i+ct-1],q1[i+ct-1],q2[i+ct-1]);
		ans[i]=q0[i+ct-1]+q1[i+ct-1]*bas1+q2[i+ct-1]*bas1*bas1+q3[i+ct-1]*bas1*bas1*bas1+q4[i+ct-1]*bas1*bas1*bas1*bas1;
//	printf("%lld\n",ans[i]);
	}
	for (int i=0;i<k;i++){
		q0[i]=q1[i]=q2[i]=q3[i]=q4[i]=ma[i]=mb[i]=la[i]=lb[i]=ha[i]=hb[i]=a[i]=b[i]=0;
	}
}
ll res[M];
bool vis[M];
int q[M];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for (int i=1;i<=m;i++){
		scanf("%d",&q[i]);
	}
	for (int i=1;i<=n;i++)if (!vis[i]){
		int ct=0;
		for (int x=i;!vis[x];x=p[x]){
			b[ct]=a[ct]=x;
			ct++;
			vis[x]=1;
		}
		for (int j=0;j<ct-j-1;j++){
			swap(b[j],b[ct-1-j]);
		}
		for (int j=0;j<ct;j++){
			b[j+ct]=b[j];
		}
		solve(2*ct,ct);
		if (ct<=bas){
			for (int j=0;j<ct;j++){
				sum[ct][j]+=ans[j];
			}
		}
		else{
			for (int j=1;j<=m;j++){
				res[j]+=ans[q[j]%ct];
			}
		}
	}
	for (int i=1;i<=bas;i++){
		for (int j=1;j<=m;j++){
			res[j]+=sum[i][q[j]%i];
		}
	}
	for (int i=1;i<=m;i++){
		printf("%lld\n",res[i]);
	}
	return 0;
}

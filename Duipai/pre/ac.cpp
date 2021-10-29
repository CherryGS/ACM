#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#define N 1000005
using namespace std;
int mod=1e9+7;
int n,m;
struct edge{
	int u,to,next;
};edge e[N<<2];
int to[N<<2];
int head[N<<1],in[N<<1];int cnt=0;
void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int dp[N<<2][2];
void dfs(int u,int fa){
	int s1=0,s2=0;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v!=fa&&v>=n){
			dfs(v,u);
			s1+=dp[v][1];
			s2+=min(dp[v][0],dp[v][1]);
		}
	}
	dp[u][0]=s1;
	dp[u][1]=s2+1;
}
int f[N<<2][2];
int main(){
	cin>>n>>m;
	for(int i=1;i<=(n+m);i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=0;i<=n-1;i++){
		dfs(i,-1);
	}
	f[0][1]=dp[0][1];
	f[0][0]=mod;
	for(int i=1;i<n;i++){
		f[i][0]=f[i-1][1]+dp[i][0];
		f[i][1]=min(f[i-1][0],f[i-1][1])+dp[i][1];
	}
	int ans1=min(f[n-1][0],f[n-1][1]);
	f[0][1]=mod;
	f[0][0]=dp[0][0];
	for(int i=1;i<n;i++){
		f[i][0]=f[i-1][1]+dp[i][0];
		f[i][1]=min(f[i-1][0],f[i-1][1])+dp[i][1];
	}
	int ans2=f[n-1][1];
	int ans=min(ans1,ans2);
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1e5;
int n,k,ans,cnt,a[N];
int q[N*2];
vector<int>f[N];
bool vis[N];
int Max(int x,int y){
	return x>y?x:y;
}
int rd(){
	int s=0,ff=1;
	char w=getchar();
	while(!isdigit(w))
		ff^=w=='-',w=getchar();
	while(isdigit(w))
		s=s*10+w-'0',w=getchar();
	return ff?s:-s;
}
void Work(int x){
	int i=0,j=0;
	int X=q[x];
	int tot=f[X].size();
	ans=Max(ans,(int)f[X].size());
	if(x-k<0||x-k>=N*2) return ;
	int Y=q[x-k];
	if(!Y) return ;
	while(i<f[X].size()&&j<f[Y].size()){
		if(f[X][i]<f[Y][j]) tot--,i++;
		else tot++,j++;
		if(tot<f[X].size())
			tot=f[X].size();
		else
			ans=Max(ans,tot);
	}
	while(j<f[Y].size())
		tot++,j++;
	ans=Max(ans,tot);
}
int main(){
	n=rd(); k=rd();
	int x,zc;
	for(int i=1;i<=n;i++){
		a[i]=rd();
		if(!q[a[i]+N]) q[a[i]+N]=++cnt,zc=cnt;
		else zc=q[a[i]+N];
		f[zc].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(!vis[q[a[i]+N]]){
			vis[q[a[i]+N]]=1;
			Work(a[i]+N);
		}
	}
	printf("%d\n",ans);
	return 0;
}
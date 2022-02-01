//by_ileln
//#define LOCAL
#include<bits/stdc++.h>
using namespace std;
#define IL inline
#define ll long long
#define pii pair<int,int>
#define N 1000005
#define M(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define cinio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define lowbit(x) x & -x
#define dbg(x) cout << #x << " = " << x << endl
ll mod=1e9+7;
int head[N];struct edge{int to,next;};edge e[N<<1];
int cmt=0;int T;
int n,m;
int tree[N<<2];void Add(int x,int k){while(x<=n){tree[x]+=k;x+=lowbit(x);}}
int Sum(int x){int ans=0;while(x!=0){ans+=tree[x];x-=lowbit(x);}return ans;}
void add(int u,int v){e[++cmt].to=v;e[cmt].next=head[u];head[u]=cmt;}
template<typename Tp> IL void read(Tp &x){x=0;int f=1;char ch=getchar();while(!isdigit(ch)){
if(ch == '-')f=-1;ch=getchar();}while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}x*=f;}
int buf[42];
template<typename Tp> IL void write(Tp x){int p=0;if(x<0){putchar('-'); x=-x;}if(x==0)
{putchar('0');return;}while(x){buf[++p] = x % 10;x /= 10;}for(int i=p;i;i--) putchar('0'+buf[i]);}
ll quick(ll a,ll b){ll ret=1;ll now=a;while(b){if(b&1){ret*=now;ret%=mod;}now*=now;now%=mod;b>>=1;}return ret;}
ll Inv(ll b){if(b==1)return 1;return(mod-mod/b)*Inv(mod%b)%mod;}
ll fac[N],inv[N];void getc(){fac[0]=inv[0]=1;for(int i=1;i<n;i++)fac[i]=fac[i-1]*i%mod;
inv[n-1]=quick(fac[n-1],mod-2);for(int i=n-2;i;i--)inv[i]=inv[i+1]*(i+1)%mod;}
ll c(int n,int m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
ll C(ll a,ll b,ll p){if(b>a)return 0;ll res=1;for(ll i=1,j=a;i<=b;i++,j--){res=res*j%p;res=res*quick(i,mod-2)%p;}return res;}
ll lucas(ll n, ll m,ll p){return m?lucas(n/p,m/p,p)*C(n%p,m%p,p)%p:1;}
/*int fa[N][22];int Fa(int i,int k){for(int x=0;x<=int(log2(k));x++)if((1<<x)&k)i=fa[i][x];return i;}
void getFa(int x){for(int i=1;i<=21;i++){if(fa[x][i-1])	fa[x][i]=fa[fa[x][i-1]][i-1];else break;}}*/
/*int B[N],p[N],pcnt=0;void getPrime(int n){B[1]=0;for(int i=2;i<=n;i++){if(!B[i]) p[++pcnt]=i;
for(int j=1;j<=pcnt&&i*p[j]<=n;j++){B[i*p[j]]=1;if(i%p[j]==0)break;}}}*/
map<int,int>mp;
struct node{
	int val,id;
};node a[N];
bool cmp1(node a,node b){
	return a.val<b.val;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	//srand(19992147); 
	cin>>T;
	while(T--){
		read(n);
		for(int i=1;i<=n;i++){
			read(a[i].val);a[i].id=i;
		}
		double ans=2000000000;
		if(n<=30000){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					double now=abs(a[i].val-a[j].val)*1.0;
					now/=abs(i-j)*1.0;
					ans=min(ans,now);
				}
			}
		}
		else{
			int p1=min(n,6000),p2=max(1,n-6000),p3=min(50,n);
			p2=max(p1+1,p2);
			for(int i=1;i<=p1;i++){
				for(int j=p2;j<=n;j++){
					if(i==j) continue;
					double now=abs(a[i].val-a[j].val)*1.0;
					now/=abs(i-j)*1.0;
					ans=min(ans,now);
				}
			}
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=min(i+p3,n);j++){
					double now=abs(a[i].val-a[j].val)*1.0;
					now/=abs(a[i].id-a[j].id)*1.0;
					ans=min(ans,now);
				}
			}
		}
		printf("%.15lf\n",ans);
	}
	return 0;
}
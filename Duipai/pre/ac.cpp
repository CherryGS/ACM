#include <bits/stdc++.h>
#define maxn 1000005
#define mod 4933
using namespace std;
typedef long long LL;
int read()
{
    int f=1,sum=0;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0' && c<='9'){sum=sum*10+c-'0';c=getchar();}
    return sum*f;
}
LL readLL()
{
    LL f=1,sum=0;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') f=-1LL;c=getchar();}
    while(c>='0' && c<='9'){sum=sum*10+c-'0';c=getchar();}
    return sum*f;
}
int n,col[maxn];
int head[maxn],to[maxn<<1],nex[maxn<<1],cnt;
void add(int u,int v)
{
    nex[++cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
}
int siz[maxn],son[maxn];
int dfs1(int x,int fa)
{
    siz[x]=1;
    for(int i=head[x];i;i=nex[i])
    {
        if(to[i]==fa) continue;
        dfs1(to[i],x);
        if(siz[to[i]]>siz[son[x]]) son[x]=to[i];
        siz[x]+=siz[to[i]];
    }
}
long long ans[maxn],now_ans=0;
int tong[maxn],max_col=0;
void cal(int x,int fa,int type)
{
	tong[col[x]]+=type;
	if(type==1)
	{
		if(tong[col[x]]>max_col) max_col=tong[col[x]],now_ans=col[x];
		else if(tong[col[x]]==max_col) now_ans+=col[x];
	}
	for(int i=head[x];i;i=nex[i])
	if(to[i]!=fa) cal(to[i],x,type);
}
void dfs2(int x,int fa,bool del)
{
	for(int i=head[x];i;i=nex[i])
	if(to[i]!=fa && to[i]!=son[x]) dfs2(to[i],x,true);//统计轻儿子
	
	if(son[x]!=0) dfs2(son[x],x,false);//统计重儿子

	for(int i=head[x];i;i=nex[i])
	    if(to[i]!=fa&&to[i]!=son[x]) cal(to[i],x,1);
	
	tong[col[x]]++;
	if(tong[col[x]]>max_col) max_col=tong[col[x]],now_ans=col[x];
	else if(tong[col[x]]==max_col) now_ans+=col[x];
	
	ans[x]=now_ans;
    if(del) cal(x,fa,-1),max_col=0,now_ans=0;
}
int main()
{
    n=read();
	for(int i=1;i<=n;i++)
    col[i]=read();
	for(int i=1;i<n;i++)
    {
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
	dfs1(1,0);
	dfs2(1,0,false);
	for(int i=1;i<=n;i++)
	printf("%lld ",ans[i]);
	putchar('\n');
}

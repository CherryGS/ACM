#include <bits/stdc++.h>
using namespace std;

int n,ans;
int a[10][10],book[100];

void dfs(int x,int y)
{
	if(x>n)
	{
		for(int i=1;i<=n;i++)
		{
			int minn=10000;
			for(int j=1;j<=n;j++) minn=min(minn,a[i][j]);
			if(minn<=n) ans++;
		}
		return;	
	}
	for(int i=1;i<=n*n;i++)
	{
		if(book[i]) continue;
		book[i]=1;
		a[x][y]=i;
		if(y==n) dfs(x+1,1);
		else dfs(x,y+1);
		book[i]=0;
	}
}

int main()
{
	n=4;
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}

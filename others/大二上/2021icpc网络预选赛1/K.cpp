#include <bits/stdc++.h>
using namespace std;

const int N=1e5+100;
int T,num[N];
vector <int> map1[N];

int main()
{
	cin>>T;
	int TT=T;
	while(TT--)
	{
		printf("Case #%d: \n",T-TT);
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++) { map1[i].clear();map1[i].push_back(0); }
		for(int i=1;i<=n;i++)
		{
			cin>>num[i];
			for(int j=1;j<=num[i];j++)
			{
				int tt;
				cin>>tt;
				map1[i].push_back(tt);
			}
		}
		while(m--)
		{
			int s,l;
			cin>>s>>l;
			int now=s,flag=1;
			while(l--)
			{
				int t;
				cin>>t;
				if(num[now]<t) flag=0;
				else if(flag)
				{
					now=map1[now][t];	
				}
			}
			if(flag) printf("%d",now);
			else printf("Packet Loss");
			if(TT==0&&m==0) ;
			else printf("\n");
		}
	}
	return 0;
}

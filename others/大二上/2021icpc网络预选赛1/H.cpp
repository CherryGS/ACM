#include <bits/stdc++.h>
using namespace std;

const int N=21100;
//const int pls=1e9;
int a[N],b[N],book1[N],book2[N];
int n,m,L;
vector <int> map1[N],map2[N],ans1,ans2;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		double t1,t2,t3;
		cin>>t1>>t2>>t3;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
//		b[i]+=pls;
		int tt,t1,t2,t3;
		cin>>tt;
		if(tt==102)
		{
			cin>>t1>>t2;
//			t1+=pls;t2+=pls;
			map1[t1].push_back(t2);
			map1[t2].push_back(t1);
			map2[t1].push_back(b[i]);
			map2[t2].push_back(b[i]);
		}
		if(tt==203)
		{
			cin>>t1>>t2>>t3;
//			t1+=pls,t2+=pls,t3+=pls;
			map1[t1].push_back(t2);
			map1[t1].push_back(t3);
			map1[t2].push_back(t1);
			map1[t2].push_back(t3);
			map1[t3].push_back(t1);
			map1[t3].push_back(t2);
			map2[t1].push_back(b[i]);
			map2[t2].push_back(b[i]);
			map2[t3].push_back(b[i]);
		}
	}
	cin>>L;
	for(int kk=1;kk<=L;kk++)
	{
		ans1.clear();
		ans2.clear();
		memset(book1,0,sizeof(book1));
		memset(book2,0,sizeof(book2));
		int x;
		cin>>x;
//		x+=pls;
		for(int i=0;i<map1[x].size();i++)
		{
			int now=map1[x][i];
			if(!book1[now])
			{
				book1[now]=1;
				ans1.push_back(now);	
			}
		}
		for(int i=0;i<map2[x].size();i++)
		{
			int now=map2[x][i];
			if(!book2[now])
			{
				book2[now]=1;
				ans2.push_back(now);
			}
		}
		int size1=ans1.size();int size2=ans2.size();
		sort(ans1.begin(),ans1.end());
		sort(ans2.begin(),ans2.end());
		printf("%d\n",x);
		printf("[");
		
		for(int i=0;i<size1;i++)
		{
			printf("%d",ans1[i]);
			if(i!=size1-1) printf(",");
		}
		printf("]\n");
		printf("[");
		
		for(int i=0;i<size2;i++)
		{
			printf("%d",ans2[i]);
			if(i!=size2-1) printf(",");	
		}
		printf("]");
		if(kk!=L) printf("\n");
	}
	return 0;
}

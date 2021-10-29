#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef __int128_t lll;

int T;
ll tt,cnt;
lll n;

int main()
{
	
	cin>>T;
	for(int i=1; i<=1e6; i++) {
		
	}
	while(T--)
	{
		cnt=0;
		cin>>tt;
		n=tt;
		for(lll t=2;t*t*t<=n&&t<=1e6;t++)
		{
			lll x=t,y=t*t*t,q=t*t;
			if(t<=1e4)
			{
				while(y<=n)
				{
					cnt++;
					lll Y=y*q-x,X=y;
					x=X,y=Y;
				}
			}
			else cnt++;
		}
		cnt++;
		cout<<cnt<<endl;
	}
	return 0;	
}
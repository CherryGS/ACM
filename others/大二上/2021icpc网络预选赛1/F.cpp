#include <bits/stdc++.h>
using namespace std;

double a,b,R,ans;
int T;

int main()
{
	cin>>T;
	int t=1;
	while(t<=T)
	{
		cin>>a>>b>>R;
		if(R>=b) ans=max(0.0,2*a-R);
		else ans=sqrt(a*a+(b-R)*(b-R))*2-R;
		printf("Case #%d: %.2lf",t,ans);
		if(t!=T) printf("\n");
		t++;	
	}
	return 0;	
}

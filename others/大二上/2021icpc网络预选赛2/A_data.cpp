#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("A.in","w",stdout);
	int n,a[1010];
	n=1000;
	srand(time(0));
	for(int i=1;i<=n;i++) a[i]=rand();
	printf("1\n");
	printf("%d 3\n",n);
	random_shuffle(a+1,a+1+n);
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;	
}

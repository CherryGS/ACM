#include <bits/stdc++.h>
using namespace std;

const int N=1005;
vector <int> ans;
int cnt,T,n,k;
int a[N*2],b[N];

void init()
{
    ans.clear();
}

void print()
{
    int now=0,siz=ans.size();
    printf("%d\n",cnt);
    while(now<siz)
    {
        printf("%d\n",ans[now]);
        if(ans[now]==2)
        {
            printf("%d %d %d\n",ans[now+1],ans[now+2],ans[now+3]);
            printf("2 1\n");
            now+=4;
        }
        else
        {
            printf("%d %d %d %d\n",ans[now+1],ans[now+2],ans[now+3],ans[now+4]);
            printf("1 3 2\n");
            now+=5;
        }
    }
}

struct stu
{
	int num,pos;	
}c[N];

bool cmp1(stu t1,stu t2)
{
	return t1.num<t2.num;	
}

bool cmp2(stu t1,stu t2)
{
	return t1.pos<t2.pos;	
}

int main()
{
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(k==1)
        {
            bool flag=1;
            for(int i=2;i<=n;i++)
            {
                if(a[i]>=a[i-1]) continue;
                flag=0;
                break;
            }
            if(!flag)
            {
                printf("-2\n");
            }
			else printf("0\n");
        }
        else if(k==2)
        {
            cnt=0;
            for(int i=2;i<=n;i++)
            {
            	if(a[i]>=a[i-1]) continue;
            	cnt++;
            	break;
            }
            if(cnt==0)
            {
                printf("0\n");                
            }
            else
            {
            	bool FLAG=0;
            	for(int i=n+1;i<=2*n;i++) a[i]=a[i-n];
            	for(int i=2;i<=n;i++)
            	{
            		bool flag=1;
            		for(int j=i+1;j<=i+n-1;j++)
					{
						if(a[j]>=a[j-1]) continue;
						flag=0;
						break;
					}
					if(flag)
					{
						FLAG=1;
						printf("1\n");
						printf("2\n");
						printf("0 %d %d\n",i-1,n);
						printf("2 1\n");
						break;
					}
            	}
            	if(!FLAG) printf("-2\n");
            }
        }
        else
        {
			for(int i=1;i<=n;i++) { c[i].num=a[i];c[i].pos=i; }
        	sort(c+1,c+1+n,cmp1);
     	   	for(int i=1;i<=n;i++) c[i].num=i;
       	 	sort(c+1,c+1+n,cmp2);
       	 	for(int i=1;i<=n;i++) a[i]=c[i].num;
            init();
            cnt=0;
			int flag;
            for(int now=1;now<=n;now++)
            {
                for(int i=1;i<=n;i++)
                {
                    if(a[i]==now) { flag=i;break; }
                }
                if(flag==now) continue;
                cnt++;
                if(now==1)
                {
                    ans.push_back(2);
                    ans.push_back(0);
                    ans.push_back(flag-1);
                    ans.push_back(n);
                    for(int i=flag;i<=n;i++) b[i-flag+1]=a[i];
                    for(int i=1;i<=flag-1;i++) b[i+n-flag+1]=a[i];
                    for(int i=1;i<=n;i++) a[i]=b[i];
                }
                else
                {
                    ans.push_back(3);
                    ans.push_back(0);
                    ans.push_back(now-1);
                    ans.push_back(flag-1);
                    ans.push_back(n);
                    for(int i=now;i<=flag-1;i++) b[i+n-flag+1]=a[i];
                    for(int i=flag;i<=n;i++) b[i-flag+now]=a[i];
                    for(int i=now;i<=n;i++) a[i]=b[i];
                }
            }
            print();
        }
    }
    return 0;
}

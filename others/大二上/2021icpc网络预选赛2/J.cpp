#include <bits/stdc++.h>
using namespace std;

const int N=510;
int nxt[10][2]={{0,0},{1,0},{-1,0},{0,1},{0,-1}};
struct stu
{
    int x,y,h;
    double water;
}a[N*N];
int h[N][N];
double water[N][N];
int n,cnt;
double m;

bool cmp(stu t1,stu t2)
{
    return t1.h>t2.h;
}

int main()
{
    scanf("%d%lf",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&h[i][j]);
            a[++cnt].x=i,a[cnt].y=j,a[cnt].h=h[i][j];
            water[i][j]=m;
        }
    }
    sort(a+1,a+1+cnt,cmp);
    for(int i=1;i<=cnt;i++)
    {
        if(a[i].h==0) break;
        int nxtx,nxty,x=a[i].x,y=a[i].y,count1=0;
        a[i].water+=water[x][y];
        for(int j=1;j<=4;j++)
        {
            nxtx=a[i].x+nxt[j][0],nxty=a[i].y+nxt[j][1];
            if(nxtx>n||nxtx<1||nxty>n||nxty<1) continue;
            if(h[nxtx][nxty]>=h[x][y]) continue;
            count1++;
        }
        if(count1==0) continue;
        for(int j=1;j<=4;j++)
        {
            nxtx=a[i].x+nxt[j][0],nxty=a[i].y+nxt[j][1];
            if(nxtx>n||nxtx<1||nxty>n||nxty<1) continue;
            if(h[nxtx][nxty]>=h[x][y]) continue;
            water[nxtx][nxty]+=a[i].water/count1;
        }
    }    
	for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(h[i][j]!=0) printf("0 ");
            else
            {
                printf("%.8lf ",water[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}

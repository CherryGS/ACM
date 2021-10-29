#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
int a[100100];
int fr[1001][1001];
int to[1001][1001];
int st[1001][1001];
int block_siz, block_num;

inline int read() {
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main() {
    n = read(), m = read();
    block_siz = sqrt(n);
    block_num = n/block_siz;
    for(int i=1; i<=n; i++) a[i] = read();
    // 处理每个数在块内的前缀最大值
    for(int i=0; i<=n; i++) {
        int r = i/block_siz;
        if(r == (i-1)/block_siz) fr[r][i-r*block_siz] = max(a[i], fr[r][i-r*block_siz-1]);
        else fr[r][i-r*block_siz] = a[i];
    }
    // 处理每个数在块内的后缀最大值
    for(int i=n; i>=0; i--) {
        int r = i/block_siz;
        if(r == (i+1)/block_siz) to[r][i-r*block_siz] = max(a[i], to[r][i-r*block_siz+1]);
        else to[r][i-r*block_siz] = a[i];
    }
    // 处理连续块之间的最大值
    for(int i=0; i<=block_num; i++)
        for(int j=0; j<=i; j++) {
            if(j) st[i-j][i] = max(to[i-j][0], st[i-j+1][i]);
            else st[i-j][i] = to[i][0];
        }

    int l, r;
    for(int i=1; i<=m; i++) {
        l = read(), r = read();
        int s1 = l/block_siz, s2 = r/block_siz;
        if(s1 != s2) {
            // 对于不在同一块内的数，可以用左边界后缀，右边界前缀，两边界之内所有整块三者取max
            printf("%d\n", max(st[s1+1][s2-1], max(to[s1][l-s1*block_siz], fr[s2][r-s2*block_siz])));
        } else {
            // 对于在同一块内的数，暴力
            int mx = 0;
            for(int i=l; i<=r; i++) mx = max(mx, a[i]);
            printf("%d\n", mx);
        }
    }
    return 0;
}
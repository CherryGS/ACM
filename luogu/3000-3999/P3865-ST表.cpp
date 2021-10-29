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

inline int read() {
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int n, m;
int st[18][100100];
int to[100100];

void debug() {
    for(int i=1; i<=n; i++) {
        cout << "---" << i << endl;
        for(int j=0; j<=18; j++)
            cout << st[i][j] << '-';
        cout << endl;
    }
}

void init() {
    for(int i=2; i<=100000; i++)
        to[i] = to[i/2]+1;
    // for(int i=1; i<=100000; i++)
    //     cout << i << ' ' << to[i] << endl;
}

int main() {
    init();
    n = read(); m = read();
    int l, r;
    for(int i=1; i<=n; i++) st[0][i] = read();
    for(int j=1; (1<<j) <= n; j++) {
        int k = (1<<(j-1));
        for(int i=1; i<=n; i++) {
            if(i+k <= n) st[j][i] = max(st[j-1][i], st[j-1][i+k]);
        }
    }

    // debug();

    for(int i=1; i<=m; i++) {
        l = read(); r = read();
        int s = to[r-l+1];
        printf("%d\n", max(st[s][l], st[s][r-(1<<s)+1]));
    }
    return 0;
}
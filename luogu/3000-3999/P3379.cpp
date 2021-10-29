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

int n, m, s;
int h[500100], nx[1001000], to[1001000], cnt;
int fa[20][500100];
int dep[500100];
int t[500100];

void add(cint f, cint t) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
}

void dfs(cint loc, cint la) {
    dep[loc] = dep[la] + 1;
    fa[0][loc] = la;
    for(int i=h[loc]; i; i=nx[i])
        if(to[i] != la) dfs(to[i], loc);
}

inline int read() {
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int sol(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    while(dep[x] > dep[y]) {
        x = fa[t[dep[x]-dep[y]]][x];
    }
    if(x == y) return x;
    for(int i=19; i>=0; i--)
        if(fa[i][x] != fa[i][y]) {
            x = fa[i][x];
            y = fa[i][y];
        }
    return fa[0][x];
}

void init() {
    for(int i=2; i<=500000; i++)
        t[i] = t[i/2] + 1;
}

void debug() {
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=19; j++) {
            cout << fa[j][i] << ' ';
        }
        cout << endl;
    }
}

int main() {
    n = read(), m = read(), s = read();
    int u, v;
    init();
    for(int i=1; i<n; i++) {
        u = read(), v = read();
        add(u, v);
        add(v, u);
    }
    dfs(s, s);
    for(int i=1; (1<<i) < n; i++) {
        for(int j=1; j<=n; j++) {
            fa[i][j] = fa[i-1][fa[i-1][j]];
        }
    }
    // debug();
    int p1, p2;
    for(int i=1; i<=m; i++) {
        p1 = read(), p2 = read();
        printf("%d\n", sol(p1, p2));
    }
    return 0;
}
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

int n;
int h[200200], nx[400400], to[400400], cnt;
int fa[200200];
int p[2], mx_dis, sum;
int des[200200];
int ans[200200];

void add(cint f, cint t) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
}

void dfs(cint loc, cint fa, cint st, cint dis) {
    if(dis > mx_dis) {
        p[st] = loc;
        mx_dis = dis;
    }
    for(int i=h[loc]; i; i=nx[i])
        if(to[i] != fa) {
            dfs(to[i], loc, st, dis+1);
        }
}

void dfs1(cint loc, cint fa1) {
    fa[loc] = fa1;
    for(int i=h[loc]; i; i=nx[i])
        if(to[i] != fa1) dfs1(to[i], loc);
}

void dfs2(cint loc) {
    if(fa[loc] == loc) return;
    des[fa[loc]] = loc;
    dfs2(fa[loc]);
}

void sol(cint loc, cint fa) {
    ans[loc] = ++sum;
    for(int i=h[loc]; i; i=nx[i])
        if(to[i] != fa && to[i] != des[loc])
            sol(to[i], loc);
    if(des[loc])
    sol(des[loc], loc);
    ++sum;
}

int main() {
    cin >> n;
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    mx_dis = 0;
    dfs(1, 1, 0, 1);
    mx_dis = 0;
    dfs(p[0], p[0], 1, 1);
    dfs1(p[0], p[0]);
    dfs2(p[1]);

    sol(p[0], p[0]);
    for(int i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
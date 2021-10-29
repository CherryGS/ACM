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
int h[202], nx[404], to[404], cnt;
int dfn[202], num, dep[202], end_dfn[202];
ll dp[202][202];
ll ans = 0;
int fa[202][202];
int t[500100];

void add(cint f, cint t) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
}

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = (ans*bs) % mod;
        bs = (bs*bs) % mod;
        x >>= 1;
    }
    return ans;
}

void dfs(cint loc, cint fat) {
    dfn[loc] = ++num;
    dep[loc] = dep[fat] + 1;
    fa[0][loc] = fat;
    for(int i=h[loc]; i; i=nx[i])
        if(to[i] != fat) {
            dfs(to[i], loc);
        }
    end_dfn[loc] = num;
}

void init() {
    for(int i=2; i<=500; i++)
        t[i] = t[i/2] + 1;
    for(int i=0; i<=200; i++) dp[i][0] = 1;
    for(int i=1; i<=200; i++)
        for(int j=1; j<=200; j++)
            dp[j][i] = (dp[j][i-1]*dp[j-1][i]*ksm(2, mod-2)) % mod;
}

int get_fa(int x, int y) {
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

void sol(cint s) {
    num = 0;
    dep[s] = -1;
    dfs(s, s);
    for(int i=1; (1<<i) < n; i++) {
        for(int j=1; j<=n; j++) {
            fa[i][j] = fa[i-1][fa[i-1][j]];
        }
    }
    ll pre = 0;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            // ai < aj
            // loc_i > loc_j
            if(dfn[j] < dfn[i] || dfn[j] > end_dfn[i]) {
                int r = dep[get_fa(i, j)];
                int s1 = dep[i] - r;
                int s2 = dep[j] - r;
                // cout << s1 << "---" << s2 << "---" << i << "---" << j << "---" << s << " " << (C(s1-1, s1+s2-1)*ksm(C(s1, s1+s2), mod-2))%mod << endl;
                ans = (ans + dp[s1][s2]) % mod;
            }
        }
    }
    // ans = (ans + pre*ksm(n, mod-2)) % mod;
}

int main() {
    init();
    cin >> n;
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for(int i=1; i<=n; i++) {
        sol(i);
    }
    // cout << ans << endl;
    cout << (ans*ksm(n, mod-2)) % mod << endl;
    return 0;
}
/*
4
1 2
2 3
1 4
*/
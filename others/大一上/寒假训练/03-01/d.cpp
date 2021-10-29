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

ll n;
ll max_, nm_;
int nx[1000100], to[1000100], he[100010], cnt;
int deg[1000100];

void add(cint f, cint t) {
    nx[++cnt] = he[f];
    he[f] = cnt;
    to[cnt] = t; 
}

ll ksm(ll m, int c) {
    ll ans = 1;
    while(c) {
        if(c&1) ans = (ans*m) % mod;
        c >>= 1;
        m = (m*m) % mod;
    }
    return ans;
}

ll fm(cint x, cint p) {
    return ksm(x,p-2);
}

void dfs(cint loc, cint fa) {
    deg[loc] = deg[fa] + 1;
    if(deg[loc] > max_) {
        max_ = deg[loc];
        nm_ = 1;
    } else if(deg[loc] == max_) ++ nm_;
    for(int i = he[loc]; i; i = nx[i])
        if(to[i] != fa) {
            dfs(to[i], loc);
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1, 1);
    cout << max_ << ' ' << nm_ << endl;
    cout << (nm_*fm(ksm(2,max_), mod)) % mod;
    return 0;
}
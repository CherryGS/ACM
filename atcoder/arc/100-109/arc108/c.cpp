#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int he[100100], to[400100], w[400100], nx[400100], cnt;

void add(cint f, cint t ,cint co) {
    nx[++cnt] = he[f];
    he[f] = cnt;
    to[cnt] = t;
    w[cnt] = co;
}

int n, m;
int bcj[100100];
struct stu {
    int u, v, c;
    void init() {
        cin >> u >> v >> c;
    }
} a[200200];

int ans[200200], num;
bool mp[200200];

int fd(cint x) {
    return bcj[x] == x? x : bcj[x] = fd(bcj[x]);
}

void upd(const stu&x) {
    if(fd(x.u) != fd(x.v)) {
        bcj[fd(x.u)] = fd(x.v);
        add(x.u, x.v, x.c);
        add(x.v, x.u, x.c);
    }
}

void dfs(cint loc, bool k, int co) {
    if(k) {
        co += 1;
        if(co > n) co = 1;
    }
    ++num;
    ans[loc] = co;
    mp[loc]=1;
    for(int i=he[loc]; i; i=nx[i])
        if(to[i] != loc && !mp[to[i]]) dfs(to[i], (co==w[i]), w[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<=m; i++) a[i].init();
    for(int i=1; i<=n; i++) bcj[i] = i;
    for(int i=1; i<=m; i++) upd(a[i]);
    dfs(1, 1, 0);
    if(num != n) cout << "No" << endl;
    else for(int i=1; i<=n; i++) cout << ans[i] << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
int h[10010], nx[20020], to[20020], w[20020], cnt;
int son[10010];
bool vis[10010];
bool ans[10010];
int k[10010];
int id, snode, mx;
unordered_set<int> e;

void add(cint f, cint t, cint co) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
    w[cnt] = co;
}

int gsiz(cint loc, cint fa) {
    int sum = 1;
    for(int i=h[loc]; i; i=nx[i])
        if(to[i] != fa && !vis[to[i]]) {
            // cout << loc << " --- " << fa << " --- " << sum << ' ' << endl;
            sum += gsiz(to[i], loc);
        }
    return sum;
}

void gp(cint loc, cint fa) {
    int pre = 0;
    son[loc] = 1;
    for(int i=h[loc]; i; i=nx[i])
        if(to[i] != fa && !vis[to[i]]) {
            gp(to[i], loc);
            pre = max(pre, son[to[i]]);
            son[loc] += son[to[i]];
            if(id) return;
        }
    pre = max(pre, snode - son[loc]);
    if(pre <= snode/2) {
        id = loc;
        return;
    }
}

void check(cint loc, cint fa, cint co) {
    if(co > mx) return;
    for(int i=1; i<=m; i++) {
        if(ans[i]) continue;
        if(e.find(k[i]-co) != e.end()) {
            ans[i] = 1;
        }
    }
    for(int i=h[loc]; i; i=nx[i])
        if(to[i] != fa && !vis[to[i]]) {
            check(to[i], loc, co+w[i]);
        }
}

void update(cint loc, cint fa, cint co) {
    e.insert(co);
    for(int i=h[loc]; i; i=nx[i]) {
        if(to[i] != fa && !vis[to[i]]) {
            update(to[i], loc, co+w[i]);
        }
    }
}

void sol(cint loc) {
    // cout << loc << ' ' << id << ' ' << vis[loc] << endl;
    vis[loc] = 1;
    e.clear();
    e.insert(0);
    for(int i=h[loc]; i; i=nx[i]) {
        if(!vis[to[i]]) {
            check(to[i], loc, w[i]);
            update(to[i], loc, w[i]);
        }
    }
    for(int i=h[loc]; i; i=nx[i]) {
        if(!vis[to[i]]) {
            snode = gsiz(to[i], loc);
            id = 0;
            gp(to[i], loc);
            // cout << to[i] << " ---- " << snode << " --- " << loc << " ---- " << id << endl;
            sol(id);
        }
    }
    if(id == loc) return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("1.in", "r", stdin);
    cin >> n >> m;
    int u, v, co;
    for(int i=1; i<n; i++) {
        cin >> u >> v >> co;
        add(u, v, co);
        add(v, u, co);
    }
    int tmp;
    for(int i=1; i<=m; i++) cin >> k[i], mx = max(mx, k[i]);
    snode = n;
    gp(1, 1);
    sol(id);
    for(int i=1; i<=m; i++) {
        cout << (ans[i] == 1 ? "AYE" : "NAY") << '\n';
    }
    return 0;
}
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

int h[10010], nx[20020], to[20020], w[20020], cnt_;
int bson[10010];
int son[10010];
unordered_set<int> e;

int k[101];
bool ans[101];


void add(cint f, cint t, cint co) {
    nx[++cnt_] = h[f];
    h[f] = cnt_;
    to[cnt_] = t;
    w[cnt_] = co;
}

void fd_son(cint loc, cint fa) {
    son[loc] = 1;
    for(int i=h[loc]; i; i=nx[i])
        if(to[i] != fa) {
            fd_son(to[i], loc);
            son[loc] += son[to[i]];
            if(son[to[i]] > son[bson[loc]]) bson[loc] = to[i];
        }
}

void check(cint loc, cint fa, cint co) {
    if(co > 1e7) return;
    for(int i=1; i<=m; i++) {
        if(ans[i]) continue;
        if(e.find(k[i]-co) != e.end()) ans[i] = 1;
    }
    for(int i=h[loc]; i; i=nx[i]) {
        if(to[i] != fa) {
            check(to[i], loc, w[i] + co);
        }
    }
}

void update(cint loc, cint fa, cint co) {
    if(co > 1e7) return;
    e.insert(co);
    for(int i=h[loc]; i; i=nx[i]) {
        if(to[i] != fa) {
            update(to[i], loc, w[i] + co);
        }
    }
}

void solve(cint loc, cint fa) {
    for(int i=h[loc]; i; i=nx[i]) {
        if(to[i] != fa && to[i] != bson[loc]) {
            solve(to[i], loc);
            e.clear();
        }
    }
    if(bson[loc]) {
        solve(bson[loc], loc);
    }
    for(int i=h[loc]; i; i=nx[i]) {
        if(to[i] != fa && to[i] != bson[loc]) {
            check(to[i], loc, w[i]);
            update(to[i], loc, w[i]);
        }
    }
}

int main() {
    cin >> n >> m;
    int u, v, w;
    for(int i=1; i<n; i++) {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    for(int i=1; i<=m; i++) cin >> k[i];
    fd_son(1, 1);
    solve(1, 1);
    for(int i=1; i<=m; i++) {
        cout << (ans[i] == 1 ? "AYE" : "NAY") << '\n';
    }
    return 0;
}
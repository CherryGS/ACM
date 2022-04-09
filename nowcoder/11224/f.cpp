#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef const ll& cll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
vector<int> to[200200];
int m, k;
int up[19][200200];
int dep[200200];
int q[200200];
bool flag[200200];
bool vis[200200];
ll ans;

void dfs(cint u, cint fa) {
    dep[u] = dep[fa] + 1;
    for(int &v: to[u]) {
        if(v != fa) {
            up[0][v] = u;
            dfs(v, u);
        }
    }
}

int lca(int x, int y) {
    if(x == 0) { return y; }
    if(x == y) { return x; }
    if(dep[x] > dep[y]) { swap(x, y); }
    for(int i=18; i>=0; i--) { if(dep[up[i][y]] >= dep[x]) { y = up[i][y]; } }
    if(x == y) { return x; }
    for(int i=18; i>=0; i--) { if(up[i][x] != up[i][y]) { x = up[i][x]; y = up[i][y]; } }
    return up[0][x];
}

void del(cint u, cint fa) {
    vis[u] = 1;
    for(int &v: to[u]) {
        if(v != fa) {
            del(v, u);
        }
    }
}

void sol(cint u, cint fa, cint step) {
    if(flag[u]) { ans += step; }
    for(int &v: to[u]) {
        if(v != fa && v != k) {
            sol(v, u, step+1);
        }
    }
}

void solve(cint T) {
    cin >> n;
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    up[0][1] = 1;
    dfs(1, 1);
    for(int j=1; j<19; j++) {
        for(int i=1; i<=n; i++) {
            up[j][i] = up[j-1][up[j-1][i]];
        }
    }
    cin >> m >> k;
    del(k, up[0][k]);
    for(int i=1; i<=m; i++) { cin >> q[i]; flag[q[i]] = 1; }
    int t = q[1], tt = 0;
    for(int i=1; i<=m; i++) { t = lca(t, q[i]); }
    for(int i=1; i<=m; i++) { if(!vis[q[i]]) { tt = lca(tt, q[i]); } }
    ll now = inf_ll;
    if(tt == 0) {
        if(t == k) { sol(t, up[0][t], 0); }
        else { sol(t, up[0][t], 1); }
    }
    else {
        
    }
    cout << now << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
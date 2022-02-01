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

int n, f;
vector<int> g[100100];
int fa[20][100100];
int dep[100100];

struct edge {
    int u, v, x, d;
    bool operator < (const edge&a) const {
        return x > a.x;
    }
};

void dfs(cint u) {
    for(int v: g[u]) {
        if(dep[v] == 0) {
            dep[v] = dep[u] + 1;
            fa[0][v] = u;
            dfs(v);
        }
    }
}

pii lca(int x, int y) {
    int sum = 0;
    if(dep[x] < dep[y]) swap(x, y);
    for(int i=19; i>=0; i--) {
        if(dep[fa[i][x]] >= dep[y]) {
            x = fa[i][x];
            sum += (1<<i);
        }
    }
    if(x == y) return {x, sum};
    for(int i=19; i>=0; i--) {
        if(fa[i][x] != fa[i][y]) {
            x = fa[i][x];
            y = fa[i][y];
            sum += (1<<i);
        }
    }
    return {fa[0][x], sum + 1};
}

void solve(cint T) {
    cin >> n >> f;
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dep[1] = 1;
    fa[0][1] = 1;
    dfs(1);
    for(int i=1; i<20; i++)
        for(int j=1; j<=n; j++) {
            fa[i][j] = fa[i-1][fa[i-1][j]];
        }
    vector<edge> q;
    for(int i=1; i<=f; i++) {
        cin >> u >> v;
        if(dep[u] < dep[v]) swap(u, v);
        auto k = lca(u, v);
        q.push_back({u, v, k.second, k.first});
    }
    sort(q.begin(), q.end());
    bool flag = 1;
    for(int i=0; i<q.size()-1; i++) {
        auto s1 = q[i];
        auto s2 = q[i+1];
        auto k = lca(s1.u, s2.u);
        if(s1.d == s1.v) {
            if(lca(s1.u, s2.u).first == s2.u && lca(s1.v, s2.v).first == s1.v) flag = 1;
            else flag = 0;
        } else {
            if(lca(s1.u, s2.u).first == s2.u && lca(s1.v, s2.v).first == s2.v) flag = 1;
            else if(lca(s1.u, s2.v).first == s2.v && lca(s1.v, s2.u).first == s2.u) flag = 1;
            else flag = 0;
        }
        if(!flag) break;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
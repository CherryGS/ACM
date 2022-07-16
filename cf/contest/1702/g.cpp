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

int n, q;
int cnt;
int dfn[200200];
int edfn[200200];
int dep[200200];
int fa[26][200200];
vector<int> to[200200];

void init_lca() {
    for(int i=1; i<26; i++) {
        for(int j=1; j<=n; j++) {
            fa[i][j] = fa[i-1][fa[i-1][j]];
        }
    }
}

int lca(int x, int y) {
    if(dep[x] < dep[y]) { swap(x, y); }
    for(int i=25; i>=0; i--) { if(dep[fa[i][x]] >= dep[y]) { x = fa[i][x]; } }
    if(x == y) { return x; }
    for(int i=25; i>=0; i--) {
        if(fa[i][x] != fa[i][y]) {
            x = fa[i][x];
            y = fa[i][y];
        }
    }
    return fa[0][x];
}

void dfs(int u, int fa1) {
    fa[0][u] = fa1;
    dep[u] = dep[fa1] + 1;
    dfn[u] = ++cnt;
    for(int &v : to[u]) {
        if(v != fa1) {
            dfs(v, u);
        }
    }
    edfn[u] = cnt;
}

bool cmp(cint x, cint y) {
    return dep[x] > dep[y];
}

void solve(cint T) {
    cin >> n;
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1, 1);
    init_lca();
    cin >> q;
    for(int i=1; i<=q; i++) {
        int k, tmp;
        vector<int> qe;
        cin >> k;
        for(int j=1; j<=k; j++) {
            cin >> tmp;
            qe.push_back(tmp);
        }
        bool flag = false;
        sort(qe.begin(), qe.end(), cmp);
        int tg = qe[0];
        for(int j=1; j<qe.size(); j++) {
            tg = lca(qe[j], tg);
        }
        vector<int> qq;
        for(int j=1; j<qe.size(); j++) {
            int fa = lca(qe[0], qe[j]);
            if(fa == tg) {
                qq.push_back(qe[j]);
            }
            else if(fa != qe[j]) {
                flag = true;
                break;
            }
        }
        sort(qq.begin(), qq.end(), cmp);
        for(int j=1; j<qq.size(); j++) {
            int fa = lca(qq[0], qq[j]);
            if(fa != qq[j]) {
                flag = true;
                break;
            }
        }
        if(flag == true) { cout << "NO" << '\n'; }
        else { cout << "YES" << '\n'; }
    }
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
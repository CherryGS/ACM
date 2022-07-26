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

int n, k;

struct Play {
    int dep[100100];
    int f[26][100100];
    vector<int> to[100100];
    void add(cint u, int v) {
        to[u].push_back(v);
        to[v].push_back(u);
    }
    void dfs(cint u, cint fa) {
        dep[u] = dep[fa] + 1;
        f[0][u] = fa;
        for(int &v: to[u]) {
            if(v != fa) {
                dfs(v, u);
            }
        }
    }
    void init_lca() {
        dfs(1, 1);
        for(int i=1; i<26; i++) {
            for(int j=1; j<=n; j++) {
                f[i][j] = f[i-1][f[i-1][j]];
            }
        }
    }
    int lca(int x, int y) {
        if(x == 0 || y == 0) { return x == 0 ? y : x; }
        if(dep[x] < dep[y]) { swap(x, y); }
        for(int i=25; i>=0; i--) { if(dep[f[i][x]] >= dep[y]) { x = f[i][x]; } }
        if(x == y) { return x; }
        for(int i=25; i>=0; i--) { if(dep[f[i][x]] != dep[f[i][y]]) { x = f[i][x]; y = f[i][y]; } }
        return f[0][x];
    }
} A, B;

int x[100100];
int a[100100];
int b[100100];
int v[2][100100];
int u[2][100100];

void solve(cint T) {
    cin >> n >> k;
    for(int i=1; i<=k; i++) { cin >> x[i]; }
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    for(int i=1; i<n; i++) { int t; cin >> t; A.add(i+1, t); }
    for(int i=1; i<=n; i++) { cin >> b[i]; }
    for(int i=1; i<n; i++) { int t; cin >> t; B.add(i+1, t); }
    A.init_lca(); B.init_lca();
    for(int i=1; i<=n; i++) {
        if(a[i] < n)
        v[0][a[i]] = A.lca(v[0][a[i]], x[i]);
        v[1][i] = B.lca(v[1][i-1], x[i]);
    }
    for(int i=n; i>=1; i--) {
        u[0][i] = A.lca(u[0][i+1], x[i]);
        u[1][i] = B.lca(u[1][i+1], x[i]);
    }
    int ans = 0;
    for(int i=1; i<=k; i++) {
        // cout << A.lca(v[0][i-1], u[0][i+1]) << ' ' << v[0][i-1] << ' ' << u[0][i+1] << endl;
        if(a[A.lca(v[0][i-1], u[0][i+1])] > b[B.lca(v[1][i-1], u[1][i+1])]) { ++ans; }
    }
    cout << ans << '\n';
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
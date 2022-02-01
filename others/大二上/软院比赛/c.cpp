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
const int N = 100010;

int n, m;
vector<int> g[100100];
vector<int> dg[100100];
int vis[100100];
int col[100100];
set<pii> e;

void dfs1(cint u) {
    vis[u] = 1;
    for(int v: g[u])
        if(!vis[v]) {
            e.erase({u,v});
            dfs1(v);
        }
}

void dfs2(cint u) {
    col[u] = 1;
    for(int v: dg[u])
        if(!col[v]) {
            e.erase({v, u});
            dfs2(v);
        }
}

void solve(cint T) {
    e.clear();
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        g[i].clear();
        dg[i].clear();
        vis[i] = 0;
        col[i] = 0;
    }
    int x, y;
    for(int i=1; i<=m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        dg[y].push_back(x);
        e.insert({x, y});
    }
    e.erase({x, y});
    dfs1(y);
    dfs2(x);
    int r = m - 2*n;
    auto k = e.begin();
    for(int i=1; i<=r; i++) {
        cout << k->first << ' ' << k->second << endl;
        k++;
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
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

const int bs=1000000;
int n;
int k, p;
int s, t;
int mx;
int dep[1000100];
bool vis[3000100];
ll dis[3000100];
int h[3000100], nx[4000200], to[4000200], w[4000200], cnt;

void add(int f, int t, int co) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
    w[cnt] = co;
}

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    mx = max(mx, dep[u]);
    for(int i=h[u]; i; i=nx[i]) {
        int v = to[i];
        if(v != fa) { dfs(v, u); }
    }
}

typedef pair<ll, int> pli;

void dij() {
    memset(dis, 0x7f, sizeof dis);
    memset(vis, 0, sizeof vis);
    priority_queue<pli, vector<pli>, greater<pli>> q;
    dis[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        // if(q.size() > 1000000) { return; }
        int u = q.top().second;
        q.pop();
        if(u == t) { return; }
        if(vis[u]) { continue; }
        vis[u] = 1;
        for(int i=h[u]; i; i=nx[i]) {
            int v = to[i];
            if(dis[v] > dis[u] + w[i]) {
                dis[v] = dis[u] + w[i];
                q.push({dis[v], v});
            }
        }
    }
}

void solve(cint T) {
    mx = cnt = 0;
    cin >> n;
    memset(h, 0, sizeof h);
    for(int i=1; i<n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    cin >> k >> p;
    cin >> s >> t;
    dfs(1, 0);
    for(int i=1; i<=n; i++) {
        add(bs+dep[i], i, 0);
        add(bs*2+dep[i], i, 0);
        if(dep[i]-k >= 1) { add(i, bs+dep[i]-k, p); }
        if(dep[i]+k <= mx) { add(i, bs*2+dep[i]+k, p); }
    }
    dij();
    cout << dis[t] << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
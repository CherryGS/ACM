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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
int h[100100], nx[1000100], to[1000100], cnt;
ll w[1000100];
ll dis[100100];
ll lim[100100];
bool vis[100100];

void add(int f, int t, ll co) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
    w[cnt] = co;
}

void dij() {
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[1] = 0;
    typedef pair<ll, int> pli;
    priority_queue<pli, vector<pli>, greater<pli>> q;
    q.push({0, 1});
    while(!q.empty()) {
        auto u = q.top().second;
        q.pop();
        if(vis[u]) { continue; }
        vis[u] = 1;
        for(int i=h[u]; i; i=nx[i]) {
            int v = to[i];
            ll val = dis[u] + w[i];
            if(max(lim[v], val) < dis[v]) {
                dis[v] = max(lim[v], val);
                q.push({dis[v], v});
            }
        }
    }
}

bool solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<=n; i++) { h[i] = 0; }
    cnt = 0;
    int u, v, ww;
    for(int i=1; i<=m; i++) {
        cin >> u >> v >> ww;
        add(u, v, ww);
        add(v, u, ww);
    }
    for(int i=2; i<=n; i++) { cin >> lim[i]; }
    dij();
    cout << dis[n] << '\n';
    return true;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}
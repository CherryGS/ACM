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

int n, m;
int a, b, d;
int val[200200];
vector<int> to[200200];
bool vis[200200];
int dis[200200];

bool check() {
    if(d <= 0) { return true; }
    for(int i=1; i<=n; i++) { vis[i] = 0; }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    ll s = val[1]-d;
    q.push({-inf_int, 1});
    vis[1] = 1;
    while(!q.empty()) {
        auto k = q.top();
        q.pop();
        if(s <= k.first) { break; }
        s += d;
        if(k.second == n) { return true; }
        for(int &v: to[k.second]) {
            if(!vis[v]) {
                vis[v] = 1;
                q.push({val[v], v});
            }
        }
    }
    return false;
}

void dij() {
    for(int i=1; i<=n; i++) { dis[i] = -1; }
    for(int i=1; i<=n; i++) { vis[i] = 0; }
    dis[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    while(!q.empty()) {
        auto k = q.top().second;
        q.pop();
        if(vis[k]) { continue; }
        vis[k] = 1;
        for(int &v: to[k]) {
            if(1ll*d*dis[k]+val[1] > val[v] && (dis[k] < dis[v]-1 || dis[v] == -1)) {
                dis[v] = dis[k] + 1;
                q.push({dis[v], v});
            }
            else if(d > 0 && 1ll*d*dis[k]+val[1] <= val[v] && dis[v] == -1) {
                dis[v] = (val[v]+1-val[1]+d-1)/d + 1;
                q.push({dis[v], v});
            }
        }
    }
}

void solve(cint T) {
    cin >> n >> m >> a >> b;
    for(int i=1; i<=n; i++) { to[i].clear(); }
    for(int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    for(int i=1; i<=n; i++) { cin >> val[i]; if(i != 1) { val[i] += b; } }
    d = a - b;
    if(!check()) { cout << -1 << '\n'; }
    else { dij(); cout << dis[n] << '\n'; }
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
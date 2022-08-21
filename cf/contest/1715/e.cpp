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

int n, m, k;
ll dis[100100];
ll p[100100];
int h[100100], nx[200200], to[200200], w[200200], cnt;
bool vis[100100];
int lst;
int nh[100100];

void add(int f, int t, int co) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
    w[cnt] = co;
}

void dij() {
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    while(!q.empty()) {
        auto u = q.top().second;
        q.pop();
        if(vis[u]) { continue; }
        vis[u] = 1;
        for(int i=h[u]; i; i=nx[i]) {
            int v = to[i];
            if(dis[v] > dis[u] + w[i]) {
                dis[v] = dis[u] + w[i];
                if(!vis[v]) { q.push({dis[v], v}); }
            }
        }
    }
}

void sol() {
    cnt = lst;
    for(int i=1; i<=n; i++) { h[i] = nh[i]; }
    for(int i=1; i<=n; i++) { p[i] = dis[i]; }
    set<pair<ll,int>> e;
    for(int i=1; i<=n; i++) { e.insert({dis[i]-2ll*max(i,n-i)*i, i}); }
    for(int i=2; i<=n; i++) {
        for(auto &k: e) {
            // cout << i << ' ' << k.second << ' ' << dis[i] << ' ' << k.first << endl;
            if(k.first+1ll*i*i >= dis[i]) { break; }
            if(k.second == i) { continue; }
            dis[i] = min(dis[i], p[k.second] + 1ll*(i-k.second)*(i-k.second));
        }
    }
    for(int i=2; i<=n; i++) { add(1, i, dis[i]); }
}

void solve(cint T) {
    cin >> n >> m >> k;
    int a, b, c;
    for(int i=1; i<=m; i++) {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    lst = cnt;
    for(int i=1; i<=n; i++) { nh[i] = h[i]; }
    for(int i=1; i<=k; i++) {
        dij();
        sol();
    }
    dij();
    for(int i=1; i<=n; i++) { cout << dis[i] << ' '; }
    cout << '\n';
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
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
int s, t;
vector<int> e[200200];
bool ok[200200];
int dep[200200];
ll dp[200200];

void bfs() {
    dep[s] = 0;
    queue<int> q;
    q.push(s);
    dp[s] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v: e[u]) {
            if(v == t && ok[u]) continue;
            if(dep[v] >= dep[u] + 1 && v == t) { ok[u] = 1; }
            if(dep[v] == dep[u] + 1) { (dp[v] += dp[u]) %= mod1; }
            else if(dep[v] > dep[u] + 1) { dp[v] = dp[u]; q.push(v); dep[v] = dep[u]+1; }
        }
    }
}

void clear(bool x) {
    for(int i=1; i<=n; i++) {
        if(x) { e[i].clear(); }
        if(x) { ok[i] = 0; }
        dp[i] = 0;
        dep[i] = hf_int;
    }
}

void solve(cint T) {
    cin >> n >> m;
    cin >> s >> t;
    int u, v;
    clear(1);
    for(int i=1; i<=m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bfs();
    ll ans = dp[t];
    clear(0);
    bfs();
    ans = (ans + dp[t]) % mod1;
    cout << ans << endl;
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
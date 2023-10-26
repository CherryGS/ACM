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

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int add(ll x, const int &y) { x += y; return x >= mod ? x - mod : x; }
int sub(ll x, const int &y) { x -= y; return x >= 0 ? x : x + mod; }
int mul(ll x, const int &y) { x *= y; return x >= mod ? x % mod : x; }

int n, t, k;
int a[200200];
queue<int> q[200200];
vector<pii> to[200200];
bool vis[200200];

void push(int x) {
    for(auto &k: to[x]) {
        // cout << k.first << ' ' << k.second << endl;
        if(!vis[k.first]) {
            q[k.second].push(k.first);
        }
    }
}

void solve(cint T) {
    cin >> n >> t;
    int m, u, v;
    for(int i=1; i<=t; i++) {
        cin >> m;
        for(int j=1; j<=m; j++) {
            cin >> u >> v;
            to[u].push_back({v, i});
            to[v].push_back({u, i});
        }
    }
    cin >> k;
    push(1); vis[1] = 1;
    queue<int> r;
    for(int i=1; i<=k; i++) { cin >> a[i]; }
    for(int i=1; i<=k; i++) {
        while(!q[a[i]].empty()) {
            auto k = q[a[i]].front(); q[a[i]].pop();
            if(vis[k]) { continue; }
            vis[k] = 1;
            r.push(k);
        }
        while(!r.empty()) { auto k = r.front(); r.pop(); push(k); }
        if(vis[n] == 1) {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
